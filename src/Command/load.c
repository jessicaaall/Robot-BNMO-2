#include "load.h"

void load(char * filename, Tab * loadsave) {
    /* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
    I.S. : filename terdefinisi, Tab kosong
    F.S. : Tab loadsave terisi dengan .txt yang bernama filename */
    int i = 0;
    // printf("lagi 0\n"); //
    STARTWORD(filename);
    // printf("lagi 1\n"); //
    while (!EOP) {
        (*loadsave).TI[i] = CWord;
        printf("%s\n", CWord.TabWord); //
        ADVWORD();
        // printf("%d\n", i);
        i++;
    }
    (*loadsave).TI[i] = CWord;
    i++;
    (*loadsave).Neff = i;
}

void save(char * filename, Tab loadsave) {
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d\n", loadsave.Neff);
    for (int i = 1; i < loadsave.Neff; i++) {
        fprintf(f, "%s\n", GetElmtArray(loadsave, i).TabWord);
    }
}