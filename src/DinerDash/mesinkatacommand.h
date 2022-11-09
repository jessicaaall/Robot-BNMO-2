/* File : mesinkatacommand.h */
/* Definisi Mesin Kata : Model Akuisisi Versi I */

#ifndef __MESIN_KATA_COMMAND_H__
#define __MESIN_KATA_COMMAND_H__

#include "boolean.h"
#include "mesinkarcommand.h"

#define NMax 1000
#define BLANK ' '

typedef struct {
    char TabWord[NMax];
    int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word CommandCC;

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

Word StringToWord(char* string);
/* Mengirimkan Word yang elemen arraynya adalah string */

boolean IsWordSame(Word kata1, Word kata2);
/* Mengirimkan true apabila kata1 sama dengan kata2 */

#endif