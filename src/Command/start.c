#include "../ADT/Array/array.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKata/mesinkata.h"

void start( Tab * loadsave) {
    /* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
    I.S. : filename terdefinisi, Tab kosong
    F.S. : Tab loadsave terisi dengan .txt yang bernama filename */
    char *fileDir = "../../savefile/konfigurasi.txt";
    int i = 0;
    STARTKATA(fileDir);
    while (!EndKata) {
        (*loadsave).TI[i] = CKata;
        (*loadsave).Neff++;
        ADVKATA();
        i++;
    }
}
