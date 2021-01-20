/* File : waktu.h */
/* ADT yang menampung seluruh jenis waktu */
#ifndef WAKTU_H
#define WAKTU_H

#include "boolean.h"
#include "jam.h"

/* *** Definisi TYPE WAKTU *** */
typedef struct {
	JAM Current; /* JAM Dinamis */
	JAM Open; /* JAM Statis */
    JAM Close; /* JAM Statis */
	long Remaining; /* integer Dinamis */
} WAKTU;

/* *** Notasi Akses: selektor WAKTU *** */
#define Current(W) (W).Current
#define Open(W) (W).Open
#define Close(W) (W).Close
#define Remain(W) (W).Remaining

/* *** Konstruktor: Membentuk WAKTU dari komponen-komponennya *** */
WAKTU MakeWAKTU (JAM CU, JAM OP, JAM CL, long REM);
/* Membentuk sebuah WAKTU dari komponen-komponennya yang valid */
/* Prekondisi : CU, OP, CL valid untuk membentuk WAKTU */

/* *** Selektor: Untuk sebuah WAKTU W *** */
JAM GetCurrent (WAKTU W);
/* Mengirimkan jam saat ini dalam permainan */
JAM GetOpen (WAKTU W);
/* Mengirimkan jam buka dalam permainan */
JAM GetClose (WAKTU W);
/* Mengirimkan jam tutup ini dalam permainan */
int GetRem (WAKTU W);
/* Mengirimkan detik tersisa dalam permainan */

/* *** Operator aritmatika JAM *** */
void NextCurrent (WAKTU * w);
/* Mengubah JAM Current bertambah 1 detik pada WAKTU W*/
void NextNCurrent (WAKTU * W, long N);
/* Mengubah JAM Current bertambah N detik pada WAKTU W*/
void DecreaseRem (WAKTU * W);
/* Mengubah Remaining berkurang 1 detik pada WAKTU W*/
void DecreaseNRem (WAKTU * W, long N);
/* Mengubah Remaining berkurang N detik pada WAKTU W*/

#endif