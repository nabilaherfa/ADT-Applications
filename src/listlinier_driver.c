#include <stdio.h>
#include <stdlib.h>
#include "listlinier.c"

int main() {
    //KAMUS
    List L;
    infotype X,X1,X2,X3;
    address P,P1,P2,P3,P4;
    int M, min, max;

    //ALGORITMA
    CreateEmpty(&L);
    if (IsEmpty(L)){
        printf("List Kosong\n");
    } else {
        printf("List Tidak Kosong\n");
    }
    
    X1 = 2;
    P1 = Alokasi(X1);
    Dealokasi(&P1);

    InsVFirst(&L,1);
    InsVLast(&L,2);

    M = NbElmt(L);
    printf("%d\n", M);

    DelVFirst(&L,&X);
    printf("%d\n", X);
    DelVLast(&L,&X);
    printf("%d\n", X);

    X2=3;
    X3=4;
    P1 = Alokasi(X1);
    P2 = Alokasi(X2);
    P3 = Alokasi(X3);
    P4 = Alokasi(5);

    InsertFirst(&L,P1);
    InsertAfter(&L,P2,P1);
    InsertLast(&L,P3);
    InsertLast(&L,P4);

    PrintInfo(L);

    min = Min(L);
    max = Max(L);

    printf("min : %d\n", min);
    printf("max : %d\n", max);

    DelFirst(&L,&P);
    printf("%d\n", P->info);
    DelP(&L,3);
    DelLast(&L,&P);
    printf("%d\n", P->info);

    return 0;
}