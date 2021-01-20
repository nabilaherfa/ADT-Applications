
/* Clarisa Natalia Edelin */
/* 13519213 */
/*Pra Praktikum 6 */

#include "mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
   while (CC == BLANK) {
      ADV();
   }
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlank();
   if (CC == MARK) {
      EndKata = true;
   } else /* CC != MARK */ {
      EndKata = false;
      SalinKata();
   }

}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
   IgnoreBlank();
   if (CC == MARK) {
      EndKata = true;
    } else /* CC != MARK */ {
      SalinKata();
      IgnoreBlank();
    }

}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i; /* definisi */

   i = 0; /* inisialisasi */
   while ((CC != MARK) && (CC != BLANK) && (i<NMax) && (CC != '\n')) 
   {
      CKata.TabKata[i] = CC;
      ADV();
      i++;
   } /* CC = MARK or CC = BLANK */
   CKata.Length = i;

}

boolean IsKataSama (Kata K1, Kata K2)
/*  Mengembalikan true jika K1 = K2; dua kata dikatakan sama
    jika panjangnya sama dan urutan karakter yang menyusun kata juga sama.
    Dua kata kosong adalah kata yang sama.
*/
{
    /* KAMUS LOKAL */
    boolean Sama = true;
    int i = 0;
    /* ALGORITMA */
    if (K1.Length == K2.Length) {
        while ((i<K1.Length) & (Sama)) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                Sama = false;
            }
            i++;
        }
        return Sama;
    }
    else {
        return false;
    }
}

void PrintKata (Kata K)
/* Menampilkan TabKata pada layar, diakhiri dengan newline */
{
   /* KAMUS LOKAL */
   int i = 0;
   /* ALGORITMA */
   for (i=0;i<=K.Length;i++){
			printf("%c",K.TabKata[i]);
	} 
   printf("\n");
}