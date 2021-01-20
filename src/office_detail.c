/*file office dan detail*/

#include <stdio.h>
#include "office_detail.h"

void PrintUpgrade(Wahana W)
/*menampilkan history wahana yang sudah di upgrade*/
{
	//KAMUS
	int i;
	//ALGORITMA
	if (Upgrade(W) == false) {
		if (NamaW(W).TabKata[0] == 'W') {
			printf("Wangkyi's Universe -> ");
		} else if (NamaW(W).TabKata[0] == 'u' || NamaW(W).TabKata[0] == 'L') {
			printf("HALOlintar -> ");
		} else if (NamaW(W).TabKata[0] == 'M' || NamaW(W).TabKata[0] == 'H') {
			printf("Choco's Land -> ");
		}	
	} 

	for (i=0;i<=NamaW(W).Length;i++){
		printf("%c",NamaW(W).TabKata[i]);
	}
	printf("\n");
}

void Detail(Player P, ListWahana L)
/*  I.S P sudah terdefinisi. L sudah terdefinisi.
	F.S Akan ditampilkan detail dari wahana yang berada di sebelah posisi pemain */
{
	//KAMUS
	Wahana W;
	int i;
	
	//ALGORITMA
	//dicek dulu apakah disebelahnya benar ada wahana
	//{tidak ada wahana disebelah pemain}
	if (!(CekPosisiWahana(P,L))) {
		printf("Disebelah Anda tidak ada wahana apapun.\nSilahkan untuk melihat peta untuk mengetahui letak wahana!\n");
	} else {
		//ada wahana disebalah kanan pemain
		//lihat posisi wahana pada List Wahana
		//print detail dari wahana yg telah ditemukan
		W = WahanaSebelah(P,L);
		printf("Nama : ");
		for (i=0;i<=NamaW(W).Length;i++){
			printf("%c",NamaW(W).TabKata[i]);
		} 
		printf("\n");
		printf("Harga : %d\n", HargaW(W));
		printf("Lokasi : [%d,%d] , Map %d \n", PosisiW(W).X, PosisiW(W).Y, MapW(W));
		printf("Deskripsi : " );
		for (i=0;i<=Des(W).Length;i++){
			printf("%c",Des(W).TabKata[i]);
		} 
		printf("\n");
		printf("Kapasitas : %d\n", Kap(W));
		printf("History Upgrade : " );
		printf("Durasi Wahana : %d\n", Durasi(W));
		printf("Status : " );
		if (Rusak(W)) {
			printf("Tidak berfungsi\n");
		} else {
			printf("Berfungsi\n");
		}
	}
	
}

void Office(Player P, ListWahana L) 
/*  I.S 
	F.S Akan ditampilkan daftar wahana dari taman bermain	*/
{
	//KAMUS
	char command[20];
	int i,j;
	addWahana P1,P2;
	
	//ALGORITMA
	do {
		printf("Masukkan perintah (Details / Report / Exit): \n");
		scanf("%s", command);
		if (command == "Details" || command == "details"){
				if (IsEmptyListWahana(L)) {
					printf("Anda belum membangun wahana apapun!\n");
				} else {
					//lihat detail dari tiap wahana yg telah dibangun
					P1 = L;
					while (P1 != Nil) {
						printf("Nama : ");
						for (j=0;j<=NamaWahana(P1).Length;j++){
							printf("%c",NamaWahana(P1).TabKata[j]);
						} 
						printf("\n");
						printf("Harga : %d\n", HargaWahana(P1));
						printf("Lokasi : [%d,%d] Map %d \n", PosisiWahana(P1).X, PosisiWahana(P1).Y, MapWahana(P1));
						printf("Deskripsi : ");
						for (j=0;j<=DeskripsiWahana(P1).Length;j++){
							printf("%c",DeskripsiWahana(P1).TabKata[j]);
						} 
						printf("\n");
						printf("Kapasitas : %d \n", KapasitasWahana(P1));
						printf("History Upgrade : ");
						printf("Durasi Wahana : %d \n", DurasiWahana(P1));

						P1 = NextW(P1);
					}
				}
		} else if (command == "Report"){
			if (IsEmptyListWahana(L)) {
					printf("Anda belum membangun wahana apapun!\n");
			}  else {
				/* Laporan wahana; yang setiap wahananya mencakup: 
				1. Berapa kali wahana dinaiki. 
				2. Total penghasilan dari wahana. 
				3. Berapa kali wahana dinaiki dalam hari ini. 
				4. Total penghasilan dari wahana dalam hari ini. */
				P2 = L;
				while (P2 != Nil) {
					printf("Wahana : ");
					for (j=0;j<=NamaWahana(P2).Length;j++){
						printf("%c",NamaWahana(P2).TabKata[j]);
					} 
					printf("\n");
					printf("Sudah dinaiki %d kali \n", NaikWahana(P2));
					printf("Total penghasilan wahana : %d\n", PenghasilanWahana(P2));
					printf("Hari ini sudah dinaiki %d kali \n", NaikWahanaHariIni(P2));
					printf("Hari ini wahana menghasilkan %d rupiah\n", PenghasilanWahanaHariIni(P2));

					P2 = NextW(P2);
				}
			}
		} else if (command == "Exit" || command == "exit"){
			printf("Anda Telah Keluar dari Office.\n");
		} else {
			printf("Perintah yang Anda masukkan tidak sesuai. Silahkan ulangi memasukkan perintah!.\n");
		}
	} while (command != "Exit" && command != "exit");
}
