
#include <stdio.h>
#include "queuegame.h"

void queuegame(Queue *Q,int n,Tab *T){
    boolean check = false; 
    
    displayQueueGame(Q);
    listgame(T);
    while (!check){
    printf("Nomor game yang  ingin ditambahkan dalam antrian : ");
    STARTCOMMAND();
    if (CommandCC<=(*T).TI[0]){
        enqueue(Q,(*T).TI[CommandCC]);
        printf("Game berhasil ditambahkan ke dalam antrian.");
        check = true;
    }
    else{
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.");
    }}
}