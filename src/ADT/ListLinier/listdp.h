/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#ifndef LISTDP_H
#define LISTDP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../boolean.h"

#define Niil NULL

/* Definisi Type Data */
typedef int infotypelist;
typedef struct tElmtlist *addresslist;
typedef struct tElmtlist { 
	infotypelist x;
	infotypelist y;
	addresslist next;
	addresslist prev;
} ElmtList;
typedef struct {
	addresslist First;
	addresslist Last;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addresslist P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define X(P) (P)->x
#define Y(P) (P)->y
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list dengan 3 element. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addresslist Alokasi (infotypelist X,infotypelist Y);
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (addresslist P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addresslist SearchList (List L, infotypelist X,infotypelist Y);
/* Mencari apakah ada elemen list dengan X(P)=X dan Y(P)=X */
/* Jika ada, mengirimkan addresslist elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast (List *L, infotypelist X,infotypelist Y);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void DelVLast (List *L);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void InsertLast (List *L, addresslist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void DelLast (List *L, addresslist *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void DelP (List *L, addresslist P);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int LengthList(List L);
/* I.S. sembarang*/
/* F.S. return panjang list*/

// Menghasilkan angka random
int random1();
int random2();
int random3();
int random4();
int random5();
// I.S sembarang
// F.S menghasilkan angka random

#endif
