#ifndef TOH_H
#define TOH_H

#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"

#define Nil -1

typedef struct {
    int buffer[5];
    int TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).buffer[(S).TOP]

void CreateEmpty (Stack *S);

#endif