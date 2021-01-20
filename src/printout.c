/* file : printout.h */
/* buat print tulisan2 default dalam game*/

#include <stdlib.h>
#include <stdio.h>
#include "printout.h"


void printTitleGame()
/*print tampilan awal saat memulai game*/
{
    printf("// Welcome to Willy wangky's fum factory!! //\n");
    printf("// New game / load game / exit? //\n");
}

void printNewGame()
/*print tampilan new game*/
{
    printf("Memulai permainan baru...\n");
    printf("Masukkan nama:");
}

void printPreparationPhaseMap1(Player P,WAKTU J,MATRIKS M1)
/*print tampilan saat preparation phase*/
{
    printf("Preparation phase day 1\n"); /*1 nya bisa berubah2*/
    TulisMATRIKSMAP(M1);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Total aksi yang akan dilakukan: \n");
    printf("Total waktu yang dibutuhkan: \n");
    printf("Total uang yang dibutuhkan: \n");
    printf("\n Masukkan Perintah: \n");

}

void printPreparationPhaseMap2(Player P, WAKTU J,MATRIKS M2)
/*print tampilan saat preparation phase Map 2*/
{
    printf("Preparation phase day 1\n"); /*1 nya bisa berubah2*/
    TulisMATRIKSMAP(M2);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Total aksi yang akan dilakukan: \n");
    printf("Total waktu yang dibutuhkan: \n");
    printf("Total uang yang dibutuhkan: \n");
    printf("\n Masukkan Perintah: \n");
}

void printPreparationPhaseMap3(Player P, WAKTU J, MATRIKS M3)
/*print tampilan saat preparation phase Map 3*/
{
    printf("Preparation phase day 1\n"); /*1 nya bisa berubah2*/
    TulisMATRIKSMAP(M3);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Total aksi yang akan dilakukan: \n");
    printf("Total waktu yang dibutuhkan: \n");
    printf("Total uang yang dibutuhkan: \n");
    printf("\n Masukkan Perintah: \n");
}

void printPreparationPhaseMap4(Player P,WAKTU J, MATRIKS M4)
/*print tampilan saat preparation phase Map 4*/
{
    printf("Preparation phase day 1\n"); /*1 nya bisa berubah2*/
    TulisMATRIKSMAP(M4);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Total aksi yang akan dilakukan: \n");
    printf("Total waktu yang dibutuhkan: \n");
    printf("Total uang yang dibutuhkan: \n");
    printf("\n Masukkan Perintah: \n");
}

void printExitGame()
/*print tampilan game saat exit*/
{
    printf("// Thanks for playing!!! //\n");
}

void printMainPhaseMap1(Player P, WAKTU J, PrioQueue Q,MATRIKS M1)
/*menampilkan tampilan game saat main phase*/
{
    printf("Main phase day 1\n");
    TulisMATRIKSMAP(M1);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Antrian[%d/%d]: \n", NBPrioQueueElmt(Q),MaxElQ(Q));
    // PrintPrioQueue(Q); /*bagian [] itu gak tau maksudnya*/
    printf("\n Masukkan Perintah: \n");
}

void printMainPhaseMap2(Player P, WAKTU J, PrioQueue Q,MATRIKS M2)
/*menampilkan tampilan game saat main phase*/
{
    printf("Main phase day 1\n");
    TulisMATRIKSMAP(M2);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Antrian[%d/%d]: \n", NBPrioQueueElmt(Q),MaxElQ(Q));
    // PrintPrioQueue(Q); /*bagian [] itu gak tau maksudnya*/
    printf("\n Masukkan Perintah: \n");
}

void printMainPhaseMap3(Player P, WAKTU J, PrioQueue Q,MATRIKS M3)
/*menampilkan tampilan game saat main phase*/
{
    printf("Main phase day 1\n");
    TulisMATRIKSMAP(M3);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Antrian[%d/%d]: \n", NBPrioQueueElmt(Q),MaxElQ(Q));
    // PrintPrioQueue(Q); /*bagian [] itu gak tau maksudnya*/
    printf("\n Masukkan Perintah: \n");
}

void printMainPhaseMap4(Player P, WAKTU J, PrioQueue Q,MATRIKS M4)
/*menampilkan tampilan game saat main phase*/
{
    printf("Main phase day 1\n");
    TulisMATRIKSMAP(M4);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V, = Gerbang\n");
    printf("Name : ");
    PrintKata(Name(P)); printf("\n");
    printf("Money : %d\n",Money(P));
    printf("Current Time: ");
    TulisJAM(Current(J)); printf("\n");
    printf("Opening Time: ");
    TulisJAM(Open(J)); printf("\n");
    printf("Time Remaining: %ld\n",Remain(J));
    printf("Antrian[%d/%d]: \n", NBPrioQueueElmt(Q),MaxElQ(Q));
    // PrintPrioQueue(Q); /*bagian [] itu gak tau maksudnya*/
    printf("\n Masukkan Perintah: \n");
}


