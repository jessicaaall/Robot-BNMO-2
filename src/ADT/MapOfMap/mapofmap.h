/* File : map.h */

#ifndef __MAP_OF_MAP_H__
#define __MAP_OF_MAP_H__

#include <stdio.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"
#include "../Map/map.h"

/* MODUL Map Of Map
Deklarasi map of map dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nul 0
#define MaxElmnt 500

// typedef int bool;
typedef Word keyMtype;
typedef Map valueMtype;
typedef int elmntcount;

typedef struct
{
	keyMtype KeyM;
	valueMtype ValueM;
} elmnttype;

typedef struct
{
	elmnttype Elmnt[MaxElmnt];
	elmntcount ElCount;
} MapOfMap;

/* Definisi Map Of Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map Of Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMapOfMap(MapOfMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map Of Map M kosong berkapasitas MaxEl */
/* Ciri Map Of Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapOfMapEmpty(MapOfMap M);
/* Mengirim true jika Map Of Map M kosong*/
/* Ciri Map Of Map kosong : count bernilai Nil */

boolean IsMapOfMapFull(MapOfMap M);
/* Mengirim true jika Map Of Map M penuh */
/* Ciri Map Of Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valueMtype ValueM(MapOfMap M, keyMtype k);
/* Mengembalikan nilai value dengan key k dari M */


void InsertM(MapOfMap *M, keyMtype k, valueMtype v);
/* Menambahkan Elmt sebagai elemen Map Of Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteM(MapOfMap *M, keyMtype k);
/* Menghapus Elmt dari Map Of Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberM(MapOfMap M, keyMtype k);
/* Mengembalikan true jika k adalah member dari M */

#endif