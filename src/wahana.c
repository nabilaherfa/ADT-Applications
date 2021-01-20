#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

FILE *fptr;
char line[20];
/* ********* KONSTRUKTOR ********* */
FileWahana MakeFWahana(Kata N,int H,int K,int D,Kata Des,int B, Material Bahan1, Material Bahan2, Material Bahan3)
/* Membuat FileWahana dari input */
{
	//KAMUS
	FileWahana currWahana;
	int i;
	
	//ALGORITMA
	FNama(currWahana)	= N;
	FHarga(currWahana) = H;
	FKap (currWahana)	= K;
	FDes(currWahana) = Des;
	FBiaya(currWahana) = B;
	currWahana.FTabBahan[0] = Bahan1; 
	currWahana.FTabBahan[1] = Bahan2;
	currWahana.FTabBahan[2] = Bahan3;
	
	return(currWahana);
}

void FileWahanakeArray(ListFileWahana *FW)
/* I.S. File material.txt terdefinisi */
/* F.S. List material yang ada di material.txt sudah diassign ke LM */
{
     //KAMUS LOKAL
    Kata Nama;
    int Harga;
    int Kapasitas;
    int Durasi;
    Kata Deskripsi;
    int Biaya;
    int Hargabahan1;
    int Hargabahan2;
    int Hargabahan3;
    Kata Namabahan1;
    Kata Namabahan2;
    Kata Namabahan3;
    Material TabBahan[3]; //harga diubah jadi jumlah
    FileWahana currWahana;
    

	int j;
	int count = 1;
	int i = 0;
	int datake = 0;
    //ALGORITMA
    //Membuka file material.txt
    fptr = fopen("../FileEksternal/wahana.txt","r");

	if (fptr == NULL) {
        printf("Tidak dapat membuka file %s.\n", "wahana.txt");
        exit(EXIT_FAILURE);
    }
    
    //Membaca baris per baris material.txt
    while (fgets(line,sizeof(line),fptr)) {
        if (count%12 == 1) {
            Nama = CharToKata(line);
        } else if (count%12 == 2) {
            Harga = CharToInt(line);
            
        } else if (count%12 ==3) {
        	Kapasitas = CharToInt(line);
			
		} else if (count%12 == 4) {
			Durasi = CharToInt(line);
			
		} else if (count%12 == 5) {
			Deskripsi = CharToKata(line);
			
		} else if (count%12 == 6) {
			Biaya = CharToInt(line);
			
		} else if (count%12 == 7) {
			Hargabahan1 = CharToInt(line);
			
		} else if (count%12 == 8) {
			Namabahan1 = CharToKata(line);
			TabBahan[0] = MakeMaterial(Namabahan1,Hargabahan1);
			
		} else if (count%12 == 9) {
			Hargabahan2 = CharToInt(line);
			
		} else if (count%12 == 10) {
			Namabahan2 = CharToKata(line);
			TabBahan[1] = MakeMaterial(Namabahan2,Hargabahan2);
			
		} else if (count%12 == 11) {
			Hargabahan3 = CharToInt(line);
			
		}else if (count%12 == 0) {
			Namabahan3 = CharToKata(line);
			TabBahan[2] = MakeMaterial(Namabahan3,Hargabahan3);
            
			//Membuat Wahana
            currWahana = MakeFWahana(Nama,Harga,Kapasitas,Durasi,Deskripsi,Biaya,TabBahan[0],TabBahan[1],TabBahan[2]);

            datake = (count/12)-1;

            //Memasukkan Wahana ke ListFileWahana
            FWahana(*FW,datake) = currWahana;
		}
        count++;
    }
    
    //Menutup file wahana.txt
    fclose(fptr);
    
    return;
}

void PohonWahana (ListFileWahana FW, HutanWahana *HW)
/* I.S. File material.txt terdefinisi */
/* F.S. List material yang ada di material.txt sudah diassign ke LM */
{
	//KAMUS
	int i,j;
	addTree T1,T2;
	
	//ALGORITMA
	i = 0;
	j = 0;
	while (i < 9) {
		T1 = Alokasi(FW.FList[i+1]);
		T2 = Alokasi(FW.FList[i+2]);
		TWahana(*HW,j) = Tree(FW.FList[i], T1, T2);
		i = i+3;
		j++;
	}
	
}

void CreateEmptyListWahana (ListWahana *LW)
/* I.S LW sembarang
   F.S menghasilkan List Wahana Kosng */
{
	//KAMUS
	//ALGORITMA
	*LW = Nil;

}

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListWahana (ListWahana L)
/* Mengirim true jika list kosong */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return(L == Nil);
}

Wahana CreateWahana (FileWahana FW, POINT posisi, int M)
/*Terbentuk Wahana*/
{
	/*KAMUS*/
	Wahana Ww;
	
	/*ALGORITMA*/
	PosisiW(Ww) = posisi;
	MapW(Ww) = M;
	NamaW(Ww) = FNama(FW);
	HargaW(Ww) = FHarga(FW);
	Kap(Ww) = FKap(FW);
	Des(Ww) = FDes(FW);
	Durasi(Ww) = FDur(FW);
	Rusak(Ww) = false;
	Upgrade(Ww) = false;
	Isi(Ww) = 0;
	Naik(Ww) = 0;
	Penghasilan(Ww) = 0;
	NaikHariIni(Ww) = 0;
	PenghasilanHariIni(Ww) = 0;
	return(Ww);
}

