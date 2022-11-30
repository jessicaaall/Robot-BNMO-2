#include <stdio.h>
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Map/map.h"
#include "../ADT/ArrayOfMap/arrayofmap.h"
#include "../ADT/Array/Array.h"

#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

void INSERTSCOREBOARD (int score, TabMap *TM, int idx);

void SCOREBOARD (TabMap TM,Tab T);

void RESETSCOREBOARD (Tab T, TabMap *TM);

#endif