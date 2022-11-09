#include "mesinkata.h"

boolean EndWord;
Word CWord;
Word CommandCC;


/* *** ADT Mesin Kata untuk Baca File Eksternal *** */

void IgnoreBlank() {
    while (((CC == BLANK) || (CC == ENTER)) && (!EOP)) {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENTER */

void CopyWord() {
    int i = 0;
    while ((CC != ENTER) && (CC != BLANK) && (i <= NMax) && (!EOP)) {
        CWord.TabWord[i] = CC;
        ADV();
        i++;
    }
    if(CC == ENTER || CC == BLANK || EOP) {
        CWord.TabWord[i] = '\0';
    }
    CWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
void STARTWORD(char * filename) {
    START(filename);
    IgnoreBlank();
    if (CC != ENTER) {
        CopyWord();
    }
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = ENTER;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD() {
    IgnoreBlank();
    if (CC != ENTER) {
        CopyWord();
        IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */


/* *** ADT Mesin Kata untuk Baca Command *** */

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
    while ((CC != ENTER) && (i < NMax) && (CC != BLANK)) {
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

void WordToString (Word kata, char* string) {
    int i;
    for (i = 0; i < kata.Length; i++) {
        string[i] = kata.TabWord[i];
    }
    string[kata.Length] = '\0';
}
/* Mengubah kata menjadi string 
   I.S. : kata terdefinisi 
   F.S. : string berisi elemen array kata */

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


void Scan(Word *c1, Word *c2) {
	STARTCOMMAND();
	if (!EndWord) {
		*c1 = WordUpper(CommandCC);
		ADVCOMMAND();
		if (!EndWord) {
			*c2 = WordUpper(CommandCC);
		}
	}
} 
/* mengembalikan nilai yang dibaca oleh stdin */

void InitialScan(Word *c1, Word *c2) {
	STARTCOMMAND();
	if (!EndWord) {
		*c1 = WordUpper(CommandCC);
		ADVCOMMAND();
		if (!EndWord) {
			*c2 = CommandCC;
		}
	}
} 

Word WordUpper(Word kata) {
	for (int i = 0; i < kata.Length; i++) {
		if ((kata.TabWord[i] >= 'a') && (kata.TabWord[i] <= 'z')) {
			kata.TabWord[i] -= 32;
		}
	}
	return kata;
}

boolean ValidTxt(Word txt){
    boolean check = false;
    if (txt.TabWord[txt.Length-4]=='.'){
        if (txt.TabWord[txt.Length-3]=='t'){
            if (txt.TabWord[txt.Length-2]=='x'){
                if (txt.TabWord[txt.Length-1]=='t'){
                    check = true;
                }
            }
        }
    }
    return check;
}


int LengthFirstWord(Word kata){
    int i= 0;
    while (i<kata.Length && kata.TabWord[i]!=' '){
        i++;
    }
    return i;
}
boolean IsFirstWordSame(Word kata1, Word kata2){
    int i=0;
    boolean check = true;
    if (LengthFirstWord(kata1)==LengthFirstWord(kata2)){
        while (i<LengthFirstWord(kata1) && check){
            if (kata1.TabWord[i]!=kata2.TabWord[i]){
                check=false;
            }
            i++;
        }
    }
    else{
        check = false;
    }
    return check;
}