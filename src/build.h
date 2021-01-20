#ifndef build_H
#define build_H

#include <stdio.h>
#include "player.h"
#include "wahana.h"
#include "point.h"
#include "tree.h"
#include "stackt.h"
#include "map.h"

void PrintNamaWahana();
/* I.S. Sembarang */
/* F.S. Nama-nama wahana ditampilkan ke layar */

boolean CekResourceWahana(Player P, HutanWahana HW, int wahana_ke, long WaktuSisa);
/* Menentukan apakah resource cukup untuk membangun wahana */

void PushBuild(Player *P, Kata Wahana, Stack *S);

void ExecuteBuild(Player *P, ListWahana *LW, HutanWahana HW, Aksi X, long *WaktuSisa, MATRIKS *M);
/* I.S. Player merupakan pemain yang sudah mempunyai berbagai resource untuk membangun wahana
F.S.  Jika resource mencukupi, maka wahana akan dibangun
Proses: Melakukan pengecekan terhadap waktu, uang, material, dan luas
Jika hanya luas yang tidak cukup, maka akan dibangun pada 1x1 saja
Jika ada selain luas yang tidak cukup, maka wahana tidak akan dibangun dan ditampilkan pesan error
*/

#endif