#include "stackt.h"
#include "stdio.h"

int main() {
    Stack S;

    CreateEmptyStack(&S);

    if (IsEmptyStack(S)) printf("Stack kosong\n");

    Aksi X;

    X.CAksi = 'D';
    X.N1 = 2;
    X.N2 = 2;
    X.NamaKata.TabKata[0] = 'H';
    X.NamaKata.TabKata[1] = 'A';
    X.NamaKata.TabKata[2] = 'L';
    X.NamaKata.TabKata[3] = 'O';
    X.NamaKata.TabKata[4] = 'L';
    X.NamaKata.TabKata[5] = 'i';
    X.NamaKata.TabKata[6] = 'n';
    X.NamaKata.TabKata[7] = 't';
    X.NamaKata.TabKata[8] = 'a';
    X.NamaKata.TabKata[9] = 'r';
    X.NamaKata.Length = 10;

    Push(&S,X);

    printf("(%d,%d)",X.N1,X.N2);

    if (!IsEmptyStack(S)) printf("Stack tidak kosong\n");
    return 0;
}