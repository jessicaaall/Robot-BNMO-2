/* 
NIM                 : 18221085
Nama                : Nalendro N.U.A.R.F
Tanggal             : 13 oktober 2022
Topik praktikum     : variasi list linear
Deskripsi           : implementasi listdp.c

*/

#include <stdio.h>
#include "listdp.h"
#include <stdlib.h>
#include <time.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L)==Nil && Last(L)==Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L)=Nil;
    Last(*L)=Nil;
    InsVLast(L,random3(),random4());
    if (random4()>0){
        InsVLast(L,random3(),random4()-1);
        if (random4()>1){
            InsVLast(L,random3(),random4()-2);
        }
        else{
            if (random3()>0){
                InsVLast(L,random3()-1,random4()-1);
            }
            else{
                InsVLast(L,random3()+1,random4()-1);
            }
        }
    }
    else{
        if (random3()==0){
            InsVLast(L,random3()+1,random4());
            InsVLast(L,random3()+2,random4());
        }
        else if (random3()==1){
            InsVLast(L,random3()-1,random4());
            InsVLast(L,random3()-1,random4()+1);
        }
        else{
            InsVLast(L,random3()-1,random4());
            InsVLast(L,random3()-2,random4());
        }
        
    }
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X,infotype Y){
    address P;
    P = (address)malloc(sizeof(ElmtList));

    if (P != Nil) {
        X(P) = X;
        Y(P) = Y;
        Next(P) = Nil;
        Prev(P)=Nil;
        return P;
    }
    else {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X,infotype Y){
    address P;
    boolean found;
    P = First(L);
    found = false;
    while (Next(P)!=Nil && !found){
        if (X(Next(P))==X && Y(Next(P))==Y){
            found=true;
        }
        else {
            P = Next(P);
        }
    }
    if (!found){
        return Nil;
    }
    else{
        return P;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

void InsVLast (List *L, infotype X,infotype Y){
    address P;

    P = Alokasi(X,Y);

    if (P != Nil) {
        InsertLast(L, P);
    }
}

void DelVLast (List *L){
    address P;
    DelLast(L, &P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void InsertLast (List *L, address P){
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    }
    else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void DelLast (List *L, address *P){
    (*P) = Last(*L);

    if (Prev(Last(*L)) == Nil) {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }

    Prev(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void DelP(List *L, address P){
    address X;
    X = Next(P);
    Next(P)=Next(Next(P));
    Prev(Next(P)) = P;
    Dealokasi(X);
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int Length (List L){
    int i=0;
    address P;
    P = First(L);
    while (P!=Nil){
        P=Next(P);
        i++;
    }
    return i;
}

boolean meteor_kena_kepala(List L,infotype X, infotype Y){
    boolean check = false;
    if (X(First(L))==X && Y(First(L))==Y){
            check=true;
        }
    else{
        check=false;
    }
    return check;
}

boolean meteor_kena_badan(List L,infotype X, infotype Y){
    boolean check = false;
    address P;
    P = First(L);
    while (Next(P)!=Nil && !check){
        if (X(P)==X && Y(P)==Y){
            check = true;
        }
        else{
            P = Next(P);
        }
    }
    return check;
}

int random1() {
    srand(time(0));
    int i =(rand()%4)+1;
    return i;
}
int random2() {
    srand(time(0)+time(0));
    int i =(rand()%5);
    return i;
}

int random3() {
    srand(time(0)*time(0)-231/time(0));
    int i =(rand()%4)+1;
    return i;
}
int random4() {
    srand(time(0)+time(0)*3/5);
    int i =(rand()%5);
    return i;
}

