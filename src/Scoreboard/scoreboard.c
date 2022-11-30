#include "scoreboard.h"

void INSERTSCOREBOARD(int score, TabMap *TM, int idx) {
    Word name1;
    Word name2;
    Map M;

    M = GetElmtArrMap(*TM, idx);
    printf("Silahkan masukkan nama anda: ");
    Scan(&name1, &name2);
    while(IsMember(M, name1) && name2.Length == 0){
        printf("Nama sudah ada, silahkan masukkan nama lain: ");
        scan(&name1, &name2);
    }
    InsertScore(&M, name1, score);
    TM->Elmt[idx] = M;
    printf("Score berhasil dimasukkan ke scoreboard!\n");
}

void SCOREBOARD(TabMap TM,Tab T){
    Map currBoard;
    int i,j,k,align;
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

void RESETSCOREBOARD(Tab T, TabMap *TM){
    Word inp1,inp2;
    int i;

    printf("DAFTAR SCOREBOARD:\n0. ALL");
    for (i = 0; i < NbelmtArray(T); i++){
        printf("%d. ", i+1);
        PrintWord(T.TI[i]);
        printf("\n");
    }

    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    Scan(&inp1,&inp2);
    if (inp1.Length == 1 && inp1.TabWord[0] == '0' && inp2.Length == 0){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SEMUA SCOREBOARD (YA/TIDAK)? ");
        Scan(&inp1,&inp2);
        if (IsWordSame(inp1, StringToWord("YA"))){
            for (i = 0; i < NbelmtArray(T); i++){
                MakeEmpty(TM->Elmt[i]);
            }
            printf("SEMUA SCOREBOARD TELAH DIHAPUS!\n");
        } else {
            printf("RESET SCOREBOARD DIBATALKAN!\n");
        }
    } else if (inp1.Length == 1 && inp1.TabWord[0] >= '1' && inp1.TabWord[0] <= '9' && inp2.Length == 0){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
        PrintWord(T.TI[inp1.TabWord[0] - '1']);
        printf("(YA/TIDAK)? ");
        Scan(&inp1,&inp2);
        if (IsWordSame(inp1, StringToWord("YA"))){
            MakeEmpty(TM->Elmt[inp1.TabWord[0] - '1']);
            printf("Scoreboard berhasil di-reset.\n");
        } else {
            printf("RESET SCOREBOARD DIBATALKAN!\n");
        }
    } else {
        printf("Input tidak valid!\n");
    }
}