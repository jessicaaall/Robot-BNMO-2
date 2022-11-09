/* File : rnggame.h */

#ifndef __RNG_GAME_H__
#define __RNG_GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

int RNGgame();
/* Mengembalikan skor akhir pemain pada RNG game */
/* RNG game : 
   Menentukan sebuah angka acak X 
   Pemain diberikan kesempatan menebak angka X dan game memberi tahu apakah tebakan pemain dibandingkan terhadap X lebih besar atau lebih kecil 
   Permainan selesai jika pemain menebak angka X dengan benar atau jika kesempatan menebak habis
   Pemain memiliki skor awal 100, skor akan berkurang 5 setiap tebakan pemain salah 
   Kesempatan menebak habis ketika skor pemain telah berkurang menjadi 0 */

#endif