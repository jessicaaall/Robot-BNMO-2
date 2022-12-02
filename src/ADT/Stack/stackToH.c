#include "stackToH.h"

void CreateSEmpty (StackToH *S) {
    TopS(*S) = Nill;
}
// Desc: Membuat StackToH kosong
/* IS: StackToH sembarang
   FS: StackToH S kosong */

boolean IsSEmpty (StackToH S) {
    return (TopS(S) == Nill);
}
/* Mengirim true apabila StackToH kosong, yaitu TOPS bernilai Nil */

void PushS(StackToH *S, int X) {
    TopS(*S) += 1;
    InfoTopS(*S) = X;
}
// Desc: Memasukkan integer S ke StackToH S dengan aturan LIFO (Last In, First Out)
/* IS: StackToH S terdefinisi, mungkin kosong
   FS: integer X sebagai elemen TopS pada StackToH S*/

void PopS(StackToH *S, int *X) {
    *X = InfoTopS(*S);
    TopS(*S) -= 1;
}
// Desc: Mengeluarkan elemen TopS pada StackToH S
/* IS: StackToH S terdefinisi, tidak kosong
   FS: Elemen TopS StackToH S akan disimpan di X, kemudian dikeluarkan dari StackToH S*/

int LengthS (StackToH S) {
    return (TopS(S)+1);
}
// Desc: Mengembalikan panjang dari StackToH S