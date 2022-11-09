#include "mesin_kar.h"
#include <stdio.h>

char CCQ;
boolean EOPQ;
boolean MBRQ;

static FILE *pitaQ;
static int retvalQ;

void STARTQ()
{
    /* Mesin siap dioperasikan. Pita dari .txt untuk dibaca
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
           Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    char *dir = "../../savefile/";
    static FILE *pitaQ;
    char CCQ;
    int retvalQ;
    pitaQ = stdin;
    EOPQ = false;
    ADVQ();
}

void ADVQ()
{
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela =
           CC, retval >= 0
    F.S. : CC adalah karakter berikutnya dari CC yang lama,
           retval mungkin < 0.
           Jika  retval < 0 maka EOP akan menyala (true) */

    /* Algoritma */
    retvalQ = fscanf(pitaQ, "%c", &CCQ);
    if (CCQ == '\n') {
        EOPQ = true;
    }
}
