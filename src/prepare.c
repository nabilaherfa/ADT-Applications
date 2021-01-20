#include "stdio.h"
#include "prepare.h"
#include "printout.h"
#include "player.h"
#include "wahana.h"
#include "matriks.h"
#include "jam.h"
#include "waktu.h"

void Prepare(Player *P, PrioQueue * Q, int MaxPengunjung, ListWahana *LW, WAKTU *J)
/* Mengosongkan antrian pengunjung dan langsung memanggil preparation phase */
{
	MATRIKS M1,M2,M3,M4;
	JAM CU, OP, CL;
	//set ulang wahana
	CU = MakeJAM(21,00,00);
    OP = MakeJAM(9,00,00);
    CL = MakeJAM(21,00,00);

	Current(*J) = CU;
	Open(*J) = OP;
	Close(*J) = CL;
	Remain(*J) = 43200;

	addWahana P1;
	P1 = *LW;
	while (P1 != Nil){
		NaikWahanaHariIni(P1) = 0;
		PenghasilanWahanaHariIni(P1) = 0;
		P1 = NextW(P1);
	}

    MakePrioQueueEmpty(Q, MaxPengunjung);
    //cari posisi dari player lalu print map sesuai posisi
	if (Map(*P) == 1){
		printPreparationPhaseMap1(*P, *J, M1);
	} else if (Map(*P) == 2) {
		printPreparationPhaseMap2(*P, *J, M2);
	} else if (Map(*P) == 3) {
		printPreparationPhaseMap3(*P, *J, M3);
	} else if (Map(*P) == 4) {
		printPreparationPhaseMap4(*P, *J, M4);
	}

}