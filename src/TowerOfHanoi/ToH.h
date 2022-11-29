#ifndef TOH_H
#define TOH_H

#include "../boolean.h"
#include "../ADT/MesinKata/mesinkata.h"
#include <math.h>

#define Nill -1
#define MaxS 100

typedef struct {
    int buffer[MaxS];
    int TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).buffer[(S).TOP]

void CreateSEmpty (Stack *S);
// Desc: Membuat Stack kosong
/* IS: Stack sembarang
   FS: Stack S kosong */

boolean IsSEmpty (Stack S);
/* Mengirim true apabila Stack kosong, yaitu TOP bernilai Nil */

void PushS(Stack *S, int X);
// Desc: Memasukkan integer S ke Stack S dengan aturan LIFO (Last In, First Out)
/* IS: Stack S terdefinisi, mungkin kosong
   FS: integer X sebagai elemen Top pada stack S*/

void PopS(Stack *S, int *X);
// Desc: Mengeluarkan elemen Top pada Stack S
/* IS: Stack S terdefinisi, tidak kosong
   FS: Elemen Top Stack S akan disimpan di X, kemudian dikeluarkan dari Stack S*/

int JumlahMaksBintang (int piringan);
// Desc: Mengembalikan jumlah maksimal bintang pada piringan tertentu

void InisialisasiS (Stack *S, int piringan);
// Desc: Menginisialisasi jumlah piringan pada Stack A
/* IS: Stack A kosong
   FS: Stack A sudah terisi piringan yang sesuai */

int LengthS (Stack S);
// Desc: Mengembalikan panjang dari Stack S

void GetInt (Word in, int *i);
// Desc: Mengubah Word in menjadi integer i
/* IS: Word in terdefinisi
   FS: Apabila Word in merupakan integer <= 500, menghasilkan integer i sesuai Word in yang terdefinisi 
       Di luar itu, menghasilkan integer i berupa 0 */

void PrintBintang (int n, int piringan);
// Desc: Mencetak bintang berjumlah n, berdasarkan piringan tertentu
/* IS: n dan piringan terdefinisi. n merupakan bagian dari piringan
   FS: Bintak tercetak */

void DisplayStack (Stack S, int piringan);
// Desc: Mencetak Stack of Bintang
/* IS: Stack of integer S terdefinisi
   FS: akan tercetak Stack of Bintang sesuai dengan integer pada Stack S*/

Stack GetStack(char input, Stack a, Stack b, Stack c);
// Desc: Mengembalikan Stack dengan input tertentu
// input = 'a' | 'A' ; return Stack a
// input = 'b' | 'B' ; return Stack b
// input = 'c' | 'C' ; return Stack c

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

boolean IsCommandSValid (char src, char dst, Stack a, Stack b, Stack c);
// Desc: Return True jika command valid
/* command valid jika: 
- Top dari Stack src < Top dari Stack dst
- src != dst
- Stack src tidak kosong
*/
// Akan terjadi konversi char src menjadi Stack src dan char dst menjadi Srack dst

void ProsesCommandS (char src, char dst, Stack *a, Stack *b, Stack *c);
// Desc: Memindahkan piringan dari Source src ke Destinasi dst
/* IS: Source, Destinasi, Stack a, Stack b, Stack c yang valid
   FS: Piringan dipindahkan dari Stack src ke Stack dst
       (akan terjadi konversi char src ke Stack src dan char dst ke Stack dst) */

boolean GameFinish (Stack S, int piringan);
// Desc: Menentukan apakah game berakhir
// Game berakhir jika Stack C penuh

int CountScore (int step, int piringan);
// Desc: Menghitung skor game berdasarkan jumlah piringan dan step yang telah dilakukan
// rumus StepMaksimum : (2^piringan)-1
// Jika step pemain > dari StepMaksimum, akan terjadi pengurangan 1 poin setiap step
// Poin minimum yang didapatkan pengguna adalah 1

#endif