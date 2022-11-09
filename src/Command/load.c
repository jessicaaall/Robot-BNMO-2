#include "../ADT/Array/array.h"
#include "../ADT/MesinKataKar/mesin_kar.h"
#include "../ADT/MesinKataKar/mesin_kata.h"

void load(char * filename, Tab * loadsave) {
    /* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
    I.S. : filename terdefinisi, Tab kosong
    F.S. : Tab loadsave terisi dengan .txt yang bernama filename */
    char *dir = "../../savefile/";
    char *fileDir;
    concatStr(dir, filename, fileDir);
    int i = 0;
    STARTKATA(fileDir);
    while (!EndKata) {
        (*loadsave).TI[i] = CKata;
        (*loadsave).Neff++;
        ADVKATA();
        i++;
    }
}
