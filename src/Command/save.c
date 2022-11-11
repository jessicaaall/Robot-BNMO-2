#include "save.h"

void save(char * filename, Tab loadsave) {
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d\n", loadsave.Neff);
    for (int i = 1; i < loadsave.Neff; i++) {
        fprintf(f, "%s\n", GetElmtArray(loadsave, i).TabWord);
    }
}