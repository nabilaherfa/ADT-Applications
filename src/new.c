#include <stdio.h>
#include "new.h"

void NewGame (Player *P) {
    /* KAMUS LOKAL */
    Kata Nama;
    Kata M1, M2, M3, M4, M5;
    STOCK S1, S2, S3, S4, S5, TStock[MatMax];
    /* ALGORITMA */
    // Input nama pengguna
    ADVKATA();
    Nama = CKata;

    // Kata Material
    M1.Length = 4;
    M1.TabKata[0] = 'k';
    M1.TabKata[1] = 'a';
    M1.TabKata[2] = 'y';
    M1.TabKata[3] = 'u';
    M2.Length = 5;
    M2.TabKata[0] = 'b';
    M2.TabKata[1] = 'e';
    M2.TabKata[2] = 't';
    M2.TabKata[3] = 'o';
    M2.TabKata[4] = 'n';
    M3.Length = 5;
    M3.TabKata[0] = 's';
    M3.TabKata[1] = 'e';
    M3.TabKata[2] = 'm';
    M3.TabKata[3] = 'e';
    M3.TabKata[4] = 'n';
    M4.Length = 7;
    M4.TabKata[0] = 'k';
    M4.TabKata[1] = 'e';
    M4.TabKata[2] = 'r';
    M4.TabKata[3] = 'a';
    M4.TabKata[4] = 'm';
    M4.TabKata[5] = 'i';
    M4.TabKata[6] = 'k';
    M5.Length = 3;
    M5.TabKata[0] = 'c';
    M5.TabKata[1] = 'a';
    M5.TabKata[2] = 't';

    // Membuat Stock dengan inisiasi 15
    S1 = MakeSTOCK(M1,15);
    S2 = MakeSTOCK(M2,15);
    S3 = MakeSTOCK(M3,15);
    S4 = MakeSTOCK(M4,15);
    S5 = MakeSTOCK(M5,15);

    // Membuat TabStock untuk player
    MakeTabStock(TStock,S1,S2,S3,S4,S5);

    // Membuat Player
    *P = MakePlayer(Nama,1000,TStock);
}