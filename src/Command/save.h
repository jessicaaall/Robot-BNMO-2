/* File: save.h */
/* Definisi spesifikasi save */

#include "../ADT/Array/array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "load.h"

#ifndef SAVE_H 
#define SAVE_H

void SAVE(Word filename, Tab loadsave);
/* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
I.S. : filename terdefinisi, Tab kosong
F.S. : Tab loadsave terisi dengan .txt yang bernama filename */

#endif