#include <stdio.h>
#include "help.h"

void HELP () {
    printf("\n====================================================  H E L P  ====================================================\n\n");
    printf("START               : Membaca file konfigurasi default\n");
    printf("LOAD <file>         : Membaca file yang berisi daftar game, daftar history game, dan daftar scoreboard setiap game\n");
    printf("SAVE <file>         : Menyimpan state game pemain saat ini ke suatu file\n");
    printf("CREATE GAME         : Menambahkan game baru pada daftar game\n");
    printf("LIST GAME           : Menampilkan daftar game\n");
    printf("DELETE GAME         : Menghapus game dari daftar game\n");
    printf("QUEUE GAME          : Mendaftarkan permainan ke dalam daftar antrian game\n");
    printf("PLAY GAME           : Memainkan game pertama pada antrian game\n");
    printf("SKIPGAME <n>        : Melewatkan permainan sebanyak n\n");
    printf("SCOREBOARD          : Menampilkan daftar scoreboard setiap game\n");
    printf("RESET SCOREBOARD    : Melakukan reset terhadap scoreboard game\n");
    printf("HISTORY <n>         : Menampilkan daftar history game sebanyak n\n");
    printf("RESET HISTORY       : Menghapus semua history game yang dimainkan\n");
    printf("QUIT                : Keluar dari program\n");
    printf("\n===================================================================================================================\n\n");
}
/* Menampilkan bantuan daftar command yang dapat dipanggil */
/* I.S. : sembarang
   F.S. : Menampilkan daftar command beserta kegunaannya */