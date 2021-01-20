#include "matriks.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    MATRIKS M;
    MakeMATRIKS(2,3,&M);

    BacaMATRIKS(&M,2,3);

    TulisMATRIKS(M);

    return 0;

}
