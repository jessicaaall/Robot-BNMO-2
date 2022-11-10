
#include <stdio.h>
#include "queuegame.h"

void queuegame(Queue *Q,Tab *T){
    boolean check = false; 
    printf("Berikut adalah daftar Game-mu\n");
    displayQueueGame(*Q);
    listgame(*T);
    while (!check){
    printf("Nomor game yang  ingin ditambahkan dalam antrian : ");
    STARTCOMMAND();
    if (CommandCC<=(*T).TI[0]){
        enqueue(Q,(*T).TI[CommandCC]);
        printf("\nGame berhasil ditambahkan ke dalam antrian.\n");
        check = true;
    }
    else{
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }}
}