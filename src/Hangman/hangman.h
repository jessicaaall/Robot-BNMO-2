/* File : hangman.h */

#ifndef __HANGMAN_H__
#define __HANGMAN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/array.h"


void readfile(char *filename, Tab *listkata);
/* Membaca filename.txt, lalu menyimpan isi filename.txt ke dalam Tab listkata */
/* I.S. filename terdefinisi, dengan isi file yang mungkin kosong */
/* F.S. listkata berisi isi dari filename.txt */

void writefile(char *filename, Tab listkata);
/* Menyimpan isi Tab listkata ke dalam filename.txt */
/* I.S. filename terdefinisi
        listkata terdefinisi, mungkin kosong */
/* F.S. filename.txt berisi isi dari Tab listkata */

int randomword(Tab listkata);
/* Mengembalikan integer random antara 0 sampai indeks efektif terakhir Tab listkata */

void HANGMAN(int *skor);
/* Proses : Membaca list kata dari file
            Terdapat 2 menu ketika memulai permainan, yaitu bermain langsung atau menambah kata-kata ke dalam list kata 
            Pada awal permainan, program menentukaan sebuah kata yang harus ditebak oleh pemain
            Pemain diberikan 10 kesempatan untuk melakukan penebakan huruf yang tidak terdapat dalam kata
            Pada setiap giliran, pemain menebak satu huruf yang terdapat pada kata 
            Apabila huruf tebakan terdapat dalam kata, maka huruf yang sudah tertebak akan ditampilkan pada layar 
            Apabila salah, maka pemain kehilangan satu kesempatan 
            Pemain tidak boleh menebak huruf yang sudah ditebak sebelumnya pada kata yang sama 
            Apabila pemain berhasil menebak suatu kata, maka pemain tersebut diberikan poin sesuai dengan panjang kata yang berhasil ditebak,
            kemudian program memberikan kata baru yang harus ditebak oleh pemain dengan jumlah kesempatan yang tersisa
            Permainan berlanjut hingga kesempatan untuk menebak huruf yang salah telah habis */
/* I.S. File yang berisi daftar kata terdefinisi */
/* F.S. Daftar kata pada file mungkin bertambah
        Menghasilkan skor akhir dari permainan Hangman */

#endif