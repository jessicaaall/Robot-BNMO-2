/* File : playgame.h */

#ifndef PLAYGAME_H
#define PLAYGAME_H

#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/ArrayofMap/arrayofmap.h"
#include "../ADT/Map/map.h"
#include "../ADT/Array/array.h"
#include "../RNGgame/rnggame.h"
#include "../DinerDash/diner_dash.h"
#include "../Hangman/hangman.h"
#include "../TowerOfHanoi/towerofhanoi.h"
#include "../SkorGame/skorgame.h"
#include "../boolean.h"
#include "../Scoreboard/scoreboard.h"

void PLAYGAME(Queue *queuegame, TabMap *TM, Tab T);
/*
I.S. Daftar antrian game terdefinisi
F.S. Game pertama pada daftar antrian game dimainkan
*/

#endif