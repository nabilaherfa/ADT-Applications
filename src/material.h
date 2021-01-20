/* File : material.h */

#ifndef material_H
#define material_H

#include "boolean.h"
#include "mesinkata.h"

typedef struct {
    Kata Nama;
    int Harga;
} Material;

typedef struct {
    Material List[5]; //Karena banyak material pada txt adalah 5
} ListMaterial;

#define Nama(M) (M).Nama
#define Harga(M) (M).Harga
#define LMaterial(LM,i) (LM).List[i]
#define LMaterialNama(LM,i) (LM).List[i].Nama
#define LMaterialNamaTabKata(LM,i) (LM).List[i].Nama.TabKata
#define LMaterialHarga(LM,i) (LM).List[i].Harga

Kata CharToKata(char Line[]);
/* Mengubah bentuk array of char menjadi Kata */

int CharToInt(char Line[]);
/* Mengubah bentuk array of char menjadi integer */

/* ********* KONSTRUKTOR ********* */
Material MakeMaterial(Kata N,int H);
/* Membuat Material dari input N berupa Nama dan H berupa Harga */

void MakeListMaterial(ListMaterial *LM);
/* I.S. File material.txt terdefinisi */
/* F.S. List material yang ada di material.txt sudah diassign ke LM */

#endif
