/*driverarray.c*/
// akses : gcc -o driver ./src/ADT/Array/array.c ./src/ADT/MesinKata/mesinkata.c ./src/ADT/Array/driverarray.c ./src/ADT/MesinKarakter/mesinkarakter.c
#include "../../boolean.h"
#include "array.h"
#include <stdio.h>

int main() {
    Tab T;
    IdxType n = 4;
    Word kata1, kata2, kata3, kata4, kata5;
    
    MakeEmptyArray(&T);
    if (IsEmptyArray(T)) {
        printf("array kosong.\n");
    }
    kata1 = StringToWord("satu");
    kata2 = StringToWord("dua");
    kata3 = StringToWord("tiga");
    kata4 = StringToWord("empat");
    kata4 = StringToWord("empat");
    kata5 = StringToWord("lima");

    SetNeffArray(&T, 5);
    SetElArray(&T, 0, kata1);
    SetElArray(&T, 1, kata2);
    SetElArray(&T, 2, kata3);
    SetElArray(&T, 3, kata4);
    SetElArray(&T, 4, kata5);

    printf("array sudah diisi");
    printf("Neff : %d\n", T.Neff);

    for (IdxType i = 0; i < T.Neff; i++) {
        printf("Elemen index ke-%d: ", i);
        printf("%s\n", &T.TI[i].TabWord);
    }
}