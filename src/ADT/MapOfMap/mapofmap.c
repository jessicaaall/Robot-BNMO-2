#include "mapofmap.h"


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMapOfMap(MapOfMap *M) {
    (*M).ElCount = Nol;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map Of Map M kosong berkapasitas MaxEl */
/* Ciri Map Of Map kosong : count bernilai Nil */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapOfMapEmpty(MapOfMap M) {
    return (M.ElCount == Nul);
}
/* Mengirim true jika Map Of Map M kosong*/
/* Ciri Map Of Map kosong : count bernilai Nil */


boolean IsMapOfMapFull(MapOfMap M) {
    return (M.ElCount == MaxElmnt);
}
/* Mengirim true jika Map Of Map M penuh */
/* Ciri Map Of Map penuh : count bernilai MaxEl */


/* ********** Operator Dasar Map ********* */
valueMtype ValueM(MapOfMap M, keyMtype k) {
    boolean found = false;
    elmntcount idx = 0;

    while (!found && idx < M.ElCount) {
        if (IsWordSame(M.Elmnt[idx].KeyM, k)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return M.Elmnt[idx].ValueM;
}
/* Mengembalikan nilai value dengan key k dari M */


void InsertM(MapOfMap *M, keyMtype k, valueMtype v) {
    if (!IsMemberM(*M, k)) {
        (*M).Elmnt[(*M).ElCount].KeyM = k;
        (*M).Elmnt[(*M).ElCount].ValueM = v;
        (*M).ElCount++;
    }
}
/* Menambahkan Elmt sebagai elemen Map Of Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */


void DeleteM(MapOfMap *M, keyMtype k) {
    boolean found = false;
    int i = 0, idx;

    while ((i < (*M).ElCount) && (!found)) {
        if (IsWordSame((*M).Elmnt[i].KeyM, k)) {
            idx = i;
            found = true;
        }
        i++;
    }

    if (found) {
        if (((*M).ElCount != 1) && (idx != (*M).ElCount-1)) {
            for (i = idx+1; i < (*M).ElCount; i++) {
                (*M).Elmnt[i-1].KeyM = (*M).Elmnt[i].KeyM;
                (*M).Elmnt[i-1].ValueM = (*M).Elmnt[i].ValueM;
            }
        }
        (*M).ElCount--;
    }
}
/* Menghapus Elmt dari Map Of Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */


boolean IsMemberM(MapOfMap M, keyMtype k) {
    int i = 0;
    boolean found = false;

    while ((i < M.ElCount) && (!found)) {
        if (IsWordSame(M.Elmnt[i].KeyM, k)) {
            found = true;
        }
        i++;
    }

    return (found);
}
/* Mengembalikan true jika k adalah member dari M */