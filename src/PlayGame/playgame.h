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
#include "../SnakeOnMeteor/snakeonmeteor.h"
#include "../SkorGame/skorgame.h"
#include "../boolean.h"
#include "../Scoreboard/scoreboard.h"
#include "../History/history.h"

void PLAYGAME(Queue *queuegame, TabMap *TM, Tab T, Stack *S);
/*
I.S. Queue queuegame yang merupakan daftar antrian game terdefinisi
     TabMap TM yang merupakan daftar scoreboard terdefinisi
     Stack S yang merupakan daftar history game terdefinisi 
F.S. Game pertama pada daftar antrian game dimainkan
     Daftar scoreboard bertambah untuk game yang dimainkan
     Daftar history game bertambah
*/

#endif