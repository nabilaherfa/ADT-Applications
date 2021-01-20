#include <stdio.h>
#include <stdlib.h>
#include "map.h"

MATRIKS TulisMAP1 () 
//membaca file map1.txt dan menampilkan matriks map ke layar
{
    //harus array of char
    char matriks[10][20]; 
    int rows, cols;
    FILE *file;

    file = fopen("../FileEksternal/map1.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map1.txt");
        exit(EXIT_FAILURE);
    }

    //membaca file menjadi matriks
    for (rows = 0; rows < 10; rows++)
        for (cols = 0; cols < 20; cols++)
            fscanf(file, " %c", &matriks[rows][cols]); 

    //print matriks
    for (rows = 0; rows < 10; rows++) {
        for (cols = 0; cols < 20; cols++)
            printf("%c", matriks[rows][cols]);
        printf("\n");
    }
}

MATRIKS TulisMAP2 () 
//membaca file map2.txt dan menampilkan matriks map ke layar
{
    //harus array of char
    char matriks[10][20]; 
    int rows, cols;
    FILE *file;

    file = fopen("../FileEksternal/map2.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map2.txt");
        exit(EXIT_FAILURE);
    }

    //membaca file menjadi matriks
    for (rows = 0; rows < 10; rows++)
        for (cols = 0; cols < 20; cols++)
            fscanf(file, " %c", &matriks[rows][cols]); 

    //print matriks
    for (rows = 0; rows < 10; rows++) {
        for (cols = 0; cols < 20; cols++)
            printf("%c", matriks[rows][cols]);
        printf("\n");
    }
}

MATRIKS TulisMAP3 ()
//membaca file map3.txt dan menampilkan matriks map ke layar
{
    //harus array of char
    char matriks[10][20]; 
    int rows, cols;
    FILE *file;

    file = fopen("../FileEksternal/map3.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map3.txt");
        exit(EXIT_FAILURE);
    }
    //membaca file menjadi matriks
    for (rows = 0; rows < 10; rows++)
        for (cols = 0; cols < 20; cols++)
            fscanf(file, " %c", &matriks[rows][cols]); 

    //print matriks
    for (rows = 0; rows < 10; rows++) {
        for (cols = 0; cols < 20; cols++)
            printf("%c", matriks[rows][cols]);
        printf("\n");
    }
}

MATRIKS TulisMAP4 () 
//membaca file map4.txt dan menampilkan matriks map ke layar
{
    //harus array of char
    char matriks[10][20]; 
    int rows, cols;
    FILE *file;

    file = fopen("../FileEksternal/map4.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map4.txt");
        exit(EXIT_FAILURE);
    }

    //membaca file menjadi matriks
    for (rows = 0; rows < 10; rows++)
        for (cols = 0; cols < 20; cols++)
            fscanf(file, " %c", &matriks[rows][cols]); 

    //print matriks
    for (rows = 0; rows < 10; rows++) {
        for (cols = 0; cols < 20; cols++)
            printf("%c", matriks[rows][cols]);
        printf("\n");
    }
}

void MakeMATRIKSMAP (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKSMAP "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/* KAMUS */
	/* ALGORITMA */
		NBrsEff(*M) = NB;
		NKolEff(*M) = NK;
}

void BacaMAP1 (MATRIKS * M)
//membaca file map1.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar
{
	/* KAMUS */
    char temp;
	indeks i = 0, j = 0;
    int NB = 10;
    int NK = 20;
	/* ALGORITMA */
    FILE *file;

    file = fopen("../FileEksternal/map1.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map1.txt");
        exit(EXIT_FAILURE);
    }
	MakeMATRIKSMAP(NB,NK,M);
	for (i=0; i<NB; i++) {
		for (j=0; j<NK; j++) {
			fscanf(file, "%c", &temp);
            while(temp == '\n'){
                fscanf(file, "%c", &temp);
            }
            if(temp != '\n'){
                Elmt(*M,i,j)=temp;
            }
		}
	}
}

