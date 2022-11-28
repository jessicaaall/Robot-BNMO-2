/* File: load.h */
/* Definisi spesifikasi load */

#include "../ADT/Array/array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/Map/map.h"
#include "../ADT/ArrayOfMap/arrayofmap.h"

#ifndef LOAD_H 
#define LOAD_H

void LOAD(char *filename, Tab *game, Stack *history, TabMap *scoreboard);
/* Proses : Membuka filename.txt 
            Menyimpan isi filename.txt yang berupa daftar permainan ke Tab game 
            Menyimpan isi filename.txt yang berupa daftar history permainan ke Stack history 
            Menyimpan isi filename.txt yang berupa daftar scoreboard permainan ke TabMap scoreboard */
/* I.S. filename terdefinisi */
/* F.S. Tab game berisi daftar permainan yang terdapat dalam filename.txt
        Stack history berisi daftar history permainan yang terdapat dalam filename.txt
        TabMap scoreboard berisi daftar scoreboard permainan yang terdapat dalam filename.txt */

#endif