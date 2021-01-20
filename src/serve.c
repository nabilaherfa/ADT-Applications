/* serve.c */

#include "serve.h"
#include <stdlib.h>
#include <stdio.h>

void Serve (Wahana W, PrioQueue Q, WAKTU J)
/* i.s. */
/* f.s. */
{   
    /* ngisi wahana dengan customer */
    /* serve terus sebelum antrian nyampe tail ato waktu abis*/
    int i = 1;
    boolean katasama;
    katasama = false;

    for(i;i<=3;i++)
    {
        if(IsKataSama(InfoHead(Q).info.TabWahana[i],Nama(W)))
        {
            katasama = true;
            break;
        }
    }

    if(katasama)
    {
        if ((!IsPrioQueueEmpty(Q)) && (Remain(J) > 20) && (Isi(W) != Kap(W)))
        {
            ElmtCustomer Temp;

            DequeuePrioQueue(&Q, &Temp);
            Isi(W) += 1;
            Penghasilan(W) += Harga(W);
            PenghasilanHariIni(W) += Harga(W);
            Naik(W) += 1;
            NaikHariIni(W) += 1;

            Remain(J) -= 20;
        }
        /* kalo udah terisi penuh */
        else
        {
            printf("Maaf, sudah tidak bisa serve lagi untuk wahana ini. ");
        }
    }
    else
    {
        printf("Maaf customer tidak ingin naik wahana ini.");
    }
    
    
    

}