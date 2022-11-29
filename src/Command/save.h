/* File: save.h */
/* Definisi spesifikasi save */

#ifndef SAVE_H 
#define SAVE_H

#include "../ADT/Array/array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/ArrayOfMap/arrayofmap.h"
#include "load.h"


void SAVE(Word filename, Tab game, Stack history, TabMap scoreboard);
/* Menyimpan isi Tab game, Stack history, dan TabMap scoreboard ke dalam filename.txt */
/* I.S. Filename terdefinisi, Tab game terdefinisi, Stack history terdefinisi, TabMap scoreboard terdefinisi */
/* F.S. Filename.txt berisi daftar game, history game, dan scoreboard untuk setiap game */

#endif