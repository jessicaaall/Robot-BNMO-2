/* File: load.h */
/* Definisi spesifikasi load */

#include "../ADT/Array/array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "load.h"

#ifndef START_H 
#define START_H

void STARTFILE(Tab *game, Stack *history, TabMap *scoreboard);
/* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
I.S. : filename terdefinisi, Tab kosong
F.S. : Tab loadsave terisi dengan .txt yang bernama filename */

#endif