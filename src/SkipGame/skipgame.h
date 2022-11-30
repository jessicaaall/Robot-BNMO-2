/* File : skipgame.h */

#ifndef __SKIPGAME_H__
#define __SKIPGAME_H__

#include "../ADT/Queue/queue.h"
#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Map/map.h"
#include "../ADT/ArrayofMap/arrayofmap.h"
#include "../ADT/Array/array.h"
#include "../PlayGame/playgame.h"

void SKIPGAME(Word n, Queue *q, TabMap *TM, Tab T);

//SKIPGAME merupakan command yang digunakan untuk melewatkan permainan sebanyak n.
//I.S. Daftar queue game yang terdefinisi.
//F.S. Daftar queue game yang sudah terskip sebanyak <n> kali.

#endif