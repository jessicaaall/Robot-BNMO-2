#include <stdio.h>
#include "../ADT/Stack/stack.h"
#include "../ADT/MesinKata/mesinkata.h"

#ifndef __HISTORY_H__
#define __HISTORY_H__

void insertHistory (Stack *S, info gameName);

void displayHistory (Stack S, int n);

void deleteHistory (Stack *S, info gameName);

void resetHistory (Stack *S);

#endif