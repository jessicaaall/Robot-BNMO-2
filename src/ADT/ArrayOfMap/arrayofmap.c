#include "arrayofmap.h"
#include <stdio.h>


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrMap (TabMap *T) {
    (*T).Nelmt = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap (TabMap T) {
    return (T.Nelmt);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbElArrMap (TabMap T) {
    return (IdxMaxArrMap - IdxMinArrMap + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */


/* *** Selektor INDEKS *** */
IndxType GetFirstIdxArrMap (TabMap T) {
    return (IdxMinArrMap);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */

IndxType GetLastIdxArrMap (TabMap T) {
    return (T.Nelmt-1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */


/* *** Menghasilkan sebuah elemen *** */
MapType GetElmtArrMap (TabMap T, IndxType i) {
    return (T.Elmt[i]);
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArrMap (TabMap Tin, TabMap *Tout) {
    (*Tout) = Tin;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */

void SetElArrMap (TabMap *T, IndxType i, MapType v) {
	(*T).Elmt[(i)] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeffArrMap (TabMap *T, IndxType N) {
    (*T).Nelmt = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */


/* ********** Test Indeks yang valid ********** */
boolean IsIndxValid (TabMap T, IndxType i) {
    return ((i >= IdxMinArrMap) && (i <= IdxMaxArrMap));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIndxEff (TabMap T, IndxType i) {
    return ((i >= GetFirstIdxArrMap(T)) && (i <= GetLastIdxArrMap(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap (TabMap T) {
    return (T.Nelmt == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */


/* *** Test tabel penuh *** */
boolean IsFullArrMap (TabMap T) {
    return (T.Nelmt == IdxMaxArrMap);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */