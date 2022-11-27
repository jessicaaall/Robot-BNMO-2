#include "playgame.h"
#include <stdio.h>

void PLAYGAME(Queue *queuegame) {
    ElType game;
    int skor;

    dequeue(queuegame, &game);
    if (IsWordSame(game, StringToWord("RNG"))){
        printf("Loading RNG ...\n");
        RNGGAME(&skor);
    } else if (IsWordSame(game, StringToWord("Diner DASH"))){
        printf("Loading DINER DASH ...\n");
        DINNERDASH();
    } else if (IsWordSame(game, StringToWord("DINOSAUR IN EARTH")) || IsWordSame(game, StringToWord("RISEWOMAN")) || IsWordSame(game, StringToWord("EIFFEL TOWER"))){
        printf("Game ");
        PrintWord(game);
        printf(" masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n");
    } else {
        printf("Loading ");
        PrintWord(game);
        printf(" ...\n\n");
        skor = skorgame();
    }     
}
/*
I.S. Daftar antrian game terdefinisi
F.S. Game pertama pada daftar antrian game dimainkan
*/