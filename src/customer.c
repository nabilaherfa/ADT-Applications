/* File : customer.c */

#include "customer.h"
#include <stdio.h>

void ChangeSabar(Customer *C, int X, boolean Tambah)
/* I.S. Terdapat Customer C yang ingin diubah kesabarannya sebesar X */
/* F.S. Kesabaran Customer C diubah */
/* Proses: Jika Tambah true, maka kesabaran ditambah */
/* Jika Tambah false, maka kesabaran dikurang */
{
    //KAMUS LOKAL

    //ALGORTIMA
    if (Tambah) Sabar(*C) += X;
    else Sabar(*C) -= X;
}
