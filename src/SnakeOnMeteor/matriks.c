#include "matriks.h"
#include <stdio.h>

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Ceff untuk mengetahui banyaknya elemen
 * T.TM untuk mengakses seluruh nilai elemen tabel
 * T.TM[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Ceff = 0
 * Definisi elemen pertama : T.TM[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TM[i] dengan i=T.Ceff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyMatriks (matriks *M){
    int i,j;
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            (*M).TM[i][j]= 0;
        }
    }
}

void Display(matriks M){
    int i, j, k;

    printf("%c%c", 201, 205);
    for (i = 0; i < 10; i++) {
            printf("%c%c",205,205);
    }
    printf("%c\n",187);
    
    for (i = 0; i < 5; i++){
        printf("%c ",186);
        for (j = 0; j < 5; j++){
            if (M.TM[i][j] == 0){
                printf("   ");
            } else if (M.TM[i][j] == 999){
                printf(" H ");
            } else if(M.TM[i][j] == -1){
                printf(" o ");
            } else if(M.TM[i][j] == -2){
                printf(" M ");
            } else {
                printf(" %d ", M.TM[i][j]); 
            }
            if (j != 4) {
                printf("%c",179);
            } else {
                printf(" ");
            }
        }
        printf("%c\n",186);
        if (i != 4) {
            printf("%c ",186);
            for (k = 0; k < 4; k++) {
                printf("%c%c%c%c", 196, 196, 196,197);
            }
            printf("%c%c%c ", 196, 196, 196);
            printf("%c\n",186);
        }
    }

    printf("%c%c", 200, 205);
    for (i = 0; i < 10; i++){
            printf("%c%c", 205, 205);
    }
    printf("%c\n",188);
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

