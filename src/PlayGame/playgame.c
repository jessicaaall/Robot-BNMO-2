#include "playgame.h"

void PLAYGAME(Queue *Q){
    /*
    I.S. Daftar game terdefinisi
    F.S. Game yang dipilih dimainkan
    */
    int i, skor;
    ElType game;

    if (!isEmpty(*Q)){
        printf("Berikut adalah daftar Game-mu\n");
        displayQueueGame(*Q);
        printf("\n");
        dequeue(Q, &game);
        if (game == "RNG"){
            printf("Loading RNG ...\n");
            skor = RNGgame();
        } else if (game == "Diner DASH"){
            printf("Loading DINER DASH ...\n");
            DINNERDASH();
        } else if (game == "DINOSAUR IN EARTH" || game == "RISEWOMAN" || game == "EIFFEL TOWER"){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", game);
        } else {
            printf("Loading %s ...\n\n", game);
            skor = skorgame();
        }
    }
    
}