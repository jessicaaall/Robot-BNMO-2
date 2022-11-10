#include <stdio.h>
#include "listgame.h"

void LISTGAME(Tab T) {
    printf("Berikut adalah daftar game yang tersedia\n");
    int i;
    for (i = 0; i < NbElmtArray(T); i++){
        printf("%d. %s\n", i+1, T.TI[i].TabWord);
    }
}
/* Mencetak daftar game ke layar */
/* I.S. Daftar game terdefinisi */ 
/* F.S. Daftar game ditampilkan ke layar */