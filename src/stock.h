/* file : stock.h*/
/* ADT yang menggambarkan stock barang yang dimiliki oleh pemain*/

#include "boolean.h"
#include "mesinkata.h"

#ifndef STOCK_H
#define STOCK_H

#define Nil NULL

typedef struct {
    Kata NAMA ;
    int JUMLAH;
} STOCK;

#define NamaStock(S) (S).NAMA
#define Jumlah(S) (S).JUMLAH

STOCK MakeSTOCK (Kata N, int J);
/* Membentuk sebuah STOCK dari komponen - komponennya*/


Kata GetNAMA (STOCK S);
/* Menulis Nama ke layar dari S*/
/* I.S. S terdefinisi */
/* F.S. Nama akan tertulis di layar */

int GetJUMLAH (STOCK S);
/* Menulis Jumlah ke layar dari S*/
/* I.S. S terdefinisi */
/* F.S. Jumlah akan tertulis di layar */

void JumlahBerkurang (STOCK S, int X);
/* Jumlah pada S berkurang sebanyak X */
/* I.S. S terdefinisi*/
/* F.S. Jumlah akan berkurang pada S */

void JumlahBertambah (STOCK S, int X);
/* Jumlah pada S bertambah sebanyak X */
/* I.S. S terdefinisi*/
/* F.S. Jumlah akan bertambah pada S */

STOCK StockBerkurang (STOCK S,STOCK S2);
/* Jumlah pada S berkurang sebanyak S2 */
/* I.S. S terdefinisi*/
/* F.S. Jumlah akan berkurang pada S */

STOCK StockBertambah (STOCK S, STOCK S2);
/* Jumlah pada S bertambah sebanyak X */
/* I.S. S terdefinisi*/
/* F.S. Jumlah akan bertambah pada S */

#endif