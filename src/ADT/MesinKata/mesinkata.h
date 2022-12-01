/* File : mesinkata.h */
/* Definisi Mesin Kata : Model Akuisisi Versi I */

#ifndef __MESIN_KATA_H__
#define __MESIN_KATA_H__

#include "../../boolean.h"
#include "../MesinKarakter/mesinkarakter.h"

#define NMax 100
#define BLANK ' '

typedef struct {
    char TabWord[NMax];    /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word CWord;
extern Word CommandCC;


/* *** ADT Mesin Kata untuk Baca File Eksternal *** */

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENTER */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
void STARTWORD(char * filename);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = ENTER;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */


/* *** ADT Mesin Kata untuk Baca Command *** */

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENTER */

void STARTCOMMAND();
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = ENTER;
          atau EndWord = false, CommandCC adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CommandCC adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCommand */

void CopyCommand();
/* Mengakuisisi kata, menyimpan dalam CommandCC
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CommandCC berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTCOMMAND2();
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = ENTER;
          atau EndWord = false, CommandCC adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND2();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CommandCC adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCommand2 */

void CopyCommand2();
/* Mengakuisisi kata, menyimpan dalam CommandCC
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CommandCC berisi kata yang sudah diakuisisi;
          CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


/* *** FUNGSI DAN PROSEDUR TAMBAHAN *** */

void PrintWord(Word kata);
/* Mencetak kata ke layar
   I.S. : kata terdefinisi
   F.S. : kata tercetak pada layar */

int LengthOfString(char* string);
/* Mengirimkan panjang string */

int WordToInt(Word kata);
/* Mengubah kata menjadi integer */

Word IntToWord(int number);
/* Mengubah integer menjadi kata */

void WordToString (Word kata, char* string);
/* Mengubah kata menjadi string 
   I.S. : kata terdefinisi 
   F.S. : string berisi elemen array kata */

Word StringToWord(char* string);
/* Mengirimkan Word yang elemen arraynya adalah string */

boolean IsWordSame(Word kata1, Word kata2);
/* Mengirimkan true apabila kata1 sama dengan kata2 */

boolean IsStringSame(char* str1, char* str2);
/* Mengirimkan true apabila string1 sama dengan string2 */

void Scan(Word *c1, Word *c2);
/* Memisahkan kata pertama dan kata kedua yang diambil stdin 
   I.S. : Sembarang 
   F.S. : c1 adalah kata pertama dan c2 adalah kata kedua yang diambil stdin 
          dengan c1 dan c2 di-upper */

void InitialScan(Word *c1, Word *c2);
/* Memisahkan kata pertama dan kata kedua yang diambil stdin 
   I.S. : Sembarang 
   F.S. : c1 adalah kata pertama dan c2 adalah kata kedua yang diambil stdin 
          dengan c1 di-upper dan c2 tidak di-upper */

Word WordUpper(Word kata);
/* Mengirimkan kata yang telah di-upper */

boolean ValidTxt(Word txt);
/* Mengirimkan true apabila txt memiliki .txt di akhir */

void SplitWord(Word kata, Word *kata1, Word *kata2);
/* Memisahkan Word kata menjadi Word kata1 dan Word kata2 */
/* I.S. kata terdefinisi, dengan kata pertama dan kata kedua dipisahkan oleh spasi */
/* F.S. kata1 merupakan kata pertama pada kata dan kata2 merupakan kata kedua pada kata */

#endif