#include "./ADT/Array/array.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    // WELKAM
    // Ada Tampilan keren
    // Ada menu (START, LOAD, EXIT)
    boolean isExit = false;
	Word command1 = StringToWord("\0");
	Word command2 = StringToWord("\0");
    Word START = StringToWord("START");
    Word LOAD = StringToWord("LOAD");
    Word EXIT = StringToWord("EXIT");
    Tab arrayGame;
    char *strout;
    MakeEmptyArray(&arrayGame);
	printf("Masukan command :");
	InitialScan(&command1, &command2);
    if (compareWord(command1, EXIT)) {
        isExit = true;
        printf("Ini Exit ges\n");
        printf("command1 : %s\n", command1.TabWord);
		printf("panjang1 : %d\n", command1.Length);
    } else if (compareWord(command1, START)) {
        printf("Ini Start ges\n");
        printf("command1 : %s\n", command1.TabWord);
		printf("panjang1 : %d\n", command1.Length);
    } else if (compareWord(command1, LOAD)) {
		printf("Ini Load ges\n");
		load(command2.TabWord, &arrayGame);
		printf("berhasil load\n");
		for (int i = 0; i < NbElmtArray(arrayGame); i++) {
			printf("isi file : %s\n", arrayGame.TI[i].TabWord);
		}
		printf("Neff : %d\n", arrayGame.Neff);
    }
    while (isExit == false) {
		printf("Masukan command :");
        Scan(&command1, &command2);
		if (compareWord(command1, EXIT)) {
			isExit = true;
		}
    }
}

void concatStr(char *str1, char *str2, char *str3) {
    int i = 0;
    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    int j = 0;
    while (str2[i] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';
}

boolean compareWord(Word K1, Word K2) {
    if (K1.Length != K2.Length) {
        return false;
    } else {
        int i = 0;
        while (i < K1.Length) {
            if (K1.TabWord[i] != K2.TabWord[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
}