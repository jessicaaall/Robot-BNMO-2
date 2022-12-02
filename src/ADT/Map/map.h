/* File : map.h */

#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

/* MODUL Map
Deklarasi map dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nol 0
#define MaxElements 90

// typedef int bool;
typedef Word keytype;
typedef int valuetype;
typedef int countelmt;

typedef struct
{
	keytype Key;
	valuetype Value;
} infotype;

typedef struct
{
	infotype Elements[MaxElements];
	countelmt Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsMapFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */

void Insert(Map *M, keytype k, valuetype v);
/* Menambahkan Elements dengan keytype k dan valuetype v sebagai elemen terakhir Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void InsertSort(Map *M, keytype k, valuetype v);
/* Menambahkan Elements dengan keytype k dan valuetype v sebagai elemen Map M berdasarkan nilai v */
/* I.S. M mungkin kosong, M tidak penuh, dengan value yang terurut mengecil
		M mungkin sudah beranggotakan v dengan key k */
/* F.S. Jika k belum ada, v menjadi anggota dari M dengan key k, M memiliki value yang terurut mengecil 
		Jika k sudah ada, operasi tidak dilakukan */

int MaxKeyLength(Map M);
/* Mengembalikan panjang maksimum dari key pada Map M */

#endif