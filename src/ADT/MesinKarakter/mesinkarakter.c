#include "mesinkarakter.h"

char CC;
boolean EOP;
boolean MBR;

static FILE *pita;
static FILE *command;
static int retval;


/* *** ADT Mesin Karakter untuk Baca File Eksternal *** */

void START(char * filename) {
    pita = fopen(filename, "r");
    EOP = false;
    ADV();
}
/* Mesin siap dioperasikan. Pita dari .txt disiapkan untuk dibaca
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. 
          Jika CC != ENTER maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV() {    
    retval = fscanf(pita, "%c", &CC);
    if (retval < 0) {
        EOP = true;
        fclose(pita);
    }
}
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, retval >= 0
F.S. : CC adalah karakter berikutnya dari CC yang lama,
      retval mungkin < 0.
      Jika  retval < 0 maka EOP akan menyala (true) */


/* *** ADT Mesin Karakter untuk Baca Command *** */

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