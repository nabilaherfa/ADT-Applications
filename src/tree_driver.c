#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main() {
    //KAMUS
    BinTree P;
    infoW X;
    int Bykdaun, Bykelmt;


    //ALGORITMA
    P = Nil;

    if (IsTreeEmpty(P)){
        printf("pohon kosong\n");
    } else {
        printf("pohon tidak kosong");
    }

    Bykdaun = NbDaun(P);
    Bykelmt = NbElmtTree(P);
    printf("%d\n", Bykdaun);
    printf("%d\n", Bykelmt);
    
    if (IsOneElmtTree(P)){
        printf("pohon memiliki 1 elemen\n");
    } else {
        printf("pohon tidak memiliki 1 elemen\n");
    }

    if (IsUnerLeft(P)){
        printf("P adalah pohon unerleft\n");
    } else {
        printf("P bukan pohon unerleft\n");
    }

    if (IsUnerRight(P)){
        printf("P adalah pohon unerright\n");
    } else {
        printf("P bukan pohon unerright\n");
    }

    if (IsBiner(P)){
        printf("P adalah pohon biner\n");
    } else {
        printf("P bukan pohon biner\n");
    }

    

    return 0;
}