#include "save.h"

void SAVE(Word filename, Tab loadsave) {
    char *namafile;
    WordToString(filename, namafile);
    
    FILE *f = fopen(namafile, "w");
    fprintf(f, "%d\n", loadsave.Neff);
    for (int i = 0; i < loadsave.Neff; i++) {
        fprintf(f, "%s\n", GetElmtArray(loadsave, i).TabWord);
    }
    PrintWord(filename);
    printf(" berhasil disimpan.\n");
    fclose(f);
}