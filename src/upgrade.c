#include <stdio.h>
#include <stdlib.h>
#include "upgrade.h"


int PrintUpgradeList(Player P, ListWahana LW, HutanWahana HW) {
    /* KAMUS LOKAL */
    int i = 0;
    Wahana Target;
    /* ALGORITMA */
    Target = WahanaSebelah(P,LW);
    while (!IsKataSama(NamaW(Target),FNamaWahana(HW,i))) {
        i++;
    }
    // Menampilkan pilihan Upgrade
    printf("1 : ");
    PrintKata(FNamaWahanaLeft(HW,i));
    printf("\n");
    printf("2 : ");
    PrintKata(FNamaWahanaRight(HW,i));
    printf("\n");
}

void MaterialToStock(STOCK TabStock[3], Material TabMaterial[3]) {
    /* KAMUS LOKAL */
    int i;
    STOCK S;
    /* ALGORITMA */
    for (i=0; i<3; i++) {
        S = MakeSTOCK((TabMaterial[i].Nama),(TabMaterial[i].Harga));
        TabStock[i] = S;
    }
}

boolean CekUpgrade(Player P, HutanWahana HW, ListWahana LW, int Cabang, long Rem) {
    /* KAMUS LOKAL */
    STOCK TabStock[3];
    int i, j, k=0;
    boolean CekMat = true, CekWaktu = true, CekUang = true, CekDekat;
    Wahana Target;
    /* ALGORITMA */
    // Cek waktu sisa
    if (Rem < 100) {
        CekWaktu = false;
        printf("Waktu yang tersisa tidak cukup\n");
    }

    CekDekat = CekPosisiWahana(P,LW);
    Target = WahanaSebelah(P,LW);

    // Cek akar keberapa di Pohon Biner
    while (!IsKataSama(NamaW(Target),FNamaWahana(HW,k))) {
        k++;
    }

    // Cek Uang, ubah material ke stock, Cabang 1 = left, cabang 2 = right
    if (Cabang == 1) {
        MaterialToStock(TabStock,FBahanBangunLeft(HW,k));
        if (Money(P) < FHargaWahanaLeft(HW,k)) CekUang = false;
    }
    if (Cabang == 2) {
        MaterialToStock(TabStock,FBahanBangunRight(HW,k));
        if (Money(P) < FHargaWahanaRight(HW,k)) CekUang = false;
    }


    // Cek Stock di player
    for (i=0; i<3; i++) {
        for (j=0; j<5; j++) {
            if (IsKataSama(NamaElStock(P,j),(TabStock[i].NAMA))) {
                if ((TabStock[i].JUMLAH)>JmlElStock(P,i)) {
                    printf("Anda tidak memiliki cukup ");
                    PrintKata(TabStock[i].NAMA);
                    printf("\n");
                    CekMat = false;
                }
            }
        }
    }
    return (CekMat && CekWaktu && CekUang && CekDekat);
}

void PushUpgrade(Kata Wahana, int k, int Cabang, Stack *S) {
    /* KAMUS LOKAL */
    Aksi X;

    /* ALGORITMA */
    X.CAksi = 'U';
    X.N1 = k; //Akar ke-k
    X.N2 = Cabang; //Cabang left atau right (1 / 2)
    X.NamaKata = Wahana;
    Push(S,X);

}

void ExecuteUpgrade(Player *P, ListWahana *LW, int k, int Cabang, HutanWahana HW, Aksi X, long *WaktuSisa) {
    /* KAMUS LOKAL */
    int i, j;
    STOCK *TabStock;
    FileWahana FW;
    Wahana W;
    addWahana Prec, PW;
    /* ALGORITMA */
    // Kurangi waktu
    *WaktuSisa -= 100;

    // Kurangi Uang
    MinusMoney(P,100);

    // Material to stock, ngurangi di player
    if (Cabang == 1) {
        MaterialToStock(TabStock,FBahanBangunLeft(HW,k));
        FW = (((HW).tree[k])->left)->info;
    }
    if (Cabang == 2) {
        MaterialToStock(TabStock,FBahanBangunRight(HW,k));
        FW = (((HW).tree[k])->right)->info;
    }
    MinusSTOCK (P,TabStock);

    // Car Posisi Wahana Lama
    Prec = *LW;
    PW = NextW(Prec);

    // Mencari Address Wahana Lama
    while (!IsKataSama(NamaWahana(PW),FNamaWahana(HW,k))) {
        Prec = NextW(Prec);
        PW = NextW(PW);
    }

    // Menambah Wahana Upgrade
    W = CreateWahana(FW, PosisiWahana(PW), MapWahana(PW));
    InsWLast(LW, W);

    // Menghapus Wahana Lama
    DelAfterWahana(LW,&PW,Prec);
}