#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"
#include "player.h"
#include "stackt.h"
#include "point.h"
#include "wahana.h"
#include "tree.h"
#include "stock.h"
#include "material.h"
#include "waktu.h"

int PrintUpgradeList(Player P, ListWahana LW, HutanWahana HW);

void MaterialToStock(STOCK TabStock[3], Material TabMaterial[3]);

boolean CekUpgrade(Player P, HutanWahana HW, ListWahana LW, int Cabang, long Rem);

void PushUpgrade(Kata Wahana, int k, int Cabang, Stack *S);

void ExecuteUpgrade(Player *P, ListWahana *LW, int k, int Cabang, HutanWahana HW, Aksi X, long *WaktuSisa);