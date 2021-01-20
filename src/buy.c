#include "stdio.h"
#include "buy.h"

void PrintNamaMaterial() 
{
    printf("Ingin membeli material apa?\n");
    printf("0 : kayu\n");
    printf("1 : beton\n");
    printf("2 : semen\n");
    printf("3 : keramik\n");
    printf("4 : cat\n");
    printf("Masukkan pilihan (angka): ");
}

boolean CekBuyMaterial(Player P, ListMaterial LM, int material_ke, long WaktuSisa)
/* Mengecek apakah uang player cukup untuk membeli material */
{
    boolean boolUang = true;
    boolean boolDurasi = true;

    //Mengecek apakah durasi cukup
    if (WaktuSisa < 20) {
        boolDurasi = false;
    }
    //Mengecek apakah uang cukup
    if(GetMoney(P) < LMaterialHarga(LM,material_ke)){
        boolUang = false;
    }

    return boolUang;
}

void PushBuy(Player *P, Kata Material, Stack *S, int jumlah_material)
/* Menambahkan Aksi Buy ke dalam Stack jika CekBuyMaterial bernilai true */
{
    Aksi X;

    X.CAksi = 'B';
    X.N1 = jumlah_material;
    X.N2 = 0;
    X.NamaKata = Material;

    Push(S,X);
}

void BuyMaterial(Player *P, ListMaterial LM, long *WaktuSisa, int jumlah_material, Aksi X)
/* Melakukan eksekusi buy material setelah pengecekan dilakukan */
{
    //KAMUS LOKAL
    int material_ke;
    STOCK MaterialStock;

    //ALGORITMA
    //Mencari material yang ingin dibeli material ke berapa
    for(int i=0; i<5; i++) {
        if (IsKataSama(LMaterialNama(LM,i), X.NamaKata)) {
            material_ke = i;
            LMaterial(LM,i);
        }
    }

    //Mengurangkan waktu
    *WaktuSisa -= 20; //Buy butuh waktu 50

    //Mengurangkan uang
    MinusMoney(P, LMaterialHarga(LM,material_ke));
    
    //Menambahkan stock
    JumlahBertambah(MaterialStock, jumlah_material);
}
