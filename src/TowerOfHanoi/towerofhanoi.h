/* File : towerofhanoi.h */

#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <math.h>
#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Stack/stackToH.h"

int JumlahMaksBintang (int piringan);
// Desc: Mengembalikan jumlah maksimal bintang pada piringan tertentu

void InisialisasiS (StackToH *S, int piringan);
// Desc: Menginisialisasi jumlah piringan pada StackToH A
/* IS: StackToH A kosong
   FS: StackToH A sudah terisi piringan yang sesuai */

void GetInt (Word in, int *i);
// Desc: Mengubah Word in menjadi integer i
/* IS: Word in terdefinisi
   FS: Apabila Word in merupakan integer <= 500, menghasilkan integer i sesuai Word in yang terdefinisi 
       Di luar itu, menghasilkan integer i berupa 0 */

void PrintBintang (int n, int piringan);
// Desc: Mencetak bintang berjumlah n, berdasarkan piringan tertentu
/* IS: n dan piringan terdefinisi. n merupakan bagian dari piringan
   FS: Bintak tercetak */

void DisplayStack (StackToH S, int piringan);
// Desc: Mencetak StackToH of Bintang
/* IS: StackToH of integer S terdefinisi
   FS: akan tercetak StackToH of Bintang sesuai dengan integer pada StackToH S*/

StackToH GetStack(char input, StackToH a, StackToH b, StackToH c);
// Desc: Mengembalikan StackToH dengan input tertentu
// input = 'a' | 'A' ; return StackToH a
// input = 'b' | 'B' ; return StackToH b
// input = 'c' | 'C' ; return StackToH c

boolean IsPiringanValid (int piringan);
// Desc: Return True jika jumlah piringan valid
// piringan valid jika > 0

void GetChar (Word in1, Word in2, char *c);
// Desc: Mengubah Word in menjadi Char c
/* IS: Word in sembarang
   FS: Apabila Word in merupakan karakter A-Z, Char c merupakan karakter yang sesuai Word in
       Apabila Word in bukan karakter A-Z, Char c = 'Z' */

boolean IsInputValid (char src, char dst);
// Desc: Return True jika Input src dan dst valid
// input src dan dst valid jika src dan dst merupakan karakter A, B, atau C

boolean IsCommandSValid (char src, char dst, StackToH a, StackToH b, StackToH c);
// Desc: Return True jika command valid
/* command valid jika: 
- TopS dari StackToH src < TopS dari StackToH dst
- src != dst
- StackToH src tidak kosong
*/
// Akan terjadi konversi char src menjadi StackToH src dan char dst menjadi Srack dst

void ProsesCommandS (char src, char dst, StackToH *a, StackToH *b, StackToH *c);
// Desc: Memindahkan piringan dari Source src ke Destinasi dst
/* IS: Source, Destinasi, StackToH a, StackToH b, StackToH c yang valid
   FS: Piringan dipindahkan dari StackToH src ke StackToH dst
       (akan terjadi konversi char src ke StackToH src dan char dst ke StackToH dst) */

boolean GameFinish (StackToH S, int piringan);
// Desc: Menentukan apakah game berakhir
// Game berakhir jika StackToH C penuh

int CountScore (int step, int piringan);
// Desc: Menghitung skor game berdasarkan jumlah piringan dan step yang telah dilakukan
// rumus StepMaksimum : (2^piringan)-1
// Jika step pemain > dari StepMaksimum, akan terjadi pengurangan 1 poin setiap step
// Poin minimum yang didapatkan pengguna adalah 1

void TOWEROFHANOI(int *skor);
// Desc: Menjalankan game Tower of Hanoi
/* IS: Sembarang
   FS: Menghasilkan skor akhir dari game Tower Of Hanoi */

#endif