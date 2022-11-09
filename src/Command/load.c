#include "../ADT/Array/array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"

void load(char * filename, Tab * loadsave) {
    /* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
    I.S. : filename terdefinisi, Tab kosong
    F.S. : Tab loadsave terisi dengan .txt yang bernama filename */
    char *dir = "../../savefile/";
    char *fileDir;
    concatStr(dir, filename, fileDir);
    int i = 0;
    STARTWORD(fileDir);
    while (!EndWord) {
        (*loadsave).TI[i] = CWord;
        (*loadsave).Neff++;
        ADVWORD();
        i++;
    }
}
