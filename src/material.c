/* File : material.c */

#include <stdio.h>
#include <stdlib.h>
#include "material.h"

FILE *fptr;
char line[20]; //Buat jaga-jaga aja makanya diassign 20

Kata CharToKata(char Line[])
/* Mengubah bentuk array of char menjadi Kata */
{
    //KAMUS LOKAL
    Kata currKata;
    int i = 0;

    //ALGORTIMA
    //Memasukkan Line ke TabKata
    while (Line[i] != '\n') {
        currKata.TabKata[i] = Line[i];
        i++;
    }
    //Memasukkan panjang Line ke Length
    currKata.Length = i-1;

    return currKata;
}

int CharToInt(char Line[])
/* Mengubah bentuk array of char menjadi integer */
{
    //KAMUS LOKAL
    int i = 0;
    int N = 0;
    int currInt;

    //ALGORITMA
    while (Line[i] != '\n') {
        if (Line[i] == '1') currInt = 1;
        else if (Line[i] == '2') currInt = 2;
        else if (Line[i] == '3') currInt = 3;
        else if (Line[i] == '4') currInt = 4;
        else if (Line[i] == '5') currInt = 5;
        else if (Line[i] == '6') currInt = 6;
        else if (Line[i] == '7') currInt = 7;
        else if (Line[i] == '8') currInt = 8;
        else if (Line[i] == '9') currInt = 9;
        else if (Line[i] == '0') currInt = 0;
        N = (N*10) + currInt;
        i++;
    }

    return (N);
}

/* ********* KONSTRUKTOR ********* */
Material MakeMaterial(Kata N,int H)
/* Membuat Material dari input N berupa Nama dan H berupa Harga */
{
    //KAMUS LOKAL
    Material currMaterial;

    //ALGORITMA
    Nama(currMaterial) = N;
    Harga(currMaterial) = H;

    return currMaterial;
}

void MakeListMaterial(ListMaterial *LM)
/* I.S. File material.txt terdefinisi */
/* F.S. List material yang ada di material.txt sudah diassign ke LM */
{
    //KAMUS LOKAL
    int count = 1;
    int datake;
    Kata currNama;
    int currHarga;
    Material currMaterial;

    //ALGORITMA
    //Membuka file material.txt
    fptr = fopen("../FileEksternal/material.txt","r");

    //Membaca baris per baris material.txt
    while (fgets(line,sizeof(line),fptr)) {

        //Jika pembacaan ke-bilangan ganjil, artinya sedang membaca nama
        if (count%2 == 1) {
            currNama = CharToKata(line);
        }
        //Jika pembacaan ke-bilangan genap, artinya sedang membaca harga
        else {
            currHarga = CharToInt(line);

            //Membuat Material
            currMaterial = MakeMaterial(currNama,currHarga);

            datake = (count/2)-1;

            //Memasukkan Material ke ListMaterial
            LMaterial(*LM,datake) = currMaterial;
        }

        count++;
    }

    //Menutup file material.txt
    fclose(fptr);

    return;
}

/**** DIBAWAH INI ADALAH DRIVER BUATAN UNTUK MENCOBA ADT ****/
/**** Coba dengan menjalankan gcc material.h material.c -o material ****/
/*
int main() {
    ListMaterial L;

    MakeListMaterial(&L);

    for(int j = 0;j<LMaterialNama(L,4).Length;j++) {
        printf("%c",LMaterialNamaTabKata(L,4)[j]); //Ngeprint data Nama Material ke-4
    }
    printf("\n");
    printf("%d\n",LMaterialNama(L,4).Length); //Ngeprint data Panjang Kata Material ke-4
    printf("%d\n",LMaterialHarga(L,4)); //Ngeprint data Harga Material ke-4

    return 0;
}
*/
