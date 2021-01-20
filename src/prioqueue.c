/*
NIM: 13519013
Nama: Rahmah Khoirussyifa' Nurdini
Tanggal: 8 Oktober 2020
Topik: Praktikum 7
Deskripsi: Realisasi dari PrioQueue.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* ********* Prototype ********* */
boolean IsPrioQueueEmpty (PrioQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    // ALGORTIMA
    return ((Head(Q) == PrioNil) && (Tail(Q) == PrioNil));
}

boolean IsPrioQueueFull (PrioQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    // ALGORTIMA    
    return ((Tail(Q)+1) % MaxElQ(Q) == Head(Q));
}

int NBPrioQueueElmt (PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    // ALGORTIMA
    if (IsPrioQueueEmpty(Q)) {
        return 0;
    }
    else {
        return (((Tail(Q) - Head(Q) + MaxElQ(Q)) % MaxElQ(Q)) + 1);
    }
}

/* *** Kreator *** */
void MakePrioQueueEmpty (PrioQueue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    // KAMUS
    PrioQueue Qtemp;

    // ALGORTIMA
    Qtemp.T = (ElmtCustomer * ) malloc (Max * sizeof(ElmtCustomer));

    if ((Qtemp.T) == NULL) MaxElQ(Qtemp) = 0;
    else MaxElQ(Qtemp) = Max;

    Head(Qtemp) = PrioNil;
    Tail(Qtemp) = PrioNil;
    *Q = Qtemp;
}

/* *** Destruktor *** */
void DeAlokasiPrioQueue(PrioQueue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    // ALGORTIMA
    MaxElQ(*Q) = 0;
    Head(*Q) = PrioNil;
    Tail(*Q) = PrioNil;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void EnqueuePrioQueue (PrioQueue * Q, ElmtCustomer X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    // KAMUS
    int i, j;
    boolean add = true;

    // ALGORITMA
    if (IsPrioQueueEmpty(*Q)) {
        Head(*Q) = 0;
    }
    Tail(*Q) = (Tail(*Q)+1) % MaxElQ(*Q);
    InfoTail(*Q) = X;

    int lastidx = Tail(*Q);

    while (add && i != Head(*Q)) {
        if (i == 0) {
            j = MaxElQ(*Q);
        }
        else {
            j = i-1;
        }

        if (Prio(ElmtQ(*Q,j)) >= Prio(ElmtQ(*Q,i))) {
            // menukar2 elemen
            ElmtCustomer temp = ElmtQ(*Q,i);
            ElmtQ(*Q,i) = ElmtQ(*Q,j);
            ElmtQ(*Q,j) = temp;
        }
        else {
            add = false;
        }

        i = j;
    }
}

void DequeuePrioQueue (PrioQueue * Q, ElmtCustomer * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = PrioNilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    // ALGORTIMA
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = PrioNil;
        Tail(*Q) = PrioNil;
    }
    else {
        Head(*Q) = (Head(*Q)+1) % MaxElQ(*Q);
    }
}

/* Operasi Tambahan */
void ChangePrio(ElmtCustomer *C, int X, boolean Tambah)
/* I.S. Terdapat Customer C yang ingin diubah prioritasnya sebesar X */
/* F.S. Prioritas Customer C diubah */
/* Proses: Jika Tambah true, maka prioritas ditambah */
/* Jika Tambah false, maka prioritas dikurang */
{
    //KAMUS LOKAL

    //ALGORTIMA
    if (Tambah) Prio(*C) += X;
    else Prio(*C) -= X;
}

void InisialisasiPrioQueue (PrioQueue *Q, ListWahana LW)
/* I.S. Sembarang */
/* F.S. Terbentuk PrioQueue yang sudah berisi 2 Customer secara acak */
{
    //KAMUS LOKAL
    int random1, random2;
    int N;
    ListWahana LW1 = LW, LW2 = LW;
    addWahana P;

    //ALGORITMA
    for (int i=0; i<2; i++) {
        if (!IsEmptyListWahana(LW)) {
            N = NbElmtWahana(LW);
            random1 = rand() % N;

            ElmtCustomer C;
            C.info.Sabar = 5;

            do
            {
                random2 = rand() % N;
            } while (random1 != random2);

            for (int j=0; j<random1; j++) {
                DelFirstWahana(&LW1,&P);
            }
            C.info.TabWahana[0] = NamaWahana(P);

            for (int k=0; k<random1; k++) {
                DelFirstWahana(&LW2,&P);
            }
            C.info.TabWahana[1] = NamaWahana(P);

            C.prio = (i+1);
            EnqueuePrioQueue(Q,C);
        }
    }
}

void TambahCustomer (PrioQueue *Q, ListWahana LW)
{
    //KAMUS LOKAL
    int random1, random2;
    int N;
    ListWahana LW1 = LW, LW2 = LW;
    addWahana P;

    //ALGORITMA
    if (!IsEmptyListWahana(LW)) {
        N = NbElmtWahana(LW);

        //Mendapatkan random number untuk wahana #1 yg ingin dinaiki
        random1 = rand() % N;

        ElmtCustomer C;
        C.info.Sabar = 5;

        //Mendapatkan random number untuk wahana #2 yg ingin dinaiki
        do
        {
            random2 = rand() % N;
        } while (random1 != random2);

        //Mendapatkan nama wahana #1
        for (int j=0; j<random1; j++) {
            DelFirstWahana(&LW1,&P);
        }
        C.info.TabWahana[0] = NamaWahana(P);

        //Mendapatkan nama wahana #2
        for (int k=0; k<random1; k++) {
            DelFirstWahana(&LW2,&P);
        }
        C.info.TabWahana[1] = NamaWahana(P);

        //Mengassign prioritas di paling belakang
        C.prio = NBPrioQueueElmt(*Q);
        EnqueuePrioQueue(Q,C);
    }  
}

/*
int main() {

    PrioQueue Q;

    InisialisasiPrioQueue(&Q);

    printf("Kesabaran C pertama = %d\n", InfoHead(Q).prio);
    printf("Ayo diprint\n");


    return 0;
}
*/