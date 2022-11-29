#include "save.h"

void SAVE(Word filename, Tab game, Stack history, TabMap scoreboard) {
    char namafile[NMax], temp[NMax];
    int i, j;
    info el;

    WordToString(filename, namafile);
    FILE *f = fopen(namafile, "w");

    fprintf(f, "%d\n", game.Neff);
    for (i = 0; i < game.Neff; i++) {
        fprintf(f, "%s\n", GetElmtArray(game, i).TabWord);
    }

    fprintf(f, "%d\n", Top(history)+1);
    while (!IsStackEmpty(history)) {
        Pop(&history, &el);
        WordToString(el, temp);
        fprintf(f, "%s\n", temp);
    }

    for (i = 0; i < scoreboard.Nelmt; i++) {
        fprintf(f, "%d\n", scoreboard.Elmt[i].Count);
        for (j = 0; j < scoreboard.Elmt[i].Count; j++) {
            WordToString(scoreboard.Elmt[i].Elements[j].Key, temp);
            fprintf(f, "%s ", temp);
            fprintf(f, "%d\n", scoreboard.Elmt[i].Elements[j].Value);
        }
    }

    PrintWord(filename);
    printf(" berhasil disimpan.\n");
    fclose(f);
}
/* Menyimpan isi Tab game, Stack history, dan TabMap scoreboard ke dalam filename.txt */
/* I.S. Filename terdefinisi, Tab game terdefinisi, Stack history terdefinisi, TabMap scoreboard terdefinisi */
/* F.S. Filename.txt berisi daftar game, history game, dan scoreboard untuk setiap game */