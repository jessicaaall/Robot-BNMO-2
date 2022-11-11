#include <stdio.h>
#include "help.h"

void HELP () {
    printf("\n============================== HELP ==============================\n\n");
    printf("START           : Membaca file konfigurasi default\n");
    printf("LOAD <file>     : Membaca file yang berisi daftar game\n");
    printf("SAVE <file>     : Menyimpan state game pemain saat ini ke suatu file\n");
    printf("CREATE GAME     : Menambahkan game baru pada daftar game\n");
    printf("LIST GAME       : Menampilkan daftar game\n");
    printf("DELETE GAME     : Menghapus game dari daftar game\n");
    printf("QUEUE GAME      : Mendaftarkan permainan ke dalam daftar antrian game\n");
    printf("PLAY GAME       : Memainkan game pertama pada antrian game\n");
    printf("SKIPGAME <n>    : Melewatkan permainan sebanyak n\n");
    printf("QUIT            : Keluar dari program\n");
}