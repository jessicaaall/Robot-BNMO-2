#include "skorgame.h"

void SKORGAME(int *skor) {
    int i;
    time_t waktu;
    struct tm *infotime;

    time(&waktu);
    infotime = localtime(&waktu);
    srand(waktu);
    *skor = rand() % 101;
    for (i = 0; i < (*infotime).tm_sec; i++) {
        *skor = (rand() + *skor) % 101;
    }

    printf("\n===============================\n");
    printf("||     G A M E   O V E R     ||\n");
    printf("===============================\n\n");
    printf("Skor akhir = %d\n\n", *skor);
}
/* Proses : Membangkitkan integer random antara 0 sampai 100 */
/* I.S  Terdefinisi */
/* F.S  Menghasilkan skor akhir berupa integer random */