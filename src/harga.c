#include <stdio.h>
#include <stdlib.h>
#include "harga.h"

boolean IsHargaValid (int B, int U, int N)
/* Mengirim true  jika H,M,S dapat membentuk H yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Harga */
{
    return ((B>0) && (U>0) && (N>0));
}

/* *** Konstruktor: Membentuk HARGA dari komponen-komponennya *** */
HARGA MakeHARGA (int BB, int UU, int NN)
/* Membentuk HARGA dari komponen-komponennya yang valid */
/* Prekondisi : BB, UU, NN valid untuk membentuk HARGA */
{
    HARGA H1;
    Build (H1) = BB;
    Upgrade (H1) = UU;
    Naik (H1) = NN;
    return H1;
}

void BacaHARGA (HARGA * H)
/* Proses : mengulangi membaca komponen BB, UU, NN sehingga membentuk H */
/* yang valid. Tidak mungkin menghasilkan H yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen BB, UU, NN
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika HARGA tidak valid maka diberikan pesan: "Harga tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang harga. */
/* Contoh:
   -60 3 4
   HARGA tidak valid
   1 3 4
   --> akan terbentuk HARGA <1,3,4> */
{
    int B, U, N;
    scanf("%d %d %d", &B, &U, &N);
    while(!IsHargaValid(B, U, N)){
        printf("Harga tidak valid\n");
        scanf("%d %d %d", &B, &U, &N);
    }
    *H = MakeHARGA(B, U, N);
}

void TulisHARGA (HARGA H)
/* I.S. : H sembarang */
/* F.S. :   Nilai H ditulis dg format HH,MM,SS */
/* Proses : menulis nilai setiap komponen H ke layar dalam format HH,MM,SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll. */
{
    printf("%d,%d,%d", Build(H), Upgrade(H), Naik(H));
}

