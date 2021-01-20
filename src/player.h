/* File : player.h */
/* ADT yang menggambarkan kepemilikan dan status player */
#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "mesinkata.h"
#include "stock.h"
#include "point.h"

#define MatMax 5 //Banyak jenis material

/* *** Definisi TYPE Player *** */
typedef struct {
	Kata Name; /* Nama Player */
    int Money; /* Uang yang dimiliki Player */
    STOCK TabStock[MatMax]; /* Tempat penyimpanan jenis material beserta jumlahnya, indeks [0..MatMax-1] */
    POINT Posisi; /* Posisi Player pada satu Map */
    int Map; /* Map letak player */
} Player;

/* *** Notasi Akses: selektor Player *** */
#define Name(P) (P).Name
#define Money(P) (P).Money
#define TabStock(P) (P).TabStock[MatMax]
#define ElStock(P,i) (P).TabStock[(i)]
#define NamaElStock(P,i) (P).TabStock[(i)].NAMA
#define JmlElStock(P,i) (P).TabStock[(i)].JUMLAH
#define Posisi(P) (P).Posisi
#define Map(P) (P).Map

void MakeTabStock (STOCK TStock[MatMax], STOCK S1, STOCK S2, STOCK S3, STOCK S4, STOCK S5);
/* Membentuk array of STOCK dari STOCK default per material */
/* Prekondisi : ADT STOCK per material sudah ada */

/* *** Konstruktor: Membentuk Player dari komponen-komponennya *** */
Player MakePlayer (Kata Nama, int Uang, STOCK TStock[MatMax]);
/* Membentuk sebuah Player dari komponen-komponennya yang valid */
/* Prekondisi : Nama, Uang, TStock valid untuk membentuk WAKTU */

Kata GetNama (Player P);
/* Mengembalikan Nama P */

int GetMoney (Player P);
/* Mengembalikan Money P */

POINT GetPosisi (Player P);
/* Mengembalikan Posisi Player pada Map */

int GetMap (Player P);
/* Mengembalikan nomor Map tempat player berada */

void PlusMoney (Player *P, int Uang);
/* Menambah Money sesuai harga tiket wahana pada saat serve */

void MinusMoney (Player *P, int Uang);
/* Mengurangi Money sesuai uang yang dibutuhkan */

void PlusSTOCK (Player *P, STOCK TStock[3]);
/* Menambah S tertentu pada P*/

void MinusSTOCK (Player *P, STOCK TStock[3]);
/* Mengurangi S tertentu pada P */

#endif