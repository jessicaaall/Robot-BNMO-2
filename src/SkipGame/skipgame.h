/* File : skipgame.h */

#ifndef __SKIPGAME_H__
#define __SKIPGAME_H__

#include "../ADT/Queue/queue.h"
#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../PlayGame/playgame.h"

void SKIPGAME(Word n, Queue *q);

//SKIPGAME merupakan command yang digunakan untuk melewatkan permainan sebanyak n.
//I.S. Daftar queue game yang terdefinisi.
//F.S. Daftar queue game yang sudah terskip sebanyak <n> kali.

#endif