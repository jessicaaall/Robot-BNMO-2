#include <stdio.h>
#include "../ADT/Stack/stack.h"
#include "../ADT/MesinKata/mesinkata.h"

#ifndef __HISTORY_H__
#define __HISTORY_H__

void INSERTHISTORY (Stack *S, info gameName);
/* Menambahkan gameName ke dalam Stack S */
/* I.S. gameName yang merupakan nama game terdefinisi
        Stack S yang merupakan daftar history permainan terdefinisi */
/* F.S. gameName ditambahkan ke dalam Stack S */

void DISPLAYHISTORY (Stack S, int n);
/* Menampilkan daftar history permainan */
/* I.S. Stack S yang merupakan daftar history permainan terdefinisi 
        int n terdefinisi, merupakan jumlah history permainan yang ingin ditampilkan */
/* F.S. Daftar history permainan ditampilkan ke layar sesuai dengan n */

void DELETEHISTORY (Stack *S, info gameName);
/* Menghapus gameName dari Stack S */
/* I.S. Stack S yang merupakan daftar history permainan terdefinisi 
        gameName yang merupakan nama game terdefinisi */
/* F.S. Apabila gameName terdapat dalam Stack S, maka gameName dihapus dari Stack S 
        Apabila gameName tidak terdapat dalam Stack S, maka Stack S tetap */

void RESETHISTORY (Stack *S);
/* Mengosongkan Stack S apabila user memilih untuk melakukan reset history */
/* I.S. Stack S yang merupakan daftar history permainan terdefinisi */
/* F.S. Apabila user memilih untuk melakukan reset history, maka Stack S menjadi kosong
        Apabila user membatalkan reset history, maka Stack S tetap dan daftar history permainan pada Stack S ditampilkan */

#endif