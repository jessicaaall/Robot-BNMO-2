/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../boolean.h"

#define MARK '\n'
/* State Mesin */
extern char CCQ;
extern boolean EOPQ;
extern boolean MBRQ;

void START();
/* Mesin siap dioperasikan. Pita dari .txt untuk dibaca
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
      Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, retval >= 0
F.S. : CC adalah karakter berikutnya dari CC yang lama,
      retval mungkin < 0.
      Jika  retval < 0 maka EOP akan menyala (true) */

#endif
