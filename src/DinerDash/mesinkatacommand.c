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


/* *** FUNGSI DAN PROSEDUR TAMBAHAN *** */
void PrintWord(Word kata) {
    int i;
    for (i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
    printf("\n");
}
/* Mencetak kata ke layar
   I.S. : kata terdefinisi
   F.S. : kata tercetak pada layar */

int LengthOfString(char* string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}
/* Mengirimkan panjang string*/

Word StringToWord(char* string) {
    Word kata;
    int panjangstring = LengthOfString(string);
    int i;

    for (i = 0; i < panjangstring; i++) {
        kata.TabWord[i] = string[i];
    }
    kata.Length = panjangstring;

    return kata;
}
/* Mengirimkan Word yang elemen arraynya adalah string */

boolean IsWordSame(Word kata1, Word kata2) {
    boolean sama = true;
    int i = 0;

    if (kata1.Length != kata2.Length) {
        sama = false;
    } else {
        while ((i < kata1.Length) && (sama)) {
            if (kata1.TabWord[i] != kata2.TabWord[i]) {
                sama = false;
            }
            i++;
        }
    }

    return sama;
}
/* Mengirimkan true apabila kata1 sama dengan kata2 */
