#include "mesinkarcommand.h"

char CC;
boolean EOP;

static FILE *command;
static int retval;


void STARTC() {
    command = stdin;
    ADVC();
}
/* Mesin siap dioperasikan. Command disiapkan untuk dibaca.
   Karakter pertama yang ada pada command posisinya adalah pada jendela.
   Command baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada command
          Jika CC != ENTER maka EOP akan padam (false)
          Jika CC = ENTER maka EOP akan menyala (true) */


void ADVC() {
    retval = fscanf(command, "%c", &CC);
    EOP = (CC == ENTER);
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, currentChar != ENTER
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = ENTER
          Jika  currentChar = ENTER maka EOP akan menyala (true) */