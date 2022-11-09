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
    char *curentComand;
    Word START = StringToWord("START");
    Word LOAD = StringToWord("LOAD");
    Word EXIT = StringToWord("EXIT");
    STARTCOMMAND();
    WordToString(CommandCC, curentComand);
    if (compareWord(CommandCC, START)) {
        Start();
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