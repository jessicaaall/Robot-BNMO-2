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
    while ((CC != ENTER) && (i <= NMax) && (!EOP)) {
        CWord.TabWord[i] = CC;
        ADV();
        i++;
    }
    if(CC == ENTER || EOP) {
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

void STARTCOMMAND2() {
    STARTC();
    IgnoreBlanks();
    if (CC == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND2();
    }
}
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = ENTER;
          atau EndWord = false, CommandCC adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND2() {
    if (CC == ENTER) {
        EndWord = true;
    } else {
        CopyCommand2();
        IgnoreBlanks();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CommandCC adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCommand2 */

void CopyCommand2() {
    int i = 0;
    while ((CC != ENTER) && (i < NMax)) {
        CommandCC.TabWord[i] = CC;
        ADVC();
        i++;
    }
    CommandCC.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam CommandCC
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CommandCC berisi kata yang sudah diakuisisi;
          CC = ENTER;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */



/* *** FUNGSI DAN PROSEDUR TAMBAHAN *** */

void PrintWord(Word kata) {
    int i;
    for (i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
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
/* Mengirimkan panjang string */

int WordToInt(Word kata) {
    int i, sum = 0;
    for (i = 0; i < kata.Length; i++) {
        if (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9') {
            sum = sum*10 + (kata.TabWord[i] - '0');
        }
    }
    return sum;
}
/* Mengubah kata menjadi integer */

boolean IsWordAnInt(Word input) {
    boolean valid = true;
    int i = 0;
    while ((valid) && (i < input.Length)) {
        if (!((input.TabWord[i] >= '0') && (input.TabWord[i] <= '9'))) {
            valid = false;
        }
        i++;
    }
    return valid;
}
Word IntToWord(int number) {
    Word temp, kata;
    int i = 0, angka;

    temp.Length = 0;
    do {
        angka = number % 10;
        temp.TabWord[i] = angka + '0';
        temp.Length++;
        number = number / 10;
        i++;
    } while (number != 0);

    kata.Length = temp.Length;
    for (i = 0; i < kata.Length; i++) {
        kata.TabWord[i] = temp.TabWord[kata.Length-1-i];
    }

    return kata;
}
/* Mengubah integer menjadi kata */

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
    *c1 = StringToWord("");
    *c2 = StringToWord("");
	STARTCOMMAND();
	if (!EndWord) {
		*c1 = WordUpper(CommandCC);
		ADVCOMMAND2();
		if (!EndWord) {
            if (!(IsWordSame(*c1, StringToWord("SAVE")))) {
                *c2 = WordUpper(CommandCC);
            } else {
                *c2 = CommandCC;
            }
		}
	}
} 
/* Memisahkan kata pertama dan kata kedua yang diambil stdin 
   I.S. : Sembarang 
   F.S. : c1 adalah kata pertama dan c2 adalah kata kedua yang diambil stdin 
          dengan c1 dan c2 di-upper */

void InitialScan(Word *c1, Word *c2) {
    *c1 = StringToWord("");
    *c2 = StringToWord("");
	STARTCOMMAND();
	if (!EndWord) {
		*c1 = WordUpper(CommandCC);
		ADVCOMMAND2();
		if (!EndWord) {
			*c2 = CommandCC;
		}
	}
}
/* Memisahkan kata pertama dan kata kedua yang diambil stdin 
   I.S. : Sembarang 
   F.S. : c1 adalah kata pertama dan c2 adalah kata kedua yang diambil stdin 
          dengan c1 di-upper dan c2 tidak di-upper */

Word WordUpper(Word kata) {
	for (int i = 0; i < kata.Length; i++) {
		if ((kata.TabWord[i] >= 'a') && (kata.TabWord[i] <= 'z')) {
			kata.TabWord[i] -= 32;
		}
	}
	return kata;
}
/* Mengirimkan kata yang telah di-upper */

boolean ValidTxt(Word txt) {
    boolean check = false;
    if (txt.Length>=5) {
	    if (txt.TabWord[txt.Length-4]=='.') {
        	if (txt.TabWord[txt.Length-3]=='t') {
            	if (txt.TabWord[txt.Length-2]=='x') {
                	if (txt.TabWord[txt.Length-1]=='t') {
                    	check = true;
                    }
                }
            }
        }
    }
    return check;
}
/* Mengirimkan true apabila txt memiliki .txt di akhir */


void SplitWord(Word kata, Word *kata1, Word *kata2) {
    int i = 0, j = 0;

    *kata1 = StringToWord("");
    *kata2 = StringToWord("");

    while ((i < kata.Length) && (kata.TabWord[i] != BLANK)) {
        (*kata1).TabWord[i] = kata.TabWord[i];
        (*kata1).Length++;
        i++;
    }
    i++;

    while (i < kata.Length) {
        (*kata2).TabWord[j] = kata.TabWord[i];
        (*kata2).Length++;
        i++;
        j++;
    }
}
/* Memisahkan Word kata menjadi Word kata1 dan Word kata2 */
/* I.S. kata terdefinisi, dengan kata pertama dan kata kedua dipisahkan oleh spasi */
/* F.S. kata1 merupakan kata pertama pada kata dan kata2 merupakan kata kedua pada kata */