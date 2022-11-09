#include "skorgame.h"

int skorgame() {
    int i, skor;
    time_t waktu;
    struct tm *infotime;

    time(&waktu);
    infotime = localtime(&waktu);
    srand(waktu);
    skor = rand() % 100;
    for (i = 0; i < (*infotime).tm_sec; i++) {
        skor = (rand() + skor) % 100;
    }

    printf("GAME OVER\n\nSkor Anda = %d\n", skor);

    return skor;
}
/* Mengembalikan skor akhir berupa integer random */