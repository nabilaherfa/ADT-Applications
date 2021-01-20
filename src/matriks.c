/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/* KAMUS */
	/* ALGORITMA */
		NBrsEff(*M) = NB;
		NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	/* KAMUS */
	/* ALGORITMA */
	return((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	/* KAMUS */
	/* ALGORITMA */
	return(BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	/* KAMUS */
	/* ALGORITMA */
	return(KolMin);
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	/* KAMUS */
	/* ALGORITMA */
	return(NBrsEff(M)-1);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	/* KAMUS */
	/* ALGORITMA */
	return(NKolEff(M)-1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/* KAMUS */
	/* ALGORITMA */
	return((i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M)) && (j<=GetLastIdxKol(M)) && (j>=GetFirstIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	/* KAMUS */
	/* ALGORITMA */
	return(Elmt(M,i,i));
}

/* ********** Assignment  MATRIKS ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
 return (NBrsEff(M)*NKolEff(M));
}

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	/* KAMUS */
	indeks i = 0, j = 0;
	/* ALGORITMA */
	MakeMATRIKS (NBrsEff(MIn),NKolEff(MIn),MHsl);
	for (i=GetFirstIdxBrs(MIn); i<NBrsEff(MIn); i++) {
		for (j=GetFirstIdxKol(MIn); j<NKolEff(MIn); j++) {
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
	/* KAMUS */
	indeks i = 0, j = 0;
	/* ALGORITMA */
	MakeMATRIKS(NB,NK,M);
	for (i=0; i<NB; i++) {
		for (j=0; j<NK; j++) {
			scanf("%hhd", &Elmt(*M,i,j));
		}
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	/* KAMUS */
	indeks i = 0, j = 0;
	/* ALGORITMA */
	if ((NBrsEff(M)>0) && (NKolEff(M)>0)) {
		for (i=0; i<NBrsEff(M); i++) {
			for (j=0; j<NKolEff(M); j++) {
				printf("%d", Elmt(M,i,j));
				if (j != GetLastIdxKol(M)) {
					printf(" ");
				}
			}
			if (i != GetLastIdxBrs(M)) {
				printf("\n");
			}
		}
	}
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
	/* KAMUS */
	indeks i = 0, j = 0;
	MATRIKS MHsl;
	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
	if (EQSize(M1,M2)) {
		for (i=0; i<NBrsEff(MHsl); i++) {
			for (j=0; j<NKolEff(MHsl); j++) {
				Elmt(MHsl,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
			}
		}
		return (MHsl);
	}
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
	/* KAMUS */
	indeks i = 0, j = 0;
	MATRIKS MHsl;
	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
	if (EQSize(M1,M2)) {
		for (i=0; i<NBrsEff(MHsl); i++) {
			for (j=0; j<NKolEff(MHsl); j++) {
				Elmt(MHsl,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
			}
		}
		return (MHsl);
	}
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	/* KAMUS */
	indeks i = 0, j = 0, k = 0;
	MATRIKS MHsl;
	/* ALGORITMA */
	if (NKolEff(M1)==NBrsEff(M2)) {
		MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&MHsl);
		for (i=0; i<NBrsEff(MHsl); i++) {
			for (j=0; j<NKolEff(MHsl); j++) {
				Elmt(MHsl,i,j) = 0;
			}
		}
		for (i=0; i<NBrsEff(MHsl); i++) {
			for (j=0; j<NKolEff(MHsl); j++) {
				for (k=0; k<NKolEff(M1); k++) {
					Elmt(MHsl,i,j) += Elmt(M1,i,k)*Elmt(M2,k,j);
				}
			}
		}
		return (MHsl);
	}
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	/* KAMUS */
	indeks i = 0, j = 0;
	MATRIKS MHsl;
	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MHsl);
	for (i=0; i<NBrsEff(MHsl); i++) {
		for (j=0; j<NKolEff(MHsl); j++) {
			Elmt(MHsl,i,j) = Elmt(M,i,j)*X;
		}
	}
	return (MHsl);
}
	

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	/* KAMUS */
	/* ALGORITMA */
	*M = KaliKons(*M,K);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	/* KAMUS */
	indeks i = 0, j = 0;
	boolean Cek = true;
	/* ALGORITMA */
	if (NBElmt(M1) == NBElmt(M2)) {
		for (i=0; i<NBrsEff(M1); i++) {
			for (j=0; j<NKolEff(M1); j++) {
				if (Elmt(M1,i,j) != Elmt(M2,i,j)) {
					Cek = false;
				}
			}
		}
		return (Cek);
	}
	else {
		return (false);
	}
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	/* KAMUS */
	/* ALGORITMA */
	return (!EQ(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	/* KAMUS */
	/* ALGORITMA */
	return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	/* KAMUS */
	/* ALGORITMA */
	return(NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	/* KAMUS */
	indeks i = 0, j = 0;
	boolean Sim = true;
	/* ALGORITMA */
	if (!IsBujurSangkar(M)) {
		return (false);
	}
	else {
		for (i=0; i<NBrsEff(M); i++) {
			for (j=0; j<NKolEff(M); j++) {
				if (Elmt(M,i,j)!=Elmt(M,j,i)) {
					Sim = false;
				}
			}
		}
		return (Sim);
	}
}
	
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
	/* KAMUS */
	indeks i = 0, j = 0;
	boolean Sat = true;
	/* ALGORITMA */
	if (!IsBujurSangkar(M)) {
		return (false);
	}
	else {
		for (i=0; i<NBrsEff(M); i++) {
			if (GetElmtDiagonal(M,i) != 1) {
				Sat = false;
			}
			for (j=0; j<NBrsEff(M); j++) {
				if ((i != j) && (Elmt(M,i,j) != 0)) {
					Sat = false;
				}
			}
		}
		return (Sat);
	}
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
	/* KAMUS */
	indeks i = 0, j = 0;
	int Count = 0;
	boolean Sparse;
	/* ALGORITMA */
	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) == 0) {
            	Count++;
			}
        }
	}
	if (Count>=NBElmt(M)*0.95) {
		Sparse = true;
	}
	else {
		Sparse = false;
	}
	return (Sparse);
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	/* KAMUS */
	/* ALGORITMA */
	return(KaliKons(M,-1));
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	/* KAMUS */
	/* ALGORITMA */
	PKaliKons(M,-1);
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	/* KAMUS */
	indeks i = 0, j = 0;
	MATRIKS MHsl;
	/* ALGORITMA */
	if (IsBujurSangkar(*M)) {
		MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&MHsl);
		for (i=0; i<NBrsEff(MHsl); i++) {
			for (j=0; j<NKolEff(MHsl); j++) {
				Elmt(MHsl,i,j) = Elmt(*M,j,i);
			}
		}
		*M = MHsl;
	}
}

/* TAMBAHAN PRAKTIKUM */
float RataBrs (MATRIKS M, indeks i) {
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
    indeks j;
	ElType sum = 0;
	int count = 0;
	
	if (i>=GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M)) {
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
			sum += Elmt(M, i, j);
			count += 1;
		}
	}
	return(sum/count);
}

