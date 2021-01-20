/* File : player.h */
/* ADT yang menggambarkan kepemilikan dan status player */

#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void MakeTabStock (STOCK TStock[MatMax], STOCK S1, STOCK S2, STOCK S3, STOCK S4, STOCK S5)
/* Mengembalikan array of STOCK dari STOCK default per material */
/* Prekondisi : ADT STOCK per material sudah ada */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    TStock[0] = S1;
    TStock[1] = S2;
    TStock[2] = S3;
    TStock[3] = S4;
    TStock[4] = S5;
}


/* *** Konstruktor: Membentuk Player dari komponen-komponennya *** */
Player MakePlayer (Kata Nama, int Uang, STOCK TStock[MatMax])
/* Membentuk sebuah Player dari komponen-komponennya yang valid */
/* Prekondisi : Nama, Uang, TStock valid untuk membentuk WAKTU */
{
    /* KAMUS LOKAL */
    Player P;
    /* ALGORITMA */
    Name(P) = Nama;
    Money(P) = Uang;
    TabStock(P) = *TStock;
    Posisi(P) = MakePOINT(1,1);
    Map(P) = 1;
    return P;
}


/* *** Selektor: Untuk sebuah Player P *** */
Kata GetNama (Player P)
/* Mengembalikan Nama P */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Name(P));
}

int GetMoney (Player P)
/* Mengembalikan Money P */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Money(P));
}

POINT GetPosisi (Player P)
/* Mengembalikan Posisi Player pada Map */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Posisi(P));
}

int GetMap (Player P)
/* Mengembalikan nomor Map tempat player berada */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Map(P));
}


/* *** Operator aritmatika Player *** */
void PlusMoney (Player *P, int Uang)
/* Menambah Money sesuai harga tiket wahana pada saat serve */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Money(*P) += Uang;
}

void MinusMoney (Player *P, int Uang)
/* Mengurangi Money sesuai uang yang dibutuhkan */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Money(*P) -= Uang;
}

void PlusSTOCK (Player *P, STOCK TStock[3])
/* Menambah S tertentu pada P*/
{
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    for (i=0; i<3; i++) {
        for (j=0; j<5; j++) {
            if (IsKataSama(NamaStock(ElStock(*P,j)),NamaStock(TStock[i]))) {
                ElStock(*P,j) = StockBertambah(ElStock(*P,j),TStock[i]);
            }
        }
    }
}

void MinusSTOCK (Player *P, STOCK TStock[3])
/* Mengurangi S tertentu pada P */
{
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    for (i=0; i<3; i++) {
        for (j=0; j<5; j++) {
            if (IsKataSama(NamaStock(ElStock(*P,j)),NamaStock(TStock[i]))) {
                ElStock(*P,j) = StockBerkurang(ElStock(*P,j),(TStock[i]));
            }
        }
    }
}