#include <stdio.h>
#include "../ADT/Array/Array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Map/map.h"
#include "../ADT/ArrayOfMap/arrayofmap.h"

#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

void INSERTSCOREBOARD (int score, TabMap *TM, int idx);
/* Proses : Meminta input nama sampai input nama belum terdapat dalam key pada Elmt ke-idx
            Menambahkan key berupa nama dan value berupa score ke dalam TabMap TM Elmt ke-idx */
/* I.S. score terdefinisi, idx terdefinisi, TabMap terdefinisi */
/* F.S. TabMap pada Elmt ke-idx mengandung key berupa input nama dan value berupa score */

void DISPLAYSCOREBOARD(TabMap TM, Tab T);
/* Menampilkan scoreboard untuk setiap game */
/* I.S. TabMap TM yang merupakan daftar scoreboard setiap game terdefinisi
        Tab T yang merupakan daftar game terdefinisi */
/* F.S. Menampilkan scoreboard untuk setiap game */

void RESETSCOREBOARD (Tab T, TabMap *TM);
/* Proses : Menampilkan daftar scoreboard
            Meminta input nomor scoreboard yang ingin dihapus sampai valid 
            Menghapus scoreboard yang ingin dihapus pada TabMap TM */
/* I.S. TabMap TM yang merupakan daftar scoreboard terdefinisi 
        Tab T yang merupakan daftar game terdefinisi */
/* F.S. Menghapus scoreboard dari daftar scoreboard pada TabMap TM berdasarkan input nomor scoreboard */

#endif