/* file: wasd.c */
/* untuk memindah */

#include "wasd.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsPagar (Player P, char C)
/* i.s. posisi pada posisi awal */ 
/* f.s. jika player berpindah sebanyak 1 ke kanan 
    atau kiri atau atas atau bawah dan ternyata menuju pagar,  
    fungsi akan mengirim true. kalau bukan pagar false */
{
    int x,y,x1,y1;

    x = Absis(Posisi(P)) + 1 ;
    x1 = Absis(Posisi(P)) - 1 ;
    y = Ordinat(Posisi(P)) + 1;
    y1 = Ordinat(Posisi(P)) - 1;

    MATRIKS M1,M2,M3,M4;
    BacaMAP1(&M1);
    BacaMAP2(&M2);
    BacaMAP3(&M3);
    BacaMAP4(&M4);

    if(C = 'w')
    {
        if((Map(P) == 1) && (GetElementMAP(M1,Absis(Posisi(P)),y1) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 2) &&(GetElementMAP(M2,Absis(Posisi(P)),y1) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 3) &&(GetElementMAP(M3,Absis(Posisi(P)),y1) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 4) &&(GetElementMAP(M4,Absis(Posisi(P)),y1) == '*'))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    
    else if(C = 'a')
    {
        if((Map(P) == 1) && (GetElementMAP(M1,x1,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 2) && (GetElementMAP(M2,x1,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 3) && (GetElementMAP(M3,x1,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 4) && (GetElementMAP(M4,x1,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
        
    else if(C = 'd')
    {
        if((Map(P) == 1) && (GetElementMAP(M1,x,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 2) && (GetElementMAP(M2,x,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 3) && (GetElementMAP(M3,x,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 4) && (GetElementMAP(M4,x,Ordinat(Posisi(P))) == '*'))
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    else if(C = 's')
    {
        if((Map(P) == 1) && (GetElementMAP(M1,Absis(Posisi(P)),y) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 2) &&(GetElementMAP(M2,Absis(Posisi(P)),y) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 3) &&(GetElementMAP(M3,Absis(Posisi(P)),y) == '*'))
        {
            return true;
        }
        else if ((Map(P) == 4) &&(GetElementMAP(M4,Absis(Posisi(P)),y) == '*'))
        {
            return true;
        }
        else
        {
            return false;
        }

    }

}

boolean IsGerbang(Player P,char C)
{
    int x,y,x1,y1;

    x = Absis(Posisi(P)) + 1 ;
    x1 = Absis(Posisi(P)) - 1 ;
    y = Ordinat(Posisi(P)) + 1;
    y1 = Ordinat(Posisi(P)) - 1;

    MATRIKS M1,M2,M3,M4;
    BacaMAP1(&M1);
    BacaMAP2(&M2);
    BacaMAP3(&M3);
    BacaMAP4(&M4);

    if(Map(P) == 1)
    {
        if((GetElementMAP(M1,x,Ordinat(Posisi(P))) == '>') && (C == 'd'))
        {
            return true;
            /*Map(P) = 2;
            Absis(Posisi(P)) = 1;
            Ordinat(Posisi(P)) = 6;*/
        }
        else if ((GetElementMAP(M1,Absis(Posisi(P)),y) == 'v' ) && (C == 's'))
        {
            return true;
            /*Map(P) = 3;
            Absis(Posisi(P)) = 4;
            Ordinat(Posisi(P)) = 1;*/
        }
        else
        {
            return false;
        }
        
    }
    else if (Map(P) == 2)
    {
        if((GetElementMAP(M2,x1,Ordinat(Posisi(P))) == '<') && (C == 'a'))
        {
            return true;
            /*Map(P) = 1;
            Absis(Posisi(P)) = 18
            Ordinat(Posisi(P)) = 4*/
        }
        else if((GetElementMAP(M2,Absis(Posisi(P)),y) == 'v') && (C == 's'))
        {
            return true;
            /*Map(P) = 4;
            Absis(Posisi(P)) = 15
            Ordinat(Posisi(P)) = 1*/
        }
        else
        {
            return false;
        }
        
    }

    else if(Map(P) == 4)
    {
        if((GetElementMAP(M4,x1,Ordinat(Posisi(P))) == '<') && (C == 'a'))
        {
            return true;
            /*Map(P) = 3;
            Absis(Posisi(P)) = 18
            Ordinat(Posisi(P)) = 3*/
        }
        else if((GetElementMAP(M4,Absis(Posisi(P)),y1) == '^') && (C == 'w'))
        {
            return true;
            /*Map(P) = 2;
            Absis(Posisi(P)) = 11
            Ordinat(Posisi(P)) = 8*/
        } 
        else
        {
            return false;
        }
        
    }
    else if (Map(P) == 3)
    {
        if((GetElementMAP(M3,x,Ordinat(Posisi(P))) == '>') && (C == 'd'))
        {
            return true;
            /*Map(P) = 4;
            Absis(Posisi(P)) = 1
            Ordinat(Posisi(P)) = 7*/
        }
        else if((GetElementMAP(M3,Absis(Posisi(P)),y) =='^') && (C == 'w'))
        {
            return true;
            /*Map(P) = 1;
            Absis(Posisi(P)) = 6
            Ordinat(Posisi(P)) = 8*/
        }
        else
        {
            return false;
        }
        
    }

}

void posisisebelum(Player P)
{
    POINT posisilama;
    Ordinat(posisilama) = Ordinat(Posisi(P));
    Absis(posisilama) = Absis(Posisi(P));

    if (Map(P) == 1)
    {
        MATRIKS *M;
        BacaMAP1(M);
        Elmt(*M,Absis(posisilama),Ordinat(posisilama))= '-';
    }
    else if (Map(P) == 2)
    {
        MATRIKS *M;
        BacaMAP2(M);
        Elmt(*M,Absis(posisilama),Ordinat(posisilama))= '-';
    }
    else if (Map(P) == 3)
    {
        MATRIKS *M;
        BacaMAP3(M);
        Elmt(*M,Absis(posisilama),Ordinat(posisilama))= '-';
    }
    else if (Map(P) == 4)
    {
        MATRIKS *M;
        BacaMAP4(M);
        Elmt(*M,Absis(posisilama),Ordinat(posisilama))= '-';
    }
    
}

void posisisetelah(Player P)
{
    if(Map(P) == 1)
    {
        MATRIKS *M;
        BacaMAP1(M);
        Elmt(*M,Absis(Posisi(P)),Ordinat(Posisi(P)))= 'P';
    }
    else if(Map(P) == 2)
    {
        MATRIKS *M;
        BacaMAP2(M);
        Elmt(*M,Absis(Posisi(P)),Ordinat(Posisi(P)))= 'P';
    }
    else if(Map(P) == 3)
    {
        MATRIKS *M;
        BacaMAP3(M);
        Elmt(*M,Absis(Posisi(P)),Ordinat(Posisi(P)))= 'P';
    }
    else if(Map(P) == 4)
    {
        MATRIKS *M;
        BacaMAP4(M);
        Elmt(*M,Absis(Posisi(P)),Ordinat(Posisi(P)))= 'P';
    }
}

void W (Player P)
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke atas */
{
    if(!IsGerbang(P,'w') && !IsPagar(P,'w'))
    {   
        posisisebelum(P);

        Ordinat(Posisi(P)) -= 1;

        posisisetelah(P);
    }
    else if(IsGerbang(P,'w'))
    {
        if(Map(P) == 3)
        {
            posisisebelum(P);

            Map(P) = 1;
            Absis(Posisi(P)) = 6;
            Ordinat(Posisi(P)) = 8;

            posisisetelah(P);
        }
        else if(Map(P) == 4)
        {
            posisisebelum(P);

            Map(P) = 2;
            Absis(Posisi(P)) = 11;
            Ordinat(Posisi(P)) = 8;

            posisisetelah(P);
        }
    }
    else if(IsPagar(P,'w'))
    {
        printf("Kamu bergerak menuju pagar !\n");
    }
    
}

void A (Player P)
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke kiri */
{
    if((!IsGerbang(P,'a')) && (!IsPagar(P,'a')))
    {
        posisisebelum(P);

        Ordinat(Posisi(P)) -= 1;
    
        posisisetelah(P);

    }
    else if(IsGerbang(P,'a'))
    {
        if(Map(P) == 2)
        {
            posisisebelum(P);

            Map(P) = 1;
            Absis(Posisi(P)) = 18;
            Ordinat(Posisi(P)) = 4;

            posisisetelah(P);

        }
        else if(Map(P) == 4)
        {
            posisisebelum(P);

            Map(P) = 3;
            Absis(Posisi(P)) = 18;
            Ordinat(Posisi(P)) = 3;

            posisisetelah(P);
        }
    }
    else if(IsPagar(P,'a'))
    {
        printf("Kamu bergerak menuju pagar !\n");
    }
}

void S (Player P)
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke bawah */
{
    if(!IsGerbang(P,'s') && !IsPagar(P,'s'))
    {
        posisisebelum(P);

        Ordinat(Posisi(P)) -= 1;

        posisisetelah(P);

    }
    else if(IsGerbang(P,'s'))
    {
        if(Map(P) == 1)
        {
            posisisebelum(P);

            Map(P) = 3;
            Absis(Posisi(P)) = 4;
            Ordinat(Posisi(P)) = 1;

            posisisetelah(P);
        }
        else if(Map(P) == 2)
        {
            posisisebelum(P);

            Map(P) = 4;
            Absis(Posisi(P)) = 15;
            Ordinat(Posisi(P)) = 1;

            posisisetelah(P);
        }
    }
    else if(IsPagar(P,'s'))
    {
        printf("Kamu bergerak menuju pagar !\n");
    }
}

void D (Player P)
/* i.s. posisi pada posisi semula */
/* f.s. player pindah posisi sebanyak 1 ke kanan */
{
    if(!IsGerbang(P,'d') && !IsPagar(P,'d'))
    {
        posisisebelum(P);

        Ordinat(Posisi(P)) -= 1;

        posisisetelah(P);
    }
    else if(IsGerbang(P,'d'))
    {
        if(Map(P) == 1)
        {
            posisisebelum(P);

            Map(P) = 2;
            Absis(Posisi(P)) = 1;
            Ordinat(Posisi(P)) = 6;

            posisisetelah(P);
        }
        else if(Map(P) == 3)
        {
            posisisebelum(P);

            Map(P) = 4;
            Absis(Posisi(P)) = 1;
            Ordinat(Posisi(P)) = 7;

            posisisetelah(P);
        }
    }
    else if(IsPagar(P,'d'))
    {
        printf("Kamu bergerak menuju pagar !\n");
    }
}

// int main(){
//     Player P;
//     POINT posisisekarang;
//     MATRIKS M1;


//     Map(P) = 1;
//     posisisekarang = SearchElement(M1,'P');
//     Absis(Posisi(P)) = Absis(posisisekarang);
//     Ordinat(Posisi(P)) = Ordinat(posisisekarang);

    
//     BacaMAP1(&M1);
//     d(P);
//     TulisMATRIKS(M1);
// }

/* Driver wasd */
/*int main(){  
    Player P;
    char inputuser;
    POINT posisisekarang;

    MATRIKS M1,M2,M3,M4;
    BacaMAP1(&M1);
    BacaMAP2(&M2);
    BacaMAP3(&M3);
    BacaMAP4(&M4);

    Map(P) = 1;
    posisisekarang = SearchElement(M1,'P');
    Absis(Posisi(P)) = Absis(posisisekarang);
    Ordinat(Posisi(P)) = Ordinat(posisisekarang);

    scanf("%c",&inputuser);

    if(inputuser == 'a')
    {
        TulisMAP1();
    }
    return 0;
}*/

