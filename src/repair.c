#include "stdio.h"
#include "repair.h"


void RepairWahana (Player P, ListWahana LW, long *WaktuSisa)
/* Memperbaiki wahana rusak di sebelah player */
{
    //KAMUS
	Wahana W;
	POINT PW;
	
	//ALGORITMA
	PW.X = Posisi(P).X + 1;
	PW.Y = Posisi(P).Y;

	//dicek dulu apakah disebelahnya ada wahana
	if (!(CekPosisiWahana(P, LW))) {
		printf("Disebelah Anda tidak ada wahana apapun.\nSilahkan untuk melihat peta untuk mengetahui letak wahana!\n");
    }else{
        if(Rusak(W)==true){
            if(*WaktuSisa < 50){
                printf("Tidak dapat repair wahana karena waktu Anda tidak cukup.");
            }else{
                Rusak(W) = false;
                *WaktuSisa -= 50;
                printf("Wahana sudah diperbaiki");
            }
        }else{
            printf("Disebelah Anda tidak ada wahana rusak");
        }
    }
}