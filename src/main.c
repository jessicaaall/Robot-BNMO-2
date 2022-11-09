#include "./ADT/Array/array.h"
#include "./ADT/MesinKataKar/mesin_kar.h"
#include "./ADT/MesinKataKar/mesin_kata.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    // WELKAM
    // Ada Tampilan keren
    // Ada menu (START, LOAD, EXIT)
    char *dir = "../../savefile/";
    static FILE *pita;
    char CC;
    int retval;
    pita = stdin;
    return 0;
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

boolean compareKata(Kata K1, Kata K2) {
    if (K1.Length != K2.Length) {
        return false;
    } else {
        int i = 1;
        while (i <= K1.Length) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
}
