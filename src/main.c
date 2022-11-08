#include "./ADT/Array/array.h"
#include "./ADT/MesinKataKar/mesin_kar.h"
#include "./ADT/MesinKataKar/mesin_kata.h"

int main() {
    
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