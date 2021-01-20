/* File build.c */

#include <stdio.h>
#include "build.h"

void PrintNamaWahana()
/* I.S. Sembarang */
/* F.S. Nama-nama wahana ditampilkan ke layar */
{
    printf("Wahana apa yang ingin kamu bangun?\n");
    printf("0 : Wangky's Universe\n");
    printf("1 : HALOlintar\n");
    printf("2 : ChocoLand\n");
    printf("Masukkan pilihan (angka): ");
}

boolean CekResourceWahana(Player P, HutanWahana HW, int wahana_ke, long WaktuSisa)
/* I.S. Terdapat W, P, dan Wahana ke wahana_ke  */
/* F.S. */
{
    //KAMUS LOKAL
    boolean boolDurasi = true, boolUang = true, boolMaterial = true;

    //ALGORITMA
    //Mengecek apakah durasi cukup, JUJUR MASIH BINGUNG SAMA REMAINNYA
    if (WaktuSisa < 100) boolDurasi = false;

    //Mengecek apakah uang cukup
    if (FBiayaWahana(HW,wahana_ke) > GetMoney(P)) boolUang = false;

    //Mengecek apakah material cukup
    for(int i=0; i<5; i++) { //Ngecek di TabStock Player
        for(int j=0; j<3; j++) { //Ngecek di Material yg dibutuhkan di Wahana
            if (IsKataSama(ElStock(P,i).NAMA, FNamaWahana(HW,wahana_ke))) {
                if (ElStock(P,i).JUMLAH < FHargaWahana(HW,wahana_ke)) {
                    boolMaterial = false;
                }
            }
        }
    }

    return boolDurasi && boolUang && boolMaterial;
}

void PushBuild(Player *P, Kata Wahana, Stack *S) {

    //KAMUS LOKAL
    Aksi X;

    //ALGORITMA
    X.CAksi = 'D';
    X.N1 = Absis(Posisi(*P));
    X.N2 = Ordinat(Posisi(*P));
    X.NamaKata = Wahana;
    Push(S,X);
    
}

void ExecuteBuild(Player *P, ListWahana *LW, HutanWahana HW, Aksi X, long *WaktuSisa, MATRIKS *M)
/* I.S. Player merupakan pemain yang sudah mempunyai berbagai resource untuk membangun wahana
F.S.  Jika resource mencukupi, maka wahana akan dibangun
Proses: Melakukan pengecekan terhadap waktu, uang, material, dan luas
*/
{
    //KAMUS LOKAL
    int wahana_ke;
    FileWahana FW;
    Wahana W;

    //ALGORITMA
    //Mencari wahana yang mau dibangun itu wahana ke berapa
    for(int i=0; i<3; i++) {
        if (IsKataSama(FNamaWahana(HW,i), X.NamaKata)) {
            wahana_ke = i;
            FW = HW.tree[wahana_ke]->info;
        }
    }

    //Mengurangkan waktu
    *WaktuSisa -= 100; //Build butuh waktu 100

    //Mengurangkan uang
    Money(*P) -= FBiayaWahana(HW,wahana_ke);

    //Mengurangkan stock
    for(int i=0; i<5; i++) { //Ngecek di TabStock Player
        for(int j=0; j<3; j++) { //Ngecek di Material yg dibutuhkan di Wahana
            if (IsKataSama(ElStock(*P,i).NAMA, FNamaWahana(HW,j))) {
                ElStock(*P,i).JUMLAH -= FIsiBahan(HW,wahana_ke,j).Harga;
            }
        }
    }

    //Mengubah map
    Elmt(*M, X.N1, X.N2) = 'W';

    //Menambah wahana ke list wahana yang sudah dibangun
    W = CreateWahana(FW, MakePOINT(X.N1, X.N2), Map(*P));
    InsWLast(LW, W);
}