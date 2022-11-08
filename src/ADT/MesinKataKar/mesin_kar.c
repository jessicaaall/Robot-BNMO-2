#include "mesin_kar.h"
#include <stdio.h>

char CC;
boolean EOP;
boolean MBR;

static FILE *pita;
static int retval;

void START(filename)
{
    /* Mesin siap dioperasikan. Pita dari .txt untuk dibaca
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
           Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = fopen(filename, "r");
    EOP = false;
    ADV();
}

void ADV()
{
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela =
           CC, retval >= 0
    F.S. : CC adalah karakter berikutnya dari CC yang lama,
           retval mungkin < 0.
           Jika  retval < 0 maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita, "%c", &CC);
    if (retval < 0) {
        EOP = true;
        fclose(pita);
    }
}
