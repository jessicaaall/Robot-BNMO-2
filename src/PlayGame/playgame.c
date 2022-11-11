#include "playgame.h"

boolean compareString(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

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
        if (compareString(game, "RNG")){
            printf("Loading RNG ...\n");
            skor = RNGgame();
        } else if (compareString(game, "Diner DASH")){
            printf("Loading DINER DASH ...\n");
            DINNERDASH();
        } else if (compareString(game, "DINOSAUR IN EARTH") || compareString(game, "RISEWOMAN") || compareString(game, "EIFFEL TOWER")){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", game);
        } else {
            printf("Loading %s ...\n\n", game);
            skor = skorgame();
        }
    }
    
}