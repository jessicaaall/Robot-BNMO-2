#include "../ADT/Array/array.h"
#include "../ADT/MesinKataKar/mesin_kar.h"
#include "../ADT/MesinKataKar/mesin_kata.h"

void load(char * filename, Tab * loadsave) {
    /* Membuka .txt dan menyimpan isi ke Tab loadsave setiap baris
    I.S. : filename terdefinisi, Tab kosong
    F.S. : Tab loadsave terisi dengan .txt yang bernama filename */
    int i = 0;
    STARTKATA(filename);
    while (!EndKata) {
        (*loadsave).TI[i] = KatatoStr(CKata);
        (*loadsave).Neff++;
        ADVKATA();
        i++;
    }
}
