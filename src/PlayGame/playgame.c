#include "playgame.h"

void playgame(Queue *Q){
    /*
    I.S. Daftar game terdefinisi
    F.S. Game yang dipilih dimainkan
    */
    int i;
    ElType game;

    if (!isEmpty(*Q)){
        printf("Berikut adalah daftar Game-mu\n");
        displayQueueGame(*Q);
        dequeue(Q, &game);
        if (game == "RNG"){
            printf("Loading RNG ...\n");
            RNGgame();
        } else if (game == "Diner DASH"){
            printf("Loading DINER DASH ...\n");
            DinerDash();
        } else if (game == "TicTacToe"){
            printf("Loading TicTacToe ...\n");
            TicTacToe();
        } else if (game == "DINOSAUR IN EARTH" || game == "RISEWOMAN" || game == "EIFFEL TOWER"){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain\n",game);
        } else {
            printf("Loading %s ...\n", game);
            skorgame();
        }
    }
    
}