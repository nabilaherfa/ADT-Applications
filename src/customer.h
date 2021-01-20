/* File : customer.h */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "mesinkata.h"


typedef struct 
{
    Kata TabWahana[3]; /* Array yang berisi list wahana*/
    int Sabar; /* Nilai kesabaran */
} Customer;

/* *** Notasi Akses: Selektor Customer *** */
#define TabWahana(C) (C).TabWahana[3]
#define Sabar(C) (C).Sabar

void ChangeSabar(Customer *C, int X, boolean Tambah);
/* I.S. Terdapat Customer C yang ingin diubah kesabarannya sebesar X */
/* F.S. Kesabaran Customer C diubah */
/* Proses: Jika Tambah true, maka kesabaran ditambah */
/* Jika Tambah false, maka kesabaran dikurang */

#endif