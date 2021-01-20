/* File : map.h */
/* contoh ADT map untuk file tubes */

#ifndef MAP_H
#define MAP_H

#include "boolean.h"
#include "matriks.h"
#include "point.h"
/* Ukuran minimum dan maksimum baris dan kolom */

MATRIKS TulisMAP1();
/* Membaca file map1.txt dan menampilkan matriks map ke layar */

MATRIKS TulisMAP2();
/* Membaca file map2.txt dan menampilkan matriks map ke layar */

MATRIKS TulisMAP3();
/* Membaca file map3.txt dan menampilkan matriks map ke layar */

MATRIKS TulisMAP4();
/* Membaca file map4.txt dan menampilkan matriks map ke layar */

void MakeMATRIKSMAP (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKSMAP "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

void BacaMAP1 (MATRIKS * M);
/* Membaca file map1.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar */

void BacaMAP2 (MATRIKS * M);
/* Membaca file map2.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar */

void BacaMAP3 (MATRIKS * M);
/* Membaca file map3.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar */

void BacaMAP4 (MATRIKS * M);
/* Membaca file map4.txt dan mengubahnya ke dalam bentuk matriks tanpa menampilkan ke layar */

POINT MakePOINTMAP (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

ElType GetElementMAP (MATRIKS M, indeks i, indeks j);
/* Mendapatkan elemen matriks[baris][kolom] yang diinginkan */

POINT SearchElement(MATRIKS M, char P);
/* Mencari posisi elemen P di dalam matriks */

void TulisMATRIKSMAP (MATRIKS M);
/* Menampilkan current map dalam bentuk matriks */

#endif
