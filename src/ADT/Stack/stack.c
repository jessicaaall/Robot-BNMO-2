#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S) {
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S) {
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong, yaitu TOP bernilai Nil */

boolean IsStackFull(Stack S) {
    return (Top(S) == MaxEl-1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */


/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, info X) {
    Top(*S)++;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */


/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, info *X) {
    *X = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


/* *** FUNGSI DAN PROSEDUR TAMBAHAN *** */
void InverseStack (Stack stackin, Stack *stackout) {
    info el;

    while (!IsStackEmpty(stackin)) {
        Pop(&stackin, &el);
        Push(stackout, el);
    }
}
/* Membalik elemen Stack */
/* I.S. stackin terdefinisi, mungkin kosong */
/* F.S. stackout adalah stackin dengan elemen yang telah dibalik */