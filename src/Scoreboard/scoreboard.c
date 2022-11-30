#include "scoreboard.h"

void INSERTSCOREBOARD(int score, TabMap *TM, int idx) {
    Word name1;
    Word name2;
    Map M;

    M = GetElmtArrMap(*TM, idx);
    printf("Nama: ");
    Scan(&name1, &name2);
    while(IsMember(M, name1) && name2.Length == 0){
        printf("Nama sudah ada, silahkan masukkan nama lain: ");
        Scan(&name1, &name2);
    }
    InsertScore(&M, name1, score);
    TM->Elmt[idx] = M;
    printf("Score berhasil dimasukkan ke scoreboard!\n");
}

void SCOREBOARD(TabMap TM,Tab T){
    Map currBoard;
    int i,j,k,align;
    for (i = 0; i < NbElmtArray(T); i++){
        currBoard = GetElmtArrMap(TM, i);
        printf("**** SCOREBOARD GAME ");
        PrintWord(T.TI[i]);
        printf(" ****\n");
        printf("| NAMA          | SKOR |\n");
        if (currBoard.Count == 0){
            printf("----- SCOREBOARD KOSONG -----\n");
        } else {
            printf("|----------------------|\n");
            for (j = 0; j < currBoard.Count; j++){
                printf("| ");
                PrintWord(currBoard.Elements[j].Key);
                align = 15 - currBoard.Elements[j].Key.Length;
                for (k = 0; k < align-1; k++){
                    printf(" ");
                }
                printf("| %d", currBoard.Elements[j].Value);
                if (currBoard.Elements[j].Value < 10){
                    printf("    |\n");
                } else if (currBoard.Elements[j].Value < 100){
                    printf("   |\n");
                } else {
                    printf("  |\n");
                }
            }
    }
        printf("\n");
    }
}

void RESETSCOREBOARD(Tab T, TabMap *TM){
    Word inp1,inp2,inp3;
    int i;
    Map resetM;
    CreateEmptyMap(&resetM);

    printf("DAFTAR SCOREBOARD:\n0. ALL\n");
    for (i = 0; i < NbElmtArray(T); i++){
        printf("%d. ", i+1);
        PrintWord(T.TI[i]);
        printf("\n");
    }

    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    Scan(&inp1,&inp2);
    if (inp1.Length == 1 && inp1.TabWord[0] == '0' && inp2.Length == 0){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SEMUA SCOREBOARD\n(YA/TIDAK)? ");
        Scan(&inp1,&inp2);
        if (IsWordSame(inp1, StringToWord("YA"))){
            for (i = 0; i < NbElmtArray(T); i++){
                TM->Elmt[i] = resetM;
            }
            printf("SEMUA SCOREBOARD TELAH DIHAPUS!\n");
        } else {
            printf("RESET SCOREBOARD DIBATALKAN!\n");
        }
    } else if (inp1.Length == 1 && inp1.TabWord[0] >= '1' && inp1.TabWord[0] <= '9' && inp2.Length == 0){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
        PrintWord(T.TI[inp1.TabWord[0] - '1']);
        printf("\n(YA/TIDAK)? ");
        Scan(&inp2,&inp3);
        if (IsWordSame(inp2, StringToWord("YA"))){
            TM->Elmt[inp1.TabWord[0] - '1'] = resetM;
            printf("Scoreboard berhasil di-reset.\n");
        } else {
            printf("RESET SCOREBOARD DIBATALKAN!\n");
        }
    } else {
        printf("Input tidak valid!\n");
    }
}