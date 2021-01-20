#include <stdio.h>
#include <stdlib.h>
#include "arraypos.c"

int main() {
    //KAMUS
    TabInt T,T1,T2;
    ElType max,min,X;
    int count;

    //ALGORITMA

    BacaIsi(&T);
    TulisIsiTab(T);
    
    BacaIsi(&T1);
    
    T2 = PlusMinusTab(T,T1,true);
    TulisIsiTab(T2);
    
    if (IsEQ(T,T2)){
    	printf("T dan T2 ekivalen\n");
	} else {
		printf("T dan T2 tidak ekivalen\n");
	}
	
	if (SearchB(T,3)) {
		printf("Angka 3 terdapat pada T");
	} else {
		printf("Angka 3 tidak terdapat pada T");
	}
	
	MaxMin(T,&max,&min);
	printf("max : %d\n", max);
	printf("min : %d\n", min);
	
	count = CountX(T,1);
	printf("Terdapat %d angka 1 pada T\n", count);
	
	if (IsAllGenap(T1)){
		printf("Semua elemen T1 genap\n");
	} else {
		printf("Semua elemen T1 tidak genap\n");
	}
	
	Sort(&T2,true);
	
	AddAsLastEl(&T1,2);
	DelLastEl(&T1,&X);
    return 0;
}
