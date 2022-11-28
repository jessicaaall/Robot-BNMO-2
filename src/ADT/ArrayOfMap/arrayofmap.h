/* File : arrayofmap.h */
/* Penempatan elemen selalu rapat kiri */

#ifndef __ARRAY_OF_MAP_H__ 
#define __ARRAY_OF_MAP_H__ 

#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"
#include "../Map/map.h"

/* Kamus Umum */

#define IdxMaxArrMap 499
#define IdxMinArrMap 0
#define IdxUndefArrMap -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IndxType;
typedef Map MapType;

typedef struct 
{
	MapType Elmt [IdxMaxArrMap-IdxMinArrMap+1]; /* memori tempat penyimpan elemen (container) */
	IndxType Nelmt; /* banyaknya elemen efektif */
} TabMap;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah Tab, cara deklarasi dan akses: */
/* Deklarasi : T : Tab */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrMap (TabMap *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap (TabMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArrMap (TabMap T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IndxType GetFirstIdxArrMap (TabMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IndxType GetLastIdxArrMap (TabMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
MapType GetElmtArrMap (TabMap T, IndxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArrMap (TabMap Tin, TabMap *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElArrMap (TabMap *T, IndxType i, MapType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArrMap (TabMap *T, IndxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIndxValid (TabMap T, IndxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIndxEff (TabMap T, IndxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap (TabMap T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArrMap (TabMap T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

#endif
