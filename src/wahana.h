/* File : material.h */

#ifndef wahana_H
#define wahana_H

#include "boolean.h"
#include "tree.h"
#include "point.h"
#include "player.h"
#include "material.h"
#include "mesinkata.h"

typedef struct {
	POINT PosisiW; //jika belum dibangun posisi = (0,0)
	int MapW;
    Kata Nama;
    int Harga;
    int Kapasitas;
    int Durasi;
    Kata Deskripsi;
	boolean Rusak; //status
	boolean Upgrade;
	int Isi; //wahana sudah diisi berapa org
	int Naik;
	int Penghasilan;
	int NaikHariIni;
	int PenghasilanHariIni;
} Wahana;

#define Nil NULL
typedef struct tElmt *addWahana;
typedef struct tElmt {
	Wahana info;
	addWahana next;
} ElmtL;

typedef addWahana ListWahana;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define InfoW(P) (P)->info
#define NextW(P) (P)->next


//untuk yg liat wahana
#define PosisiW(Ww) (Ww).PosisiW
#define MapW(Ww) (Ww).MapW
#define NamaW(Ww) (Ww).Nama
#define HargaW(Ww) (Ww).Harga
#define Kap(Ww) (Ww).Kapasitas
#define Des(Ww) (Ww).Deskripsi
#define Durasi(Ww) (Ww).Durasi
#define Rusak(Ww) (Ww).Rusak
#define Upgrade(Ww) (Ww).Upgrade
#define Isi(Ww) (Ww).Isi
#define Naik(Ww) (Ww).Naik
#define Penghasilan(Ww) (Ww).Penghasilan
#define NaikHariIni(Ww) (Ww).NaikHariIni
#define PenghasilanHariIni(Ww) (Ww).PenghasilanHariIni

#define NamaWahana(LW) (LW)->info.Nama
#define HargaWahana(LW) (LW)->info.Harga
#define KapasitasWahana(LW) (LW)->info.Kapasitas
#define DurasiWahana(LW) (LW)->info.Durasi
#define DeskripsiWahana(LW) (LW)->info.Deskripsi
#define WahanaRusak(LW) (LW)->info.Rusak
#define UpgradeWahana(LW) (LW)->info.Upgrade
#define IsiWahana(Lw) (LW)->info.Isi
#define PosisiWahana(LW) (LW)->info.PosisiW
#define MapWahana(LW) (LW)->info.MapW
#define NaikWahana(LW) (LW)->info.Naik
#define PenghasilanWahana(LW) (LW)->info.Penghasilan
#define NaikWahanaHariIni(LW) (LW)->info.NaikHariIni
#define PenghasilanWahanaHariIni(LW) (LW)->info.PenghasilanHariIni


FileWahana MakeFWahana(Kata N,int H,int K,int D,Kata Des,int B,Material Bahan1, Material Bahan2, Material Bahan3);
/* Membuat FileWahana dari input */

void FileWahanakeArray(ListFileWahana *FW);
/* I.S. File material.txt terdefinisi */
/* F.S. List material yang ada di material.txt sudah diassign ke LM */

void PohonWahana (ListFileWahana FW, HutanWahana *HW);
/* I.S. File material.txt terdefinisi */
/* F.S. List material yang ada di material.txt sudah diassign ke LM */

void CreateEmptyListWahana (ListWahana *LW);
/* I.S LW sembarang
   F.S menghasilkan List Wahana Kosng */

boolean IsEmptyListWahana (ListWahana L);
/* Mengirim true jika list kosong */

Wahana CreateWahana (FileWahana FW, POINT posisi, int M);
/*Terbentuk Wahana*/

addWahana AlokasiWahana (Wahana X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiWahana (addWahana *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void InsWLast (ListWahana *L, Wahana X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void DelFirstWahana (ListWahana *L, addWahana *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelAfterWahana (ListWahana *L, addWahana *Pdel, addWahana Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

boolean SearchWahana (ListWahana L, POINT P, int Map);
/* menghasilkan true jika wahana ada pada list (wahana sudah dibangun) dan false jika tidak ada*/

Wahana SearchWahana1 (ListWahana L, POINT P, int Map);
/* menghasilkan wahana pada point. Wahana pada point tersebut sudah ada pada list*/

boolean CekPosisiWahana(Player P, ListWahana LW);
/*mengirimkan true jika player berada disebelah wahana*/

Wahana WahanaSebelah(Player P, ListWahana LW);
/*mengirimkan true jika player berada disebelah wahana*/

int NbElmtWahana (ListWahana LW);
/* mengembalikan jumlah elemen yang terdapat pada list wahana*/

void RandomWahanaRusak (ListWahana *LW);
/*I.S List Wahana bisa kosong */
/*F.S akan dipilih secara acak 1 wahana yg akan dijadikan rusak */
#endif
