#include <stdio.h>
#include "help.h"

void HELP () {
    printf("\n============================== HELP ==============================\n\n");
    printf("START        : Membaca file konfigurasi default\n");
    printf("LOAD <file>  : Membaca file yang berisi daftar game\n");
    printf("SAVE <file>  : Menyimpan state game pemain saat ini ke suatu file\n");
    printf("CREATEGAME   : Menambahkan game baru pada daftar game\n");
    printf("LISTGAME     : Menampilkan daftar game\n");
    printf("DELETEGAME   : Menghapus game dari daftar game\n");
    printf("QUEUEGAME    : Mendaftarkan permainan ke dalam daftar antrian game\n");
    printf("PLAYGAME     : Memainkan game pertama pada antrian game\n");
    printf("SKIPGAME <n> : Melewatkan permainan sebanyak n\n");
    printf("QUIT         : Keluar dari program\n");
}