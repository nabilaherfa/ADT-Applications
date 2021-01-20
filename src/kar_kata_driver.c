#include <stdio.h>
#include "mesinkata.h"

int main() {
    /* KAMUS */
    int i;
    Kata Test;
    /* ALGORITMA */
    STARTKATA();
    i = 0;
    Test = CKata;
    while (i < Test.Length) {
        printf("%c", Test.TabKata[i]);
        i++;
    }
    printf("\n");
    ADVKATA();
    Test = CKata;
    while (i < Test.Length) {
        printf("%c", Test.TabKata[i]);
        i++;
    }
    return 0;
}