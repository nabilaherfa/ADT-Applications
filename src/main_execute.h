/* File : main_execute.h */

#ifndef main_execute_H
#define main_execute_H

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "stackt.h"
#include "buy.h"
#include "upgrade.h"
#include "build.h"
#include "material.h"
#include "wahana.h"
#include "matriks.h"
#include "waktu.h"
#include "prioqueue.h"

void Main (Player *P, Stack *S, int day, ListWahana *LW, WAKTU *J, PrioQueue Q, MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4);
/* I.S P sembarang
   F.S Menampilkan map dan fitur - fitur lainnya tanpa mengeksekusi isi stack */

void Execute (Player *P, Stack *S, int day, ListMaterial LM, long *WaktuSisa, ListWahana *LW, HutanWahana HW, MATRIKS *M, WAKTU *J, PrioQueue Q, MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4);
/* I.S P sembarang, S sudah terdefinisi
   F.S Menampilkan map dan fitur - fitur lainnya setelah mengeksekusi isi stack*/

#endif