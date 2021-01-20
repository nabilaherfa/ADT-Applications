#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>
#include <math.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return(First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	/*KAMUS*/
	/*ALGORITMA*/
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/*KAMUS*/
	address P;
	
	/*ALGORITMA*/
	P = (address) malloc (1*sizeof(ElmtList));
	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
	} 
	return (P);
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	/*KAMUS*/
	/*ALGORITMA*/
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	/*KAMUS*/
	address P;
	boolean found;
	
	/*ALGORITMA*/
	P = First(L);
	if (P == Nil){
		found = false;
	} else {
		while ((Next(P) != Nil) && (Info(P) != X)){
			P = Next(P);
		}
		found = (Info(P) == X);
	}
	
	if (!found){
		return (Nil);
	} else {
		return (P);
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	/*KAMUS*/
	address P;
	
	/*ALGORITMA*/
	P = Alokasi(X);
	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	} 
	
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	/*KAMUS*/
	address P;
	address Last;
	
	/*ALGORITMA*/
	if (IsEmpty(*L)){
		InsVFirst(L,X);
	} else {
		P = Alokasi(X);
		if (P != Nil ){
			Last = First(*L);
			while (Next(Last) != Nil){
				Last = Next(Last);
			}
			Next(Last) = P;
			Next(Next(Last)) = Nil;
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	/*KAMUS*/
	address P;
	
	/*ALGORITMA*/
	P = First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	/*KAMUS*/
	address P, Prec;
	
	/*ALGORITMA*/
	P = First(*L);
	Prec = Nil;
	while (Next(P) != Nil){
		Prec = P;
		P = Next(P);
	}
	*X = Info(P);
	if (Prec == Nil){
		First(*L) = Nil;
	} else {
		Next(Prec) = Nil;
	}
	Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	/*KAMUS*/
	/*ALGORITMA*/
	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	/*KAMUS*/
	/*ALGORITMA*/
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	/*KAMUS*/
	address Last;
	
	/*ALGORITMA*/
	if (P == Nil) return;
	
	if (IsEmpty(*L)){
		InsertFirst(L,P);
	} else {
		Last = First(*L);
		while (Next(Last) != Nil){
			Last = Next(Last);
		}
		Next(P) = Nil;
		Next(Last) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	/*KAMUS*/
	/*ALGORITMA*/
	*P = First(*L);
	First(*L) = Next(*P);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/*KAMUS*/
	address P, Prec;
	
	/*ALGORITMA*/
	if(!IsEmpty(*L)){
        P = First(*L);
        if(Info(P) == X){
            DelFirst(L, &Prec);
        }else{
            while(Next(P) != Nil && Info(Next(P)) != X){
                P = Next(P);
            }
            if(Next(P) != Nil){
                DelAfter(L, &Prec, P);
            }
        }
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	/*KAMUS*/
	address Prec;
	
	/*ALGORITMA*/
	*P = First(*L);
	Prec = Nil;
	while (Next(*P) != Nil){
		Prec = *P;
		*P = Next(*P);
	}
	
	if (Prec == Nil){
		First(*L) = Nil;
	} else {
		Next(Prec) = Nil;
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	/*KAMUS*/
	/*ALGORITMA*/
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	/*KAMUS*/
	address P;
	/*ALGORITMA*/
	printf("[");
	if (!IsEmpty(L)){
		P = First(L);
		while (P != Nil){
			printf("%d", Info(P));
			if (Next(P)!= Nil){
				printf(",");
			}
			P = Next(P);
		}
	}
	printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	/*KAMUS*/
	int count;
	address P;
	
	/*ALGORITMA*/
	if (IsEmpty(L)){
		count = 0;
	} else {
		count = 0;
		P = First(L);
		while (P != Nil){
			count++;
			P = Next(P);
		}
	}
	return(count);
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
	/*KAMUS*/
	address P;
	infotype Min;
	
	/*ALGORITMA*/
	if (NbElmt(L) == 1){
		Min = Info(First(L));
	} else {
		P = First(L);
		Min = Info(P);
		while (P != Nil){
			if (Info(P) < Min){
				Min = Info (P);
			}
			P = Next(P);
		}
	}
	return (Min);
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	/*KAMUS*/
	address P;
	infotype Max;
	
	/*ALGORITMA*/
	if (NbElmt(L) == 1){
		Max = Info(First(L));
	} else {
		P = First(L);
		Max = Info(P);
		while (P != Nil){
			if (Info(P) > Max){
				Max = Info (P);
			}
			P = Next(P);
		}
	}
	return(Max);
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	/*KAMUS*/
	address P, Prec;
	
	/*ALGORITMA*/
	CreateEmpty(L3);
	if (!IsEmpty(*L1)){
		P = First(*L1);
		Prec = Nil;
		First(*L3) = P;
		while (P != Nil){
			Prec = P;
			P = Next(P);
		}
		Next(Prec) = First(*L2);
	} else {
		First(*L3) = First(*L2);
	}
	CreateEmpty(L1);
	CreateEmpty(L2);
	return;
}