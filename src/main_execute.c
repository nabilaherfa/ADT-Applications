#include <stdio.h>
#include <stdlib.h>
#include "main_execute.h"


//main
void Main (Player *P, Stack *S, int day, ListWahana *LW, WAKTU *J, PrioQueue Q, MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4) 
/* I.S P sembarang
   F.S Menampilkan map dan fitur - fitur lainnya tanpa mengeksekusi isi stack */
{
	//KAMUS
	Aksi X;
	JAM CU, OP, CL;
	//ALGORITMA
	//pop isi stack tanpa eksekusi
	while (!(IsEmptyStack(*S))){
		Pop(S,&X);
	}
	
	CU = MakeJAM(9,00,00);
    OP = MakeJAM(9,00,00);
    CL = MakeJAM(21,00,00);

	Current(*J) = CU;
	Open(*J) = OP;
	Close(*J) = CL;
	Remain(*J) = 43200;


	//random wahana rusak
	RandomWahanaRusak(LW);

	printf("Main phase day %d \n", day);
	
	//cari posisi dari player lalu print map sesuai posisi
	if (Map(*P) == 1){
		printMainPhaseMap1(*P,*J,Q,M1);
	} else if (Map(*P) == 2) {
		printMainPhaseMap2(*P,*J,Q,M2);
	} else if (Map(*P) == 3) {
		printMainPhaseMap3(*P,*J,Q,M3);
	} else if (Map(*P) == 4) {
		printMainPhaseMap4(*P,*J,Q,M4);
	}
	
}

//execute
void Execute (Player *P, Stack *S, int day, ListMaterial LM, long *WaktuSisa, ListWahana *LW, HutanWahana HW, MATRIKS *M, WAKTU *J, PrioQueue Q, MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4)
/* I.S P sembarang, S sudah terdefinisi
   F.S Menampilkan map dan fitur - fitur lainnya setelah mengeksekusi isi stack*/
{
	//KAMUS
	Aksi X;
	JAM CU, OP, CL;

	//ALGORITMA
	//pop isi stack satu per satu
	while (!(IsEmptyStack(*S))) {
		if (InfoTopCAksi(*S) == 'B') {
			//lakukan operasi untuk buy
			BuyMaterial(P, LM, WaktuSisa, InfoTopN1(*S), InfoTop(*S));
		} else if (InfoTopCAksi(*S) == 'U') {
			//lakukan operasi untuk upgrade
			ExecuteUpgrade(P, LW, InfoTopN1(*S), InfoTopN2(*S), HW, InfoTop(*S), WaktuSisa);
		} else if (InfoTopCAksi(*S) == 'D') {
			//lakukan operasi untuk build
			ExecuteBuild(P, LW, HW, InfoTop(*S), WaktuSisa, M);
		}
		Pop(S,&X);
	}

	CU = MakeJAM(9,00,00);
    OP = MakeJAM(9,00,00);
    CL = MakeJAM(21,00,00);

	Current(*J) = CU;
	Open(*J) = OP;
	Close(*J) = CL;
	Remain(*J) = 43200;

	//random wahana rusak
	RandomWahanaRusak(LW);

	printf("Main phase day %d \n", day);
	//cari posisi dari player lalu print map sesuai posisi
	if (Map(*P) == 1){
		printMainPhaseMap1(*P,*J,Q,M1);
	} else if (Map(*P) == 2) {
		printMainPhaseMap2(*P,*J,Q,M2);
	} else if (Map(*P) == 3) {
		printMainPhaseMap3(*P,*J,Q,M3);
	} else if (Map(*P) == 4) {
		printMainPhaseMap4(*P,*J,Q,M4);
	}
	
	
}
