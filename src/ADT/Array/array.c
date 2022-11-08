#include "../../boolean.h"
#include "array.h"
#include <stdio.h>

void MakeEmptyArray (Tab *T){
	(*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (Tab T){
	return ((T).Neff);
}

int MaxNbElArray (Tab T){
	return (IdxMax - IdxMin + 1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArray (Tab T){
	return (IdxMin);
}

IdxType GetLastIdxArray (Tab T){
	return ((T).Neff);
}

ElType GetElmtArray (Tab T, IdxType i){
	return ((T).TI[(i)]);
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArray (Tab Tin, Tab *Tout){
	*Tout = Tin;
}

void SetElArray (Tab *T, IdxType i, ElType v){
	(*T).TI[(i)] = v ;
}

void SetNeffArray (Tab *T, IdxType N){
	(*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArray (Tab T, IdxType i){
	return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEffArray (Tab T, IdxType i){
	return ((i >= GetFirstIdxArray(T)) && (i <= GetLastIdxArray(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (Tab T){
	return (NbElmtArray(T) == 0);
}

boolean IsFullArray (Tab T){
	return (NbElmtArray(T) == (IdxMax - IdxMin + 1));
}