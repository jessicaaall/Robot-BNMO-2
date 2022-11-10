#include <stdio.h>
#include "skipgame.h"


void skipgame(Word command,Queue *q){
    int i=0;
    int hasil=0;
    int j=0;
    boolean check;
    printf("Berikut adalah daftar game-mu\n");
    displayQueueGame(*q);
    while (i<command.Length && !check){
        if (command.TabWord[i]>='A' &&  command.TabWord[i]<='Z'){
            check = true;
        }
        else{
        hasil = hasil*10 + command.TabWord[i] - 48;
        i++;}

    }
    if (!check){
    if (hasil<length(*q)){
        for (j=0;j<hasil;j++){
            dequeue(q);
    }
    playgame(q);
    }
    else{
        CreateQueue(q);
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    }
    else{
        printf("Masukkan untuk melakukan SKIPGAME salah, dimohon untuk mengganti masukkan game yang ingin di input dengan format angka.\n");
    }
}

