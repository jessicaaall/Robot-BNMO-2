/* File : stackToH.h */

#ifndef STACK_TOH_H
#define STACK_TOH_H

#include <stdio.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

#define Nill -1
#define MaxS 100

typedef struct {
    int bufferS[MaxS];
    int TOPS;
} StackToH;

#define TopS(S) (S).TOPS
#define InfoTopS(S) (S).bufferS[(S).TOPS]

void CreateSEmpty (StackToH *S);
// Desc: Membuat StackToH kosong
/* IS: StackToH sembarang
   FS: StackToH S kosong */

boolean IsSEmpty (StackToH S);
/* Mengirim true apabila StackToH kosong, yaitu TOPS bernilai Nil */

void PushS(StackToH *S, int X);
// Desc: Memasukkan integer S ke StackToH S dengan aturan LIFO (Last In, First Out)
/* IS: StackToH S terdefinisi, mungkin kosong
   FS: integer X sebagai elemen TopS pada StackToH S*/

void PopS(StackToH *S, int *X);
// Desc: Mengeluarkan elemen TopS pada StackToH S
/* IS: StackToH S terdefinisi, tidak kosong
   FS: Elemen TopS StackToH S akan disimpan di X, kemudian dikeluarkan dari StackToH S*/

int LengthS (StackToH S);
// Desc: Mengembalikan panjang dari StackToH S


#endif