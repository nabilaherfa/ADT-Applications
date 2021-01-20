#include "jam.h"
#include <stdio.h>

int main() {
    JAM J;

    J = MakeJAM(23,59,59);

    TulisJAM(J);

    J = NextDetik(J);

    TulisJAM(J);


    return 0;
}