#include "scoreboard.h"
#include "../ADT/Mesikata/mesinkata.h"

void INSERTSCOREBOARD(int score, TabMap *TM, int idx) {
    Word name1;
    Word name2;
    Map M;

    M = TM->TI[idx];
    printf("Silahkan masukkan nama anda: ");
    Scan(&name1, &name2);
    while(IsMember(*M, name1) && name2.Length == 0){
        printf("Nama sudah ada, silahkan masukkan nama lain: ");
        scan(&name1, &name2);
    }
    InsertScore(M, name1, score);
    TM->TI[idx] = M;
    printf("Score berhasil dimasukkan ke scoreboard!\n");
}

void SCOREBOARD(TabMap TM,Tab T){
    Map currBoard;
    int i,j,align;
    for (i = 0; i < NbelmtArray(T); i++){
        currBoard = GetElmtArrMap(TM, i);
        printf("**** SCOREBOARD GAME ");
        PrintWord(T.TI[i]);
        printf(" ****\n");
        printf("| NAMA     | SKOR |\n");
        printf("|-----------------|\n");
        for (j = 0; j < currBoard.Count; j++){
            printf("| ");
            PrintWord(currBoard.Elements[j].Key);
            align = 10 - currBoard.Elements[j].Key.Length;
            for (k = 0; k < align; k++){
                printf(" ");
            }
            printf("| %d |\n", currBoard.Elements[j].Value);
        }
        printf("\n");
    }
}

void RESETSCOREBOARD(){
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
