/* File : mesinkata.h */
/* Definisi Mesin Kata : Model Akuisisi Versi I */

#ifndef __MESIN_KATA_H__
#define __MESIN_KATA_H__

#include "../../boolean.h"
#include "../MesinKarakter/mesinkarakter.h"

#define NMax 1000
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


/* *** FUNGSI DAN PROSEDUR TAMBAHAN *** */

void PrintWord(Word kata);
/* Mencetak kata ke layar
   I.S. : kata terdefinisi
   F.S. : kata tercetak pada layar */

int LengthOfString(char* string);
/* Mengirimkan panjang string*/

void WordToString (Word kata, char* string);
/* Mengubah kata menjadi string 
   I.S. : kata terdefinisi 
   F.S. : string berisi elemen array kata */

Word StringToWord(char* string);
/* Mengirimkan Word yang elemen arraynya adalah string */

boolean IsWordSame(Word kata1, Word kata2);
/* Mengirimkan true apabila kata1 sama dengan kata2 */
void Scan(Word *c1, Word *c2);

void InitialScan(Word *c1, Word *c2);

Word WordUpper(Word kata);

#endif