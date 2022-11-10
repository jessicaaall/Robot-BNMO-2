#include <stdio.h>
#include "listgame.h"

void LISTGAME(Tab T) {
    printf("Berikut adalah daftar game yang tersedia\n");
    int i, j;
    for (i = 0; i < NbElmtArray(T); i++) {
        printf("%d. ", i+1);
        for (j = 0; j < T.TI[i].Length; j++) {
            printf("%c", T.TI[i].TabWord[j]);
        }
        printf("\n");
    }
}
/* Mencetak daftar game ke layar */
/* I.S. Daftar game terdefinisi */ 
/* F.S. Daftar game ditampilkan ke layar */