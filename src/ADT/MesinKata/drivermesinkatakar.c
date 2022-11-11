#include <stdio.h>
#include "mesinkata.h"

int main() {
    int i = 0;
    STARTWORD("konfigurasi.txt");

    while (!EOP) {
        printf("%s\n", CWord.TabWord); //

        ADVWORD();
        i++;
    }
    return 0;
}