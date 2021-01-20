#include <stdio.h>
#include <math.h> 
#include "arraypos.h"

/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{ 	/* kamus */
	IdxType i;
	
	/* algoritma */
	for (i=IdxMin; i<= IdxMax; i++){
		T->TI[i] = ValUndef;
	}

}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{	/* kamus */
	int count = 0;
	IdxType i;
	
	/* algoritma */
	for (i=IdxMin; i <= IdxMax; i++){
		if (T.TI[i] != ValUndef) {
			count++;
		}
	}
	return (count-IdxMin);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{	/* algoritma */
	return (IdxMax+1-IdxMin);	
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{	/* algoritma */
	return (IdxMin);	
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{	/* algoritma */
	return (IdxMin+NbElmt(T)-1);	
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{	/* algoritma */
	return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{	/* algoritma */
	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{	/* algoritma */
	return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{	/* algoritma */
	return (NbElmt(T)==MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{	/* kamus */
	int N;
	IdxType i;

	/* algoritma */
	MakeEmpty(T);
	while (true){
        scanf("%d\n", &N);
        if (N >= 0 && N <= MaxNbEl(*T)){
            break;
        }
    }

    if (N > 0){
        for(i=IdxMin;i < N; i++){
            scanf("%d\n", &(T->TI[i]));
        }
    }

    return;
}


void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{	/* kamus */
	IdxType i;
	
	/* algoritma */
	printf("[");
	if (!(IsEmpty(T))){
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
			printf("%d", T.TI[i]);
			if (i != GetLastIdx(T)){
                printf(",");
            }
		}
	}
	printf("]");
	return;
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{	/* kamus */
	TabInt T3;
	IdxType i;
	
	/* algoritma */
	MakeEmpty(&T3);
	for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if (plus){
            Elmt(T3, i) = Elmt(T1, i)+(Elmt(T2, i) != ValUndef ? Elmt(T2, i) : 0);
        } else {
            Elmt(T3, i) = Elmt(T1, i)-(Elmt(T2, i) != ValUndef ? Elmt(T2, i) : 0);
        }
    }
	return (T3);
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{	/* kamus */
	IdxType i;
	boolean eq;
	
	if (NbElmt(T1) != NbElmt(T2)){
        eq =  false;
    } else {
    	eq = (NbElmt(T1) == NbElmt(T2));
    	for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        	eq = eq && (Elmt(T1, i) == Elmt(T2, i));
    	}
	}
    return (eq);
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{	/* kamus */
	IdxType i = GetFirstIdx(T);
	boolean found = false;
	IdxType place;
	
	/* algoritma */
	while (i <= GetLastIdx(T) && !(found) ){
		if (T.TI[i] == X){
			found = true;
		}
		i++;
	}
	
	if (found == true){
		place = i-1;
	} else {
		place = IdxUndef;
	}
	return (place);
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{	/* kamus */
	IdxType i = GetFirstIdx(T);
	boolean cari = false;
	
	/* algoritma */
	while (i <= GetLastIdx(T) && !(cari)){
		if (T.TI[i] == X){
			cari = true;
		}
		i++;
	}
	
	return (cari);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{	/* kamus */
	IdxType i;
	ElType maksimum, minimum;
	
	/* algoritma */
   	maksimum = T.TI[GetFirstIdx(T)]; 
	minimum = T.TI[GetFirstIdx(T)]; 
	
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
		if (T.TI[i] > maksimum){
			maksimum = T.TI[i];
		}
	}
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++){
		if (T.TI[i] < minimum){
			minimum = T.TI[i];
		}
	}
	* Max = maksimum;
	* Min = minimum;
	return;	
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{	/* kamus */
	int count;
	IdxType i;
	
	/* algoritma */	
	if (IsEmpty(T)){
		count = 0;
	} else {
		count = 0;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
			count = count + T.TI[i];
		}
	}
	
	return (count);
}

int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{	/* kamus */
	int count = 0;
	IdxType i;
	
	/* algoritma */	
	if (IsEmpty(T)){
		count = 0;
	} else { 
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
			if (T.TI[i]==X){
				count = count + 1;
			}
		}
	}
	
	return (count);
	
}

boolean IsAllGenap (TabInt T)
/* Menghasilkan true jika semua elemen T genap */
{	/* kamus */
	boolean genap = true;
	IdxType i = GetFirstIdx(T);
	
	/* algoritma */	
	while (i <= GetLastIdx(T) && genap){
		if (((T.TI[i]) % 2 )!= 0){
			genap = false;
		}
		i++;
	}
	return (genap);
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{	/* kamus */
	IdxType i, Pass, Imax, Imin;
	ElType Temp;
	TabInt T1;
	
	/* algoritma */	
	T1 = * T;
	if (asc==true){
		for (Pass = GetFirstIdx(T1); Pass < GetLastIdx(T1); Pass++){
			Imin = Pass;
			for (i = Pass+1; i <= GetLastIdx(T1); i++){
				if (Elmt(T1,Imin) > Elmt(T1,i)) {
					Imin  = i;
				}
			}
			Temp = Elmt(T1,Imin);
			Elmt(T1,Imin) = Elmt(T1,Pass);
			Elmt(T1,Pass) = Temp;
		}
	} else {
		for (Pass = GetFirstIdx(T1); Pass < GetLastIdx(T1); Pass++){
			Imax = Pass;
			for (i = Pass+1; i <= GetLastIdx(T1); i++){
				if (Elmt(T1,Imax) < Elmt(T1,i)) {
					Imax = i;
				}
			}
			Temp = Elmt(T1,Imax);
			Elmt(T1,Imax) = Elmt(T1,Pass);
			Elmt(T1,Pass) = Temp;
		}
	}
	* T = T1;	
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{ 	
	/* algoritma */
	T->TI[GetLastIdx(* T)+1] = X;
	return;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{	
	* X = T->TI[GetLastIdx(* T)];
	T->TI[GetLastIdx(* T)] = ValUndef;
	return;
}