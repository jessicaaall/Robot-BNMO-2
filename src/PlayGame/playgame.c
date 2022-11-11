#include "playgame.h"
#include <stdio.h>

void PLAYGAME(Queue *queuegame) {
    if (isEmpty(*queuegame)) {
        printf("Daftar antrian game-mu kosong. Tidak ada game untuk dimainkan.\n");
    } else {
        printf("Berikut adalah daftar antrian game-mu\n");
        displayQueueGame(*queuegame);
        printf("\n");
        
        ElType game;
        int skor;

        dequeue(queuegame, &game);
        if (IsWordSame(game, StringToWord("RNG"))){
            printf("Loading RNG ...\n");
            skor = RNGgame();
        } else if (IsWordSame(game, StringToWord("Diner DASH"))){
            printf("Loading DINER DASH ...\n");
            DINNERDASH();
        } else if (IsWordSame(game, StringToWord("DINOSAUR IN EARTH")) || IsWordSame(game, StringToWord("RISEWOMAN")) || IsWordSame(game, StringToWord("EIFFEL TOWER"))){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", game);
        } else {
            printf("Loading %s ...\n\n", game);
            skor = skorgame();
        }
    }      
}
/*
I.S. Daftar antrian game terdefinisi
F.S. Game pertama pada daftar antrian game dimainkan
*/