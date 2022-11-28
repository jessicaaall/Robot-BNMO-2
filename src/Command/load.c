#include "load.h"

void LOAD(char *filename, Tab *game, Stack *history, TabMap *scoreboard) {
    Stack temphistory;
    Map listscore;
    Word word1, word2;
    int i, j, count;

    MakeEmptyArray(game);
    CreateEmptyStack(history);
    CreateEmptyStack(&temphistory);
    MakeEmptyArrMap(scoreboard);

    STARTWORD(filename);
    
    count = WordToInt(CWord);
    game->Neff = count;
    for (i = 0; i < count; i++) {
        ADVWORD();
        if (!IsFullArray(*game)) {
            game->TI[i] = CWord;
        }
    }

    ADVWORD();
    count = WordToInt(CWord);
    for (i = 0; i < count; i++) {
        ADVWORD();
        if (!IsStackFull(temphistory)) {
            Push(&temphistory, CWord);
        }
    }
    InverseStack(temphistory, history);

    for (i = 0; i < game->Neff; i++) {
        ADVWORD();
        count = WordToInt(CWord);
        CreateEmptyMap(&listscore);
        for (j = 0; j < count; j++) {
            ADVWORD();
            SplitWord(CWord, &word1, &word2);
            if (!IsMapFull(listscore)) {
                Insert(&listscore, word1, WordToInt(word2));
            }
        }
        if ((*scoreboard).Nelmt != IdxMaxArrMap-IdxMinArrMap+1) {
            InsertArrMap(scoreboard, listscore);
        }
    }
}
/* Proses : Membuka filename.txt 
            Menyimpan isi filename.txt yang berupa daftar permainan ke Tab game 
            Menyimpan isi filename.txt yang berupa daftar history permainan ke Stack history 
            Menyimpan isi filename.txt yang berupa daftar scoreboard permainan ke TabMap scoreboard */
/* I.S. filename terdefinisi */
/* F.S. Tab game berisi daftar permainan yang terdapat dalam filename.txt
        Stack history berisi daftar history permainan yang terdapat dalam filename.txt
        TabMap scoreboard berisi daftar scoreboard permainan yang terdapat dalam filename.txt */