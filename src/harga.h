/* File : harga.h */
/* contoh ADT harga untuk file tubes */
/* infotype adalah integer */

#ifndef HARGA_H
#define HARGA_H

#include "boolean.h"

/* *** Definisi TYPE HARGA <BB,UU,NN> *** */
typedef struct {
	int BB; /* integer */
	int UU; /* integer */
	int NN; /* integer */
} HARGA;

/* *** Notasi Akses: selektor HARGA *** */
#define Build(H) (H).BB
#define Upgrade(H) (H).UU
#define Naik(H) (H).NN

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

boolean IsHargaValid (int B, int U, int N);
/* Mengirim true  jika B,U,N dapat membentuk H yang valid */
/* dipakai untuk mentest SEBELUM membentuk HARGA */

/* *** Konstruktor: Membentuk HARGA dari komponen-komponennya *** */
HARGA MakeHARGA (int BB, int UU, int NN);
/* Membentuk HARGA dari komponen-komponennya yang valid */
/* Prekondisi : BB, UU, NN valid untuk membentuk HARGA*/

void BacaHARGA (HARGA * H);
/* Proses : mengulangi membaca komponen BB, UU, NN sehingga membentuk H */
/* yang valid. Tidak mungkin menghasilkan H yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen BB, UU, NN
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika HARGA tidak valid maka diberikan pesan: "Harga tidak valid", dan pembacaan
   diulangi hingga didapatkan harga yang valid. */
/* Contoh:
   -60 3 4
   HARGA tidak valid
   1 3 4
   --> akan terbentuk HARGA <1,3,4> */

void TulisHARGA (HARGA H);
/* F.S. :   Nilai H ditulis dg format BB,UU,NN */
/* Proses : menulis nilai setiap komponen H ke layar dalam format BB,UU,NN
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll. */


#endif
