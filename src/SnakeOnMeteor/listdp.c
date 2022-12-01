#include <stdio.h>
#include "listdp.h"
#include <stdlib.h>
#include <time.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty (List L){
    return (First(L)==Niil && Last(L)==Niil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
    First(*L)=Niil;
    Last(*L)=Niil;
    if (random3()==2 &&random4()==3){
        InsVLast(L,random3(),random5());
        InsVLast(L,random3(),random5()-1);
        InsVLast(L,random3()-1,random5()-1);
        }
    else if (random3()==2 &&random4()==2){
        InsVLast(L,random3(),random5());
        InsVLast(L,random3()-1,random5());
        InsVLast(L,random3()-2,random5());
        }
    
    else if (random3()==2 && (random4()==4)){
        InsVLast(L,random3(),random4());
        InsVLast(L,random3(),random4()-1);
        InsVLast(L,random3()-1,random4()-1);
        }    
    else{
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
    }
    
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addresslist Alokasi (infotypelist X,infotypelist Y){
    addresslist P;
    P = (addresslist)malloc(sizeof(ElmtList));

    if (P != Niil) {
        X(P) = X;
        Y(P) = Y;
        Next(P) = Niil;
        Prev(P)=Niil;
        return P;
    }
    else {
        return Niil;
    }
}
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak Niil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Niil, Prev(P)=Niil */
/* Jika alokasi gagal, mengirimkan Niil. */
void Dealokasi (addresslist P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addresslist SearchList (List L, infotypelist X,infotypelist Y){
    addresslist P;
    boolean found;
    P = First(L);
    found = false;
    while (Next(P)!=Niil && !found){
        if (X(Next(P))==X && Y(Next(P))==Y){
            found=true;
        }
        else {
            P = Next(P);
        }
    }
    if (!found){
        return Niil;
    }
    else{
        return P;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addresslist elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

void InsVLast (List *L, infotypelist X,infotypelist Y){
    addresslist P;

    P = Alokasi(X,Y);

    if (P != Niil) {
        InsertLast(L, P);
    }
}

void DelVLast (List *L){
    addresslist P;
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

void InsertLast (List *L, addresslist P){
    if (IsListEmpty(*L)) {
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
void DelLast (List *L, addresslist *P){
    (*P) = Last(*L);

    if (Prev(Last(*L)) == Niil) {
        First(*L) = Niil;
        Last(*L) = Niil;
    }
    else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Niil;
    }

    Prev(*P) = Niil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void DelP(List *L, addresslist P){
    addresslist X;
    X = Next(P);
    Next(P)=Next(Next(P));
    Prev(Next(P)) = P;
    Dealokasi(X);
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int LengthList (List L){
    int i=0;
    addresslist P;
    P = First(L);
    while (P!=Niil){
        P=Next(P);
        i++;
    }
    return i;
}

boolean meteor_kena_kepala(List L,infotypelist X, infotypelist Y){
    boolean check = false;
    if (X(First(L))==X && Y(First(L))==Y){
            check=true;
        }
    else{
        check=false;
    }
    return check;
}

boolean meteor_kena_badan(List L,infotypelist X, infotypelist Y){
    boolean check = false;
    addresslist P;
    P = First(L);
    while (Next(P)!=Niil && !check){
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
    srand(time(0)+time(0)*3/3);
    int i =(rand()%5);
    return i;
}
int random5(){
    return random4()-2;
}