/****************** Manajemen Memori ******************/
addWahana AlokasiWahana (Wahana X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/*KAMUS*/
	addWahana P;
	
	/*ALGORITMA*/
	P = (addWahana) malloc (1*sizeof(ElmtL));
	if (P != Nil){
		InfoW(P) = X;
		NextW(P) = Nil;
	} 
	return (P);
}

void DealokasiWahana (addWahana *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	/*KAMUS*/
	/*ALGORITMA*/
	free(*P);
}

void InsWLast (ListWahana *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	/*KAMUS*/
	addWahana P;
	addWahana Last;
	
	/*ALGORITMA*/
	P = AlokasiWahana(X);
	if (P != Nil ){
		if (IsEmptyListWahana(*L)){
			NextW(P) = *L;
			*L = P;
		} else {
			Last = *L;
			while (NextW(Last) != Nil){
				Last = NextW(Last);
			}
			NextW(Last) = P;
			NextW(NextW(Last)) = Nil;
		}
	}
}
void DelFirstWahana (ListWahana *L, addWahana *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	/*KAMUS*/
	/*ALGORITMA*/
	*P = *L;
	*L = NextW(*P);
}

void DelAfterWahana (ListWahana *L, addWahana *Pdel, addWahana Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	/*KAMUS*/
	/*ALGORITMA*/
	*Pdel = NextW(Prec);
	NextW(Prec) = NextW(*Pdel);
}

boolean SearchWahana (ListWahana L, POINT P, int Map)
/* menghasilkan true jika wahana ada pada list (wahana sudah dibangun) dan false jika tidak ada*/
{
	//KAMUS
	addWahana P1;
	boolean found;
	//ALGORITMA
	P1 = L;
	found = false;
	while (P1 != Nil && found == false) {
		if (InfoW(P1).PosisiW.X == P.X && InfoW(P1).PosisiW.Y == P.Y && InfoW(P1).MapW == Map) {
			found = true;
		} else {
			P1 = NextW(P1);
		}
	}
	return (found);
}

Wahana SearchWahana1 (ListWahana L, POINT P, int Map)
/* menghasilkan wahana pada point. Wahana pada point tersebut sudah ada pada list*/
{
	//KAMUS
	addWahana P1;
	boolean found;
	//ALGORITMA
	P1 = L;
	found = false;
	while (P1 != Nil && found == false) {
		if (InfoW(P1).PosisiW.X == P.X && InfoW(P1).PosisiW.Y == P.Y && InfoW(P1).MapW == Map) {
			found = true;
		} else {
			P1 = NextW(P1);
		}
	}

	if (found) {
		return(InfoW(P1));
	}
}

boolean CekPosisiWahana(Player P, ListWahana LW) 
/*mengirimkan true jika player berada disebelah wahana*/
{
    /* KAMUS LOKAL */
    boolean Sebelah;
    float XI, YI;
	addWahana P1;

    /* ALGORITMA */
    Sebelah = false;
	P1 = LW;
    while ((P1 != Nil) && (!Sebelah)) {
            if (MapWahana(P1) == Map(P)) {
                XI = Posisi(P).X - PosisiWahana(P1).X;
                YI = Posisi(P).Y - PosisiWahana(P1).Y;
                if ((XI == 0 && abs(YI) == 1) || (abs(XI) == 1 && YI == 0)) {
                    Sebelah = true;
                }
            }
        P1 = NextW(P1);
    }
    return Sebelah;
}

Wahana WahanaSebelah(Player P, ListWahana LW) 
/*mengirimkan true jika player berada disebelah wahana*/
{
    /* KAMUS LOKAL */
    boolean Sebelah;
    float XI, YI;
	Wahana W;
	addWahana P1;


    /* ALGORITMA */
    Sebelah = false;
	P1 = LW;
    while ((P1 != Nil) && (!Sebelah)) {
            if (MapWahana(P1) == Map(P)) {
                XI = Posisi(P).X - PosisiWahana(P1).X;
                YI = Posisi(P).Y - PosisiWahana(P1).Y;
                if ((XI == 0 && abs(YI) == 1) || (abs(XI) == 1 && YI == 0)) {
                    Sebelah = true;
					W = InfoW(P1);
                }
            }
        P1 = NextW(P1);
    }
	return W;
}

int NbElmtWahana (ListWahana LW) 
/* mengembalikan jumlah elemen yang terdapat pada list wahana*/
{
	//KAMUS
	addWahana P;
	int count;

	//ALGORTIMA
	P = LW;
	count = 0;
	while (P != Nil) {
		count++;
		P = NextW(P);
	}

	return(count);
}

void RandomWahanaRusak (ListWahana *LW)
/*I.S List Wahana bisa kosong */
/*F.S akan dipilih secara acak 1 wahana yg akan dijadikan rusak */
{
	//KAMUS
	int random;
	int BykElmt,i;
	addWahana P1;

	//ALGORITMA
	if (!(IsEmptyListWahana(*LW))){
		BykElmt = NbElmtWahana(*LW);
		random = rand() % (BykElmt);

		P1 = *LW;
		for (i=0;i<random;i++){
			P1 = NextW(P1);
		}
		WahanaRusak(P1) = true;
	} 
	
}

/*
int main(){
	HutanWahana HW;
	ListFileWahana FW;
	int i;

	FileWahanakeArray(&FW);
	PohonWahana(FW,&HW);
	for (i=0;i<=FDeskripsiWahanaLeft(HW,2).Length;i++){
		printf("%c",FDeskripsiWahanaLeft(HW,2).TabKata[i]);
	}
	
	return 0;
}
*/