void BacaMAP2 (MATRIKS * M)
//membaca file map1.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar
{
	/* KAMUS */
    char temp;
	indeks i = 0, j = 0;
    int NB = 10;
    int NK = 20;
	/* ALGORITMA */
    FILE *file;

    file = fopen("../FileEksternal/map2.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map2.txt");
        exit(EXIT_FAILURE);
    }
	MakeMATRIKSMAP(NB,NK,M);
	for (i=0; i<NB; i++) {
		for (j=0; j<NK; j++) {
			fscanf(file, "%c", &temp);
            while(temp == '\n'){
                fscanf(file, "%c", &temp);
            }
            if(temp != '\n'){
                Elmt(*M,i,j)=temp;
            }
		}
	}
}

void BacaMAP3 (MATRIKS * M)
//membaca file map1.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar
{
	/* KAMUS */
    char temp;
	indeks i = 0, j = 0;
    int NB = 10;
    int NK = 20;
	/* ALGORITMA */
    FILE *file;

    file = fopen("../FileEksternal/map3.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map3.txt");
        exit(EXIT_FAILURE);
    }
	MakeMATRIKSMAP(NB,NK,M);
	for (i=0; i<NB; i++) {
		for (j=0; j<NK; j++) {
			fscanf(file, "%c", &temp);
            while(temp == '\n'){
                fscanf(file, "%c", &temp);
            }
            if(temp != '\n'){
                Elmt(*M,i,j)=temp;
            }
		}
	}
}

void BacaMAP4 (MATRIKS * M)
//membaca file map1.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar
{
	/* KAMUS */
    char temp;
	indeks i = 0, j = 0;
    int NB = 10;
    int NK = 20;
	/* ALGORITMA */
    FILE *file;

    file = fopen("../FileEksternal/map4.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file %s.\n", "map4.txt");
        exit(EXIT_FAILURE);
    }
	MakeMATRIKSMAP(NB,NK,M);
	for (i=0; i<NB; i++) {
		for (j=0; j<NK; j++) {
			fscanf(file, "%c", &temp);
            while(temp == '\n'){
                fscanf(file, "%c", &temp);
            }
            if(temp != '\n'){
                Elmt(*M,i,j)=temp;
            }
		}
	}
}

ElType GetElementMAP (MATRIKS M, indeks i, indeks j)
//Mendapatkan elemen matriks[baris][kolom] yang diinginkan
{
    return(Elmt(M,i,j));
}

POINT MakePOINTMAP (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
   POINT P;

   Absis(P) = X;
   Ordinat(P) =Y;
   return P;
}

POINT SearchElement(MATRIKS M, char P)
//Mencari posisi elemen P di dalam matriks
{
    indeks i = 0, j = 0;
    POINT Z;
    int NB = 10;
    int NK = 20;
    int absis, ordinat;
	/* ALGORITMA */
    
	for (i=0; i<NB; i++) 
		for (j=0; j<NK; j++)
            if(GetElementMAP(M,i,j)==P){
                absis = i;
                ordinat = j;
                Z = MakePOINTMAP(absis,ordinat);
                return Z;
                break;
            }
}

void TulisMATRIKSMAP (MATRIKS M)
/* Menampilkan current map dalam bentuk matriks */
{
	/* KAMUS */
	indeks i = 0, j = 0;
	/* ALGORITMA */
		for (i=0; i<10; i++) {
			for (j=0; j<20; j++) {
				printf("%c", Elmt(M,i,j));
			}
			if (i != 10) {
				printf("\n");
			}
	    }
}


// //driver
// int main(){
//     POINT P;
//     MATRIKS M;
//     BacaMAP2(&M);
//     TulisMATRIKSMAP(M);
//     printf("%c", GetElementMAP(M,1,1));
//     P = SearchElement(M, 'A');
//     printf("(%d, %d)", P.X, P.Y);
// }
