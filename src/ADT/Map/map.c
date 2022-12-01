#include "map.h"


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M) {
    (*M).Count = Nol;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M) {
    return (M.Count == Nol);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */


boolean IsMapFull(Map M) {
    return (M.Count == MaxElements);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */


/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k) {
    boolean found = false;
    countelmt idx = 0;

    while (!found && idx < M.Count) {
        if (IsWordSame(M.Elements[idx].Key, k)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}
/* Mengembalikan nilai value dengan key k dari M */


void Insert(Map *M, keytype k, valuetype v) {
    if (!IsMember(*M, k)) {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}
/* Menambahkan Elements dengan keytype k dan valuetype v sebagai elemen terakhir Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */


void Delete(Map *M, keytype k) {
    boolean found = false;
    int i = 0, idx;

    while ((i < (*M).Count) && (!found)) {
        if (IsWordSame((*M).Elements[i].Key, k)) {
            idx = i;
            found = true;
        }
        i++;
    }

    if (found) {
        if (((*M).Count != 1) && (idx != (*M).Count-1)) {
            for (i = idx+1; i < (*M).Count; i++) {
                (*M).Elements[i-1].Key = (*M).Elements[i].Key;
                (*M).Elements[i-1].Value = (*M).Elements[i].Value;
            }
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */


boolean IsMember(Map M, keytype k) {
    int i = 0;
    boolean found = false;

    while ((i < M.Count) && (!found)) {
        if (IsWordSame(M.Elements[i].Key, k)) {
            found = true;
        }
        i++;
    }

    return (found);
}
/* Mengembalikan true jika k adalah member dari M */


void InsertSort(Map *M, keytype k, valuetype v){
    int i,j;
    if (!IsMember(*M, k)) {
        for(i=0; i<(*M).Count; i++){
            if(v > (*M).Elements[i].Value){
                break;
            }          
        }
        if(i<(*M).Count){
            for(j=(*M).Count; j>i; j--){
                (*M).Elements[j].Key = (*M).Elements[j-1].Key;
                (*M).Elements[j].Value = (*M).Elements[j-1].Value;
            }
        }
        (*M).Elements[i].Key = k;
        (*M).Elements[i].Value = v;
        (*M).Count++;
    }
}
/* Menambahkan Elements dengan keytype k dan valuetype v sebagai elemen Map M berdasarkan nilai v */
/* I.S. M mungkin kosong, M tidak penuh, dengan value yang terurut mengecil
		M mungkin sudah beranggotakan v dengan key k */
/* F.S. Jika k belum ada, v menjadi anggota dari M dengan key k, M memiliki value yang terurut mengecil 
		Jika k sudah ada, operasi tidak dilakukan */

int MaxKeyLength(Map M) {
    int i, max = 0;
    for (i = 0; i < M.Count; i++) {
        if (M.Elements[i].Key.Length > max) {
            max = M.Elements[i].Key.Length;
        }
    }
    return max;
}
/* Mengembalikan panjang maksimum dari key pada Map M */