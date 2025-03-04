
/* File : stackt.c */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include <stdio.h>
#include "stackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP berNillai Nill */
{
    // KAMUS LOKAL

    // ALGORITMA
    Top(*S) = Nill;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    // KAMUS LOKAL

    // ALGORITMA
    return (Top(S) == Nill);
}

boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung Nillai elemen stack penuh */
{
    // KAMUS LOKAL

    // ALGORITMA
    return (Top(S) == MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Aksi X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    // KAMUS LOKAL

    // ALGORITMA
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Aksi * X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Nillai elemen TOP yang lama, TOP berkurang 1 */
{
    // KAMUS LOKAL

    // ALGORITMA
    *X = InfoTop(*S);
    Top(*S) -= 1;
}