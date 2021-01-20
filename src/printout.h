/* file : printout.h */
/* buat print tulisan2 default dalam game*/

#ifndef PrintOut_H
#define PrintOut_H

#include "map.h"
#include "player.h"
#include "waktu.h"
#include "prioqueue.h"
#include "jam.h"

void printTitleGame();
/*print tampilan awal saat memulai game*/

void printNewGame();
/*print tampilan new game*/

void printPreparationPhaseMap1(Player P,WAKTU J,MATRIKS M1);
/*print tampilan saat preparation phase Map 1*/

void printPreparationPhaseMap2(Player P,WAKTU J,MATRIKS M2);
/*print tampilan saat preparation phase Map 2*/

void printPreparationPhaseMap3(Player P,WAKTU J,MATRIKS M3);
/*print tampilan saat preparation phase Map 3*/

void printPreparationPhaseMap4(Player P,WAKTU J,MATRIKS M4);
/*print tampilan saat preparation phase Map 4*/

void printExitGame();
/*print tampilan game saat exit*/

void printMainPhaseMap1(Player P, WAKTU J, PrioQueue Q,MATRIKS M1);
/*menampilkan tampilan game saat main phase Map 1*/

void printMainPhaseMap2(Player P, WAKTU J, PrioQueue Q,MATRIKS M2);
/*menampilkan tampilan game saat main phase Map 2*/

void printMainPhaseMap3(Player P, WAKTU J, PrioQueue Q,MATRIKS M3);
/*menampilkan tampilan game saat main phase Map 3*/

void printMainPhaseMap4(Player P, WAKTU J, PrioQueue Q,MATRIKS M4);
/*menampilkan tampilan game saat main phase Map 4*/

#endif


