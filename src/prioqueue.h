/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef PrioQueue_H
#define PrioQueue_H

#include "boolean.h"
#include "customer.h"
#include "wahana.h"

#define PrioNil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
    Customer info;  /* elemen karakter */
} ElmtCustomer;

typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    ElmtCustomer * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxElQ;     /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah ElmtCustomer dan Q adalah PrioQueue, maka akses elemen : */
#define Prio(e)     (e).prio
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoHeadSabar(Q) (Q).T[(Q).HEAD].Sabar
#define InfoHeadTabWahana(Q,i) (Q).T[(Q).HEAD].TabWahana[i]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q)    (Q).MaxElQ
#define ElmtQ(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsPrioQueueEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsPrioQueueFull (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBPrioQueueElmt (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakePrioQueueEmpty (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiPrioQueue(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueuePrioQueue (PrioQueue * Q, ElmtCustomer X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void DequeuePrioQueue (PrioQueue * Q, ElmtCustomer * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void ChangePrio(ElmtCustomer *C, int X, boolean Tambah);
/* I.S. Terdapat Customer C yang ingin diubah prioritasnya sebesar X */
/* F.S. Prioritas Customer C diubah */
/* Proses: Jika Tambah true, maka prioritas ditambah */
/* Jika Tambah false, maka prioritas dikurang */

void InisialisasiPrioQueue (PrioQueue *Q, ListWahana LW);
/* I.S. Sembarang */
/* F.S. Terbentuk PrioQueue yang sudah berisi 2 Customer secara acak */

void TambahCustomer (PrioQueue *Q, ListWahana LW);
/* I.S. Terdapat PrioQueue Q yang ingin ditambah Customernya */
/* F.S. Elemen Q bertambah 1, yaitu Customer yang memiliki list wahana yang acak */

#endif