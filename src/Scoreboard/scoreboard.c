#include "scoreboard.h"

void insertScoreboard (int score, Map *M){
    Word name1;
    Word name2;
    printf("Silahkan masukkan nama anda: ");
    Scan(&name1, &name2);
    while(IsMember(*M, name1)){
        printf("Nama sudah ada, silahkan masukkan nama lain: ");
        scan(&name1, &name2);
    }
    Insert(M, name1, score);
    printf("Score berhasil dimasukkan ke scoreboard!\n");
}

void displayScoreboard (TabMap T){

}

void resetScoreboard (){
    //LIST SCOREBOARD
    printf("SCOREBOARD YANG INGIN DIHAPUS:");
    //INPUT ANGKA
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ___ (YA/TIDAK)?");
    //INPUT YA/TIDAK
    if (YA){
        //HAPUS SCOREBOARD
        printf("Scoreboard berhasil di-reset./n");
    }
    else if (TIDAK){
        printf("Scoreboard gagal di-reset. Anda akan diarahkan kembali ke menu utama./n");
    }
    else {
        printf("Input tidak valid. Anda akan diarahkan kembali ke menu utama./n");
            }
}
