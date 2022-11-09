#include <stdio.h>
#include "help.h"

void help(){
    printf("\n                    HELP\n\n");
    printf("START        : Membaca file konfigurasi default\n");
    printf("LOAD <file>  : Membaca file yang berisi list game dan history\n");
    printf("SAVE <file>  : Menyimpan state game pemain saat ini ke suatu file\n");
    printf("CREATEGAME   : Menambahkan game baru pada daftar game\n");
    printf("LISTGAME     : Menampilkan daftar game\n");
    printf("DELETEGAME   : Menghapus game dari daftar game\n");
    printf("QUEUEGAME    : Mendaftarkan permainan ke dalam list\n");
    printf("PLAYGAME     : Memainkan game pertama pada antrian game\n");
    printf("SKIPGAME <n> : Melewatkan permaian sebanyak n\n");
    printf("QUIT         : Keluar dari program\n");
}