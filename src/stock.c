/* file : stock.h*/
/* ADT yang menggambarkan stock barang yang dimiliki oleh pemain*/

#include "stock.h"

STOCK MakeSTOCK (Kata N, int J)
/* Membentuk sebuah STOCK dari komponen - komponennya*/
{
    STOCK S;

    NamaStock(S) = N;
    Jumlah(S) = J;

    return S;
}


Kata GetNAMA (STOCK S)
/* Menulis Nama ke layar dari S*/
/* I.S. S terdefinisi */
/* F.S. Nama akan tertulis di layar */
{
    return (NamaStock(S));
}

int GetJUMLAH (STOCK S)
/* Menulis Jumlah ke layar dari S*/
/* I.S. S terdefinisi */
/* F.S. Jumlah akan tertulis di layar */
{
    return (Jumlah(S));
}

void JumlahBerkurang (STOCK S, int X)
/* Jumlah pada S berkurang sebanyak X */
/* I.S. S terdefinisi*/
/* F.S. Jumlah akan berkurang pada S */
{
    Jumlah(S) = Jumlah(S) - X;
}

void JumlahBertambah (STOCK S, int X)
/* Jumlah pada S bertambah sebanyak X */
/* I.S. S terdefinisi*/
/* F.S. Jumlah akan bertambah pada S */
{
    Jumlah(S) = Jumlah(S) + X;
}

STOCK StockBerkurang (STOCK S,STOCK S2)
{
    Jumlah(S) = Jumlah(S) - Jumlah(S2);

    return(S);
}

STOCK StockBertambah (STOCK S, STOCK S2)
{
    Jumlah(S) = Jumlah(S) + Jumlah(S2);

    return(S);
}