#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "build.h"
#include "buy.h"
#include "exit.h"
#include "jam.h"
#include "main_execute.h"
#include "new.h"
#include "office_detail.h"
#include "player.h"
#include "prepare.h"
#include "prioqueue.h"
#include "repair.h"
#include "serve.h"
#include "undo.h"
#include "upgrade.h"
#include "wahana.h"
#include "waktu.h"
#include "wasd.h"


int main() {
    /* KAMUS */
    int day = 1, MaxPengunjung = 20;
    boolean play;
    Stack ST;
    Player P;
    JAM CU, OP, CL;
    WAKTU WT;
    PrioQueue Q;
    ListMaterial LM;
    ListFileWahana FW;
    HutanWahana HW;
    ListWahana LW;
    STOCK TabStock[3];
    MATRIKS M1, M2, M3, M4;
    Kata new, exit, w, a, s, d;
    Kata build, upgrade, buy, undo, execute, main;
    Kata serve, repair, detail, office, prepare;
    char input[20];
    Kata WKata, WMat, NamaP;
    /* ALGORITMA */
    //Simpan kata input pengguna
    new.Length = 3;
    new.TabKata[0] = 'n';
    new.TabKata[1] = 'e';
    new.TabKata[2] = 'w';
    exit.Length = 4;
    exit.TabKata[0] = 'e';
    exit.TabKata[1] = 'x';
    exit.TabKata[2] = 'i';
    exit.TabKata[3] = 't';
    w.Length = 1;
    w.TabKata[0] = 'w';
    a.Length = 1;
    a.TabKata[0] = 'a';
    s.Length = 1;
    s.TabKata[0] = 's';
    d.Length = 1;
    d.TabKata[0] = 'd';
    build.Length = 5;
    build.TabKata[0] = 'b';
    build.TabKata[1] = 'u';
    build.TabKata[2] = 'i';
    build.TabKata[3] = 'l';
    build.TabKata[4] = 'd';
    upgrade.Length = 7;
    upgrade.TabKata[0] = 'u';
    upgrade.TabKata[1] = 'p';
    upgrade.TabKata[2] = 'g';
    upgrade.TabKata[3] = 'r';
    upgrade.TabKata[4] = 'a';
    upgrade.TabKata[5] = 'd';
    upgrade.TabKata[6] = 'e';
    buy.Length = 3;
    buy.TabKata[0] = 'b';
    buy.TabKata[1] = 'u';
    buy.TabKata[2] = 'y';
    undo.Length = 4;
    undo.TabKata[0] = 'u';
    undo.TabKata[1] = 'n';
    undo.TabKata[2] = 'd';
    undo.TabKata[3] = 'o';
    execute.Length = 7;
    execute.TabKata[0] = 'e';
    execute.TabKata[1] = 'x';
    execute.TabKata[2] = 'e';
    execute.TabKata[3] = 'c';
    execute.TabKata[4] = 'u';
    execute.TabKata[5] = 't';
    execute.TabKata[6] = 'e';
    main.Length = 4;
    main.TabKata[0] = 'm';
    main.TabKata[1] = 'a';
    main.TabKata[2] = 'i';
    main.TabKata[3] = 'n';
    serve.Length = 5;
    serve.TabKata[0] = 's';
    serve.TabKata[1] = 'e';
    serve.TabKata[2] = 'r';
    serve.TabKata[3] = 'v';
    serve.TabKata[4] = 'e';
    repair.Length = 6;
    repair.TabKata[0] = 'r';
    repair.TabKata[1] = 'e';
    repair.TabKata[2] = 'p';
    repair.TabKata[3] = 'a';
    repair.TabKata[4] = 'i';
    repair.TabKata[5] = 'r';
    detail.Length = 6;
    detail.TabKata[0] = 'd';
    detail.TabKata[1] = 'e';
    detail.TabKata[2] = 't';
    detail.TabKata[3] = 'a';
    detail.TabKata[4] = 'i';
    detail.TabKata[5] = 'l';
    office.Length = 6;
    office.TabKata[0] = 'o';
    office.TabKata[1] = 'f';
    office.TabKata[2] = 'f';
    office.TabKata[3] = 'i';
    office.TabKata[4] = 'c';
    office.TabKata[5] = 'e';
    prepare.Length = 7;
    prepare.TabKata[0] = 'p';
    prepare.TabKata[1] = 'r';
    prepare.TabKata[2] = 'e';
    prepare.TabKata[3] = 'p';
    prepare.TabKata[4] = 'a';
    prepare.TabKata[5] = 'r';
    prepare.TabKata[6] = 'e';

    //Mengisi Variabel
    MakeListMaterial(&LM);
    FileWahanakeArray(&FW);
    PohonWahana(FW,&HW);
    CreateEmptyListWahana(&LW);

    //Mengisi matriks dengan map
    BacaMAP1(&M1);
    BacaMAP2(&M2);
    BacaMAP3(&M3);
    BacaMAP4(&M4);

    //Buat Type waktu
    CU = MakeJAM(21,0,0);
    OP = MakeJAM(9,0,0);
    CL = MakeJAM(21,0,0);
    WT = MakeWAKTU(CU,OP,CL,43200);

    //Sambutan
    printTitleGame();

    scanf("%s", input);
    //Input pertama
    while (input != "new")
    {
        printf("Anda belum memulai permainan!");
        scanf("%s", input);
    }
    play = true;
    while(play) {
        if (input=="new")
        {
            printNewGame();
            STARTKATA();
            NamaP = CKata;
            NewGame(&P);
        }
        else if (input=="exit")
        {
            Exit();
            play = false;
        }
        else if (input=="w")
        {
            W(P);
        }
        else if (input=="a")
        {
            A(P);
        }
        else if (input=="s")
        {
            S(P);
        }
        else if (input=="d")
        {
            D(P);
        }
        else if (input=="build")
        {
            int wahana_ke;
            PrintNamaWahana();
            scanf("%d", &wahana_ke);
            CekResourceWahana(P,HW,wahana_ke,Remain(WT));
            PushBuild(&P,WKata,&ST);
        }
        else if (input=="upgrade")
        {
            int i, Cabang;
            i = PrintUpgradeList(P,LW,HW);
            scanf("%d", &Cabang);
            CekUpgrade(P,HW,LW,Cabang,Remain(WT));
            PushUpgrade(WKata,i,Cabang,&ST);
        }
        else if (input=="buy")
        {
            int material_ke;
            int jumlah_material;
            PrintNamaMaterial();
            scanf("%d", &material_ke);
            scanf("%d", &jumlah_material);
            CekBuyMaterial(P,LM,material_ke,Remain(WT));
            PushBuy(&P,WMat,&ST,jumlah_material);
        }
        else if (input=="undo")
        {
            Aksi X;
            UndoAksi(&ST,&X);
        }
        else if (input=="execute")
        {
            int MPlayer;
            MPlayer = GetMap(P);
            if (MPlayer == 1) {
                Execute(&P,&ST,day,LM,&Remain(WT),&LW,HW,&M1,&WT,Q,M1,M2,M3,M4);
            }
            else if (MPlayer == 2) {
                Execute(&P,&ST,day,LM,&Remain(WT),&LW,HW,&M2,&WT,Q,M1,M2,M3,M4);
            }
            else if (MPlayer == 3) {
                Execute(&P,&ST,day,LM,&Remain(WT),&LW,HW,&M3,&WT,Q,M1,M2,M3,M4);
            }
            else if (MPlayer == 4) {
                Execute(&P,&ST,day,LM,&Remain(WT),&LW,HW,&M4,&WT,Q,M1,M2,M3,M4);
            }
        }
        else if (input=="main")
        {
            Main(&P,&ST,day,&LW,&WT,Q,M1,M2,M3,M4);
        }
        else if (input=="serve")
        {
            Wahana Ww;
            Serve (Ww,Q,WT);
        }
        else if (input=="repair")
        {
            RepairWahana(P,LW,&Remain(WT));
        }
        else if (input=="detail")
        {
            Detail(P,LW);
        }
        else if (input=="office")
        {
            Office(P,LW);
        }
        else if (input=="prepare")
        {
            Prepare(&P,&Q,MaxPengunjung,&LW,&WT);
        }
        scanf("%s", input);
    }
    return 0;
}