#include <stdio.h>
#include "queuegame.h"
#include "../ListGame/listgame.h"

void QUEUEGAME(Tab daftargame, Queue *queuegame) {
    if (isEmpty(*queuegame)) {
        printf("Daftar antrian game-mu kosong.\n");
    } else {
        printf("Berikut adalah daftar antrian game-mu\n");
        displayQueueGame(*queuegame);
    }
    printf("\n");
    LISTGAME(daftargame);

    printf("\nNomor game yang mau ditambahkan ke antrian >> ");
    STARTCOMMAND2();
    printf("\n");

    boolean valid = true;
    int i, nomor;

    for (i = 0; i < CommandCC.Length; i++) {
        if ((CommandCC.TabWord[i] < '0') || (CommandCC.TabWord[i] > '9')) {
            valid = false;
        }
    }

    if (!valid) {
        printf("\nNomor permainan tidak valid, silahkan masukkan nomor game pada daftar game.\n");
    } else {
        nomor = 0;
        for (i = 0; i < CommandCC.Length; i++) {
            nomor = nomor*10 + (CommandCC.TabWord[i] - '0');
        }

        if ((nomor == 0) || (nomor > daftargame.Neff)) {
            printf("\nNomor permainan tidak valid, silahkan masukkan nomor game pada daftar game.\n");
        } else {
            enqueue(queuegame, daftargame.TI[nomor-1]);
            printf("\nGame berhasil ditambahkan ke dalam daftar antrian.\n");
        }
    }
}
/* Proses : Menerima input nomor game yang ingin ditambahkan dalam daftar antrian game
            Apabila input nomor game valid, daftar antrian game bertambah
            Apabila input nomor game tidak valid, daftar antrian game tetap */
/* I.S. Daftar antrian game terdefinisi */
