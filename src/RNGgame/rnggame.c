#include "rnggame.h"

void RNGGAME(int *skor) {

    printf("\n ____    _   _    ____      ____      _      __  __   _____\n");
    printf("|  _ \\  | \\ | |  / ___|    / ___|    / \\    |  \\/  | | ____|\n");
    printf("| |_) | |  \\| | | |  _    | |  _    / _ \\   | |\\/| | |  _|\n");
    printf("|  _ <  | |\\  | | |_| |   | |_| |  / ___ \\  | |  | | | |___\n");
    printf("|_| \\_\\ |_| \\_|  \\____|    \\____| /_/   \\_\\ |_|  |_| |_____|\n\n\n");

    int X, i;
    time_t waktu;
    struct tm *infotime;

    time(&waktu);
    infotime = localtime(&waktu);
    srand(waktu);
    X = rand() % 100;
    for (i = 0; i < (*infotime).tm_sec; i++) {
        X = (rand() + X) % 100;
    }

    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak angka X.\n\n");

    boolean valid;
    int tebakan;
    *skor = 100;

    do {
        do {
            printf("Tebakan >> ");
            STARTCOMMAND2();

            i = 0;
            valid = true;
            while ((valid) && (i < CommandCC.Length)) {
                if ((CommandCC.TabWord[i] < '0') || (CommandCC.TabWord[i] > '9')) {
                    valid = false;
                }
                i++;
            }

            if (!(valid)) {
                printf("Tebakan Anda tidak valid. Mohon masukkan bilangan integer.\n\n");
            }
        } while (!(valid));

        tebakan = 0;
        for (i = 0; i < CommandCC.Length; i++) {
            tebakan = tebakan*10 + (CommandCC.TabWord[i] - '0');
        }

        if (tebakan < X) {
            printf("Lebih besar\n\n");
            *skor -= 5;
        } else if (tebakan > X) {
            printf("Lebih kecil\n\n");
            *skor -= 5;
        } else {
            printf("\nSelamat, tebakan Anda benar! X adalah %d.\n\n", X);
        }
    } while ((tebakan != X) && (*skor != 0));

    if (*skor == 0) {
        printf("Kesempatan Anda telah habis. Anda gagal menebak. X adalah %d.\n\n", X);
    }

    printf("\n===============================\n");
    printf("||     G A M E   O V E R     ||\n");
    printf("===============================\n\n");
    printf("Skor akhir = %d\n\n", *skor);
}
/* Proses : Menentukan sebuah angka acak X 
            Pemain diberikan kesempatan menebak angka X dan game memberi tahu apakah tebakan pemain dibandingkan terhadap X lebih besar atau lebih kecil 
            Permainan selesai jika pemain menebak angka X dengan benar atau jika kesempatan menebak habis
            Pemain memiliki skor awal 100, skor akan berkurang 5 setiap tebakan pemain salah 
            Kesempatan menebak habis ketika skor pemain telah berkurang menjadi 0 */
/* I.S.  Terdefinisi */
/* F.S.  Menghasilkan skor akhir dari permainan RNG */