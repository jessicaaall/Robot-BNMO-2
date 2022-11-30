#include "playgame.h"
#include <stdio.h>

void PLAYGAME(Queue *queuegame, TabMap *TM) {
    ElType game;
    int skor;

    dequeue(queuegame, &game);
    printf("Loading ");
    PrintWord(game);
    printf(" ...\n");

    if (IsWordSame(game, StringToWord("RNG"))){
        RNGGAME(&skor);
    } else if (IsWordSame(game, StringToWord("DINER DASH"))){
        DINNERDASH(&skor);
    } else if (IsWordSame(game, StringToWord("HANGMAN"))){
        HANGMAN(&skor);
    } else if (IsWordSame(game, StringToWord("TOWER OF HANOI"))){
        TOWEROFHANOI(&skor);
    } else if (IsWordSame(game, StringToWord("SNAKE ON METEOR"))){
        printf("Game ");
        PrintWord(game);
        printf(" masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n");
    } else {
        SKORGAME(&skor);
    }
    INSERTSCOREBOARD(skor,TM);
    // TAMBAH KE HISTORY
}
/*
I.S. Daftar antrian game terdefinisi
F.S. Game pertama pada daftar antrian game dimainkan
*/