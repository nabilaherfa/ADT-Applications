#include "stdio.h"
#include "player.h"
#include "material.h"
#include "printout.h"
#include "stock.h"
#include "stackt.h"
#include "waktu.h"

#ifndef buy_H
#define buy_H

void PrintNamaMaterial();

boolean CekBuyMaterial(Player P, ListMaterial LM, int material_ke, long WaktuSisa);
/* Mengecek apakah uang player cukup untuk membeli material */

void PushBuy(Player *P, Kata Material, Stack *S, int jumlah_material);
/* Menambahkan Aksi Buy ke dalam Stack jika CekBuyMaterial bernilai true */

void BuyMaterial(Player *P, ListMaterial LM, long *WaktuSisa, int jumlah_material, Aksi X);
/* Melakukan eksekusi buy material setelah pengecekan dilakukan */

#endif