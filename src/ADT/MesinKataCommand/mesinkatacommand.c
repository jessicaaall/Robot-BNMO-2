#include "mesinkatacommand.h"

boolean EndWord;
Word CommandCC;

void IgnoreBlanks() {
    while (CC == BLANK) {
        ADVC();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENTER */

void STARTCOMMAND() {
    STARTC();
    IgnoreBlanks();
    if (CC == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = ENTER;
          atau EndWord = false, CommandCC adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND() {
    if (CC == ENTER) {
        EndWord = true;
    } else {
        CopyCommand();
        IgnoreBlanks();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CommandCC adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCommand */

void CopyCommand() {
    int i = 0;
    while ((CC != ENTER) && (i < NMax)) {
        if ((CC >= 'a') && (CC <= 'z')) {
            CC -= 32;
        }
        CommandCC.TabWord[i] = CC;
        ADVC();
        i++;
    }
    CommandCC.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam CommandCC
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CommandCC berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */