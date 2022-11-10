/* File : creategame.h */

#ifndef __CREATEGAME_H__
#define __CREATEGAME_H__

#include "../boolean.h"
#include "../ADT/Array/array.h"
#include "../ADT/MesinKata/mesinkata.h"
#include <stdio.h>

void CREATEGAME (Tab *daftargame);
/* Proses : Menerima input nama game yang akan ditambahkan 
            Menambahkan game baru pada daftar game */
/* I.S. Daftar game terdefinisi */
/* F.S. Apabila game yang ingin ditambahkan tidak ada pada daftar game, daftar game bertambah 
        Apabila game yang ingin ditambahkan sudah ada pada daftar game, daftar game tetap */

#endif