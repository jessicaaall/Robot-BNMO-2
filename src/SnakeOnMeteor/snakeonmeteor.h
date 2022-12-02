#ifndef SNAKE_ON_METEOR_H
#define SNAKE_ON_METEOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/ListLinier/listdp.h"
#include "../ADT/Matriks/matriks.h"

boolean meteor_kena_kepala(List L,infotypelist X, infotypelist Y);
/* I.S. list tidak kosong */
/* F.S. apakah koordinat meteor sama dengan koordinat kepala atau first(L)*/
boolean meteor_kena_badan(List L,infotypelist X, infotypelist Y);
/* I.S. list tidak kosong */
/* F.S. apakah koordinat meteor sama dengan koordinat badan*/

void move(List *snake, char input, int *tempX, int *tempY);
/* IS: Sembarang
   FS: Memindahkan koordinat snake sesuai input yang di masukkan */

void food(List *snake,int X1,int Y1,int X2, int Y2);
/* IS: Sembarang
   FS: Menambahkan makanan kedalam permainan*/

void Peta(List snake, int x, int y, int X,int Y,int X2, int Y2);
/* IS: Sembarang
   FS: menampilkan peta lengkap dengan ular makanan dan meteor*/

boolean nabrak(char input, List snake);
/* IS: Sembarang
   FS: memeriksa apakah ular menabrak badan sendiri atau tidak*/

boolean bekas_meteor(List snake,int x,int y,char input);
/* IS: Sembarang
   FS: memeriksa apakah suatu koordinat merupakan bekas meteor atau bukan dan bisaa untuk dilewati*/

boolean tambah_panjang(int X,int Y,List snake,int X1,int Y1, int X2, int Y2);
/* IS: Sembarang
   FS: memeriksa apakah pertambahan panjang bisa dilakukan */
void meteor(int *X,int *Y,List snake);
/* IS: Sembarang
   FS: spawn meteor*/

void SNAKEONMETEOR(int *skor);
// Desc: Menjalankan game snake
/* IS: Sembarang
   FS: Menghasilkan skor akhir dari game snake */

#endif