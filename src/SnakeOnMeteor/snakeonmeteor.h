#ifndef SNAKE_ON_METEOR_H
#define SNAKE_ON_METEOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./ADT/MesinKata/mesinkata.h"
#include "listdp.h"
#include "matriks.h"


void move(List *snake, char input, int *tempX, int *tempY);
/* IS: Sembarang
   FS: Memindahkan koordinat snake sesuai input yang di masukkan */

void food(List *snake);
/* IS: Sembarang
   FS: Menambahkan makanan kedalam permainan*/

void Peta(List snake, int x, int y);
/* IS: Sembarang
   FS: menampilkan peta lengkap dengan ular makanan dan meteor*/

boolean nabrak(char input, List snake);
/* IS: Sembarang
   FS: memeriksa apakah ular menabrak badan sendiri atau tidak*/

boolean bekas_meteor(List snake,int x,int y,char input);
/* IS: Sembarang
   FS: memeriksa apakah suatu koordinat merupakan bekas meteor atau bukan dan bisaa untuk dilewati*/


void SNAKEONMETEOR(int *skor);
// Desc: Menjalankan game snake
/* IS: Sembarang
   FS: Menghasilkan skor akhir dari game snake */

#endif