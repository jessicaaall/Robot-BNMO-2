/* File: mesinkarcommand.h */
/* Definisi Mesin Karakter Command */

#ifndef __MESIN_KAR_COMMAND_H__
#define __MESIN_KAR_COMMAND_H__

#include <stdio.h>
#include "boolean.h"

#define ENTER '\n'

/* State Mesin */
extern char CC;
extern boolean EOP;

void STARTC();
/* Mesin siap dioperasikan. Command disiapkan untuk dibaca.
   Karakter pertama yang ada pada command posisinya adalah pada jendela.
   Command baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada command
          Jika CC != ENTER maka EOP akan padam (false)
          Jika CC = ENTER maka EOP akan menyala (true) */

void ADVC();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, currentChar != ENTER
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = ENTER
          Jika  currentChar = ENTER maka EOP akan menyala (true) */

#endif