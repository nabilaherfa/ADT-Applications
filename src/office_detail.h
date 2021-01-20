/* File : office_detail.h */

#ifndef office_detail_H
#define office_detail_H

#include <stdio.h>
#include "wahana.h"
#include "mesinkata.h"
#include "player.h"

void PrintUpgrade(Wahana W);
/*menampilkan history wahana yang sudah di upgrade*/

void Detail(Player P, ListWahana L);
/*  I.S P sudah terdefinisi. L sudah terdefinisi.
	F.S Akan ditampilkan detail dari wahana yang berada di sebelah posisi pemain */

void Office(Player P, ListWahana L);
/*  I.S 
	F.S Akan ditampilkan daftar wahana dari taman bermain	*/

#endif