/* File : deletegame.h */

#ifndef __DELETEGAME_H__
#define __DELETEGAME_H__

#include "../boolean.h"
#include "../ADT/Array/array.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ListGame/listgame.h"
#include "../ADT/Map/map.h"
#include "../ADT/ArrayOfMap/arrayofmap.h"
#include <stdio.h>

void DELETEGAME (Tab *daftargame, Queue queuegame, TabMap *listscoreboard);
/* Proses : Menerima input nomor game yang ingin dihapus
            Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna 
            Apabila input game merupakan salah satu dari 5 game pertama pada daftar game, maka game gagal dihapus
            Apabila input game merupakan salah satu dari game yang terdapat dalam queue game, maka game gagal dihapus */
/* I.S. Daftar game dan queue game terdefinisi */
/* F.S. Daftar game berkurang jika game berhasil dihapus atau tetap jika game gagal dihapus */

#endif