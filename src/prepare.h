#include "stdio.h"
#include "prioqueue.h"
#include "printout.h"
#include "map.h"
#include "wahana.h"
#include "player.h"
#include "matriks.h"
#include "jam.h"
#include "waktu.h"

#ifndef prepare_H
#define prepare_H

void Prepare(Player *P, PrioQueue * Q, int MaxPengunjung, ListWahana *LW, WAKTU *J);
/* Mengosongkan antrian pengunjung dan langsung memanggil preparation phase */

#endif