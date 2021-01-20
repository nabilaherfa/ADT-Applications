/* file: wasd.h */
/* untuk memindah */

#ifndef wasd_H
#define wasd_H

#include "map.h"
#include "player.h"
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

void W (Player P);
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke atas */

void A (Player P);
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke kiri */

void S (Player P);
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke bawah */

void D (Player P);
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke kanan */

boolean IsPagar (Player P, char C);
/* i.s. posisi pada posisi awal */ 
/* f.s. jika player berpindah sebanyak 1 ke kanan 
    atau kiri atau atas atau bawah dan ternyata menuju pagar,  
    fungsi akan mengirim true. kalau bukan pagar false */

boolean IsGerbang (Player P, char C);
/* i.s. posisi pada posisi awal */
/* f.s. jika player berpindah sebanyak 1 ke kanan 
    atau kiri atau atas atau bawah dan ternyata menuju gerbang,  
    fungsi akan mengirim true. kalau bukan gerbang false */

#endif