float RataKol (MATRIKS M, indeks j) {
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
    indeks i;
	ElType sum = 0;
	int count = 0;
	
	if (j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M)) {
		for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
			sum += Elmt(M, i, j);
			count += 1;
		}
	}
	return(sum/count);
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min) {
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
    indeks j;

	*min = Elmt(M, i, GetFirstIdxKol(M));
	*max = Elmt(M, i, GetFirstIdxKol(M));
    if (i>=GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M)) {
    	for (j=GetFirstIdxKol(M)+1; j<=GetLastIdxKol(M); j++) {
    		if (Elmt(M, i, j) > *max)
    			*max = Elmt(M, i, j);
    		if (Elmt(M, i, j) < *min)
    			*min = Elmt(M, i, j);
		}
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min) {
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    indeks i;
	
	*min = Elmt(M, GetFirstIdxBrs(M), j);
	*max = Elmt(M, GetFirstIdxBrs(M), j);
	if (j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M)) {
    	for (i=GetFirstIdxBrs(M)+1; i<=GetLastIdxBrs(M); i++) {
    		if (Elmt(M, i, j) > *max)
    			*max = Elmt(M, i, j);
    		if (Elmt(M, i, j) < *min)
    			*min = Elmt(M, i, j);
		}
	}
}

int CountXBrs (MATRIKS M, indeks i, ElType X) {
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    int count = 0;
    indeks j;
	
	if (i>=GetFirstIdxBrs(M) && i<GetLastIdxBrs(M)) {
    	for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
    		if (Elmt(M, i, j) == X)
				count += 1;
		}
	}
	return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X) {
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    int count = 0;
    indeks i;
	
	if (j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M)) {
    	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
   			if (Elmt(M, i, j) == X)
				count += 1;
		}
	}		
	return count;
}

// int main()
// {
//     MATRIKS M;
//     MakeMATRIKS(2,3,&M);

//     BacaMATRIKS(&M,2,3);

//     TulisMATRIKS(M);

//     return 0;

// }
