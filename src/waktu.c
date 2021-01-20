/* File : waktu.c */
/* ADT yang menampung seluruh jenis waktu */

#include <stdio.h>
#include <stdlib.h>
#include "waktu.h"

/* *** Konstruktor: Membentuk WAKTU dari komponen-komponennya *** */
WAKTU MakeWAKTU (JAM CU, JAM OP, JAM CL, long REM)
/* Membentuk sebuah WAKTU dari komponen-komponennya yang valid */
/* Prekondisi : CU, OP, CL valid untuk membentuk WAKTU */
{
    /* KAMUS LOKAL */
    WAKTU W;
    /* ALGORITMA */
    Current(W) = CU;
    Open(W) = OP;
    Close(W) = CL;
    Remain(W) = REM;
    return W;
}


/* *** Selektor: Untuk sebuah WAKTU W *** */
JAM GetCurrent (WAKTU W)
/* Mengirimkan jam saat ini dalam permainan */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Current(W));
}

JAM GetOpen (WAKTU W)
/* Mengirimkan jam buka dalam permainan */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Open(W));
}

JAM GetClose (WAKTU W)
/* Mengirimkan jam tutup ini dalam permainan */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Close(W));
}

int GetRem (WAKTU W)
/* Mengirimkan detik tersisa dalam permainan */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(Remain(W));
}


/* *** Operator aritmatika JAM *** */
void NextCurrent (WAKTU * W)
/* Mengubah JAM Current bertambah 1 detik pada WAKTU W*/
{
    /* KAMUS LOKAL */
    long CurrentSecond;
    /* ALGORITMA */
    CurrentSecond = JAMToDetik(Current(*W));
    CurrentSecond++;
    Current(*W) = DetikToJAM(CurrentSecond);

}

void NextNCurrent (WAKTU * W, long N)
/* Mengubah JAM Current bertambah N detik pada WAKTU W*/
{
    /* KAMUS LOKAL */
    long CurrentSecond;
    /* ALGORITMA */
    CurrentSecond = JAMToDetik(Current(*W));
    CurrentSecond += N;
    Current(*W) = DetikToJAM(CurrentSecond);
}

void DecreaseRem (WAKTU * W)
/* Mengubah Remaining berkurang 1 detik pada WAKTU W*/
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Remain(*W)--;
}

void DecreaseNRem (WAKTU * W, long N)
/* Mengubah Remaining berkurang N detik pada WAKTU W*/
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Remain(*W) -= N;
}