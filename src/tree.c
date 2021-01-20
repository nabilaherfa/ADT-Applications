/* File: tree.c */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/* *** KONSTRUKTOR *** */
BinTree Tree (infoW Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi
berhasil. Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	//KAMUS
	BinTree T;
	
	//ALGORITMA
	T = (BinTree) malloc (sizeof(Node));
    if (T != Nil) {
        Akar(T) = Akar;
        Left(T) = L;
        Right(T) = R;
    }
    return T;
}

void MakeTree (infoW Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Sembarang 
   F.S. Menghasilkan sebuah pohon P 
  Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
  Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */
{
	//KAMUS
	//ALGORITMA
	*P = Tree(Akar,L,R);
}
  
/* *** MEMORY MANAGEMENT *** */
addTree Alokasi (infoW X)
/* Mengirimkan address hasil alokasi sebuah elemen X 
   Jika alokasi berhasil, maka address tidak nil, dan misalnya 
   menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil 
   Jika alokasi gagal, mengirimkan Nil */
{
	//KAMUS
	addTree P;
	
	//ALGORITMA
	P = (addTree) malloc (1*sizeof(Node));
    if (P != Nil){
        Akar(P) = X;
        Right(P) = Nil;
        Left(P) = Nil;
    }
    return P;
	
}

void Dealokasi (addTree P)
/* I.S. P terdefinisi 
   F.S. P dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address P */
{
	//KAMUS
	//ALGORITMA
	free(P);
}
   
/* *** PREDIKAT PENTING *** */
boolean IsTreeEmpty (BinTree P)
/*  Mengirimkan true jika P adalah pohon biner yang kosong */
{
	//KAMUS
	//ALGORITMA
	return(P==Nil);
}

boolean IsOneElmtTree (BinTree P)
/*  Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen */
{
	//KAMUS
	//ALGORITMA
	return (Right(P) == Nil) && (Left(P) == Nil);
}

boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
	//KAMUS
	//ALGORITMA
	return (Left(P) != Nil) && (Right(P) == Nil);
}

boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
	//KAMUS
	//ALGORITMA
	return (Right(P) != Nil) && (Left(P) == Nil);
}

boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner: 
   mempunyai subpohon kiri dan subpohon kanan */
{
	//KAMUS
	//ALGORITMA
	return (Right(P) != Nil) && (Left(P) != Nil);
}

//boolean SearchTree(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
//{
	//KAMUS
	//ALGORITMA
/*    if (IsOneElmtTree(P)){
        return (Akar(P) == X);
    }
    else{
        if (IsUnerLeft(P)){
            return (Akar(P) == X) || SearchTree(Left(P),X);
        }
        else if (IsUnerRight(P)){
            return (Akar(P) == X) || SearchTree(Right(P),X);
        }
        else if (IsBiner(P)){
            return (Akar(P) == X) || SearchTree(Left(P),X) || SearchTree(Right(P),X);
        }
        else{
            return false;
        }
    }
} */

int NbElmtTree(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	//KAMUS
	//ALGORITMA
    if (IsOneElmtTree(P)){
        return 1;
    }
    else{
        if (IsUnerLeft(P)){
            return 1 + NbElmtTree(Left(P));
        }
        else if (IsUnerRight(P)){
            return 1 + NbElmtTree(Right(P));
        }
        else if (IsBiner(P)){
            return 1 + NbElmtTree(Left(P)) + NbElmtTree(Right(P));
        }
        else{
            return 0;
        }
    }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
	//KAMUS
	//ALGORITMA
    if (IsOneElmtTree(P)){
        return 1;
    }
    else{
        if (IsUnerLeft(P)){
            return NbDaun(Left(P));
        }
        else if (IsUnerRight(P)){
            return NbDaun(Right(P));
        }
        else if (IsBiner(P)){
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
        else{
            return 0;
        }
    }
}
