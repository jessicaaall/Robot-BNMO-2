/* File: load.h */
/* Definisi spesifikasi load */

#include "../Array/array.h"
#include "../MesinKataKar/mesin_kar.h"
#include "../MesinKataKar/mesin_kata.h"

#ifndef LOAD_H 
#define LOAD_H

void load(char * filename, Tab * loadsave);
/* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
I.S. : filename terdefinisi, Tab kosong
F.S. : Tab loadsave terisi dengan .txt yang bernama filename */

#endif