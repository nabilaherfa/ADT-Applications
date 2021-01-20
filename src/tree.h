/* File: tree.h */

#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "material.h"

#define Nil NULL
/* *** Definisi Type Pohon Biner *** */
typedef struct {
	Kata FNama;
    int FHarga;
    int FKapasitas;
    int FDurasi;
    Kata FDeskripsi;
    int FBiaya;
    Material FTabBahan[3]; 
} FileWahana;


typedef struct {
    FileWahana FList[9]; //Karena banyak wahana pada txt adalah 9
} ListFileWahana;

typedef FileWahana infoW;
typedef struct tNode *addTree;
typedef struct tNode { 
	infoW info;
	addTree left;
	addTree right;
} Node;

/* Definisi PohonBiner */
/* Pohon Biner kosong P = Nil */
typedef addTree BinTree;

typedef struct { 
	BinTree tree[3];
} HutanWahana;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

#define TWahana(HW,i) (HW).tree[i]

//untuk yg file wahana
#define FNama(W) (W).FNama
#define FHarga(W) (W).FHarga
#define FKap(W) (W).FKapasitas
#define FDur(W) (W).FDurasi
#define FDes(W) (W).FDeskripsi
#define FBiaya(W) (W).FBiaya
#define FBahan(W) (W).FTabBahan
#define FBahanIsi(W,i) (W).FTabBahan[i]

#define FWahana(FW,i) (FW).FList[i]

#define FNamaWahana(FW,i) ((FW).tree[i])->info.FNama
#define FHargaWahana(FW,i) ((FW).tree[i])->info.FHarga
#define FKapasitas(FW,i) ((FW).tree[i])->info.FKapasitas
#define FDurasi(FW,i) ((FW).tree[i])->info.FDurasi
#define FDeskripsiWahana(FW,i) ((FW).tree[i])->info.FDeskripsi
#define FBiayaWahana(FW,i) ((FW).tree[i])->info.FBiaya
#define FBahanBangun(FW,i) ((FW).tree[i])->info.FTabBahan
#define FIsiBahan(FW,i,j) ((FW).tree[i])->info.FTabBahan[j]

#define FNamaWahanaLeft(FW,i) (((FW).tree[i])->left)->info.FNama
#define FHargaWahanaLeft(FW,i) (((FW).tree[i])->left)->info.FHarga
#define FKapasitasLeft(FW,i) (((FW).tree[i])->left)->info.FKapasitas
#define FDurasiLeft(FW,i) (((FW).tree[i])->left)->info.FDurasi
#define FDeskripsiWahanaLeft(FW,i) (((FW).tree[i])->left)->info.FDeskripsi
#define FBiayaWahanaLeft(FW,i) (((FW).tree[i])->left)->info.FBiaya
#define FBahanBangunLeft(FW,i) (((FW).tree[i])->left)->info.FTabBahan
#define FIsiBahanLeft(FW,i,j) (((FW).tree[i])->left)->info.FTabBahan[j]

#define FNamaWahanaRight(FW,i) (((FW).tree[i])->right)->info.FNama
#define FHargaWahanaRight(FW,i) (((FW).tree[i])->right)->info.FHarga
#define FKapasitasRight(FW,i) (((FW).tree[i])->right)->info.FKapasitas
#define FDurasiRight(FW,i) (((FW).tree[i])->right)->info.FDurasi
#define FDeskripsiWahanaRight(FW,i) (((FW).tree[i])->right)->info.FDeskripsi
#define FBiayaWahanaRight(FW,i) (((FW).tree[i])->right)->info.FBiaya
#define FBahanBangunRight(FW,i) (((FW).tree[i])->right)->info.FTabBahan
#define FIsiBahanRight(FW,i,j) (((FW).tree[i])->right)->info.FTabBahan[j]

/* *** KONSTRUKTOR *** */
BinTree Tree (infoW Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi
berhasil. Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (infoW Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Sembarang 
   F.S. Menghasilkan sebuah pohon P 
  Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
  Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */
  
/* *** MEMORY MANAGEMENT *** */
addTree Alokasi (infoW X);
/* Mengirimkan address hasil alokasi sebuah elemen X 
   Jika alokasi berhasil, maka address tidak nil, dan misalnya 
   menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil 
   Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addTree P);
/* I.S. P terdefinisi 
   F.S. P dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address P */
   
/* *** PREDIKAT PENTING *** */
boolean IsTreeEmpty (BinTree P);
/*  Mengirimkan true jika P adalah pohon biner yang kosong */
boolean IsOneElmtTree (BinTree P);
/*  Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen */
boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner: 
   mempunyai subpohon kiri dan subpohon kanan */
   
//boolean SearchTree(BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
int NbElmtTree(BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
  
#endif

