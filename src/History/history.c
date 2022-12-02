#include "history.h"

void INSERTHISTORY (Stack *S, info gameName) {
    Push(S, gameName);
}
/* Menambahkan gameName ke dalam Stack S */
/* I.S. gameName terdefinisi
        Stack S yang merupakan daftar history permainan terdefinisi */
/* F.S. gameName ditambahkan ke dalam Stack S */

void DISPLAYHISTORY (Stack S, int n) {
    Stack sTemp;
    info val;
    int i = 1;
    CreateEmptyStack(&sTemp);
    if (IsStackEmpty(S)) {
        printf("History game kosong. Tidak ada game yang telah dimainkan.\n");
    } else {
        if (n == 0) {
            printf("Masukan tidak valid. Masukan angka harus lebih besar dari 0.\n");
        } else {
            printf("Berikut adalah daftar game yang telah dimainkan\n");
            while (!IsStackEmpty(S) && i <= n) {
                Pop(&S, &val);
                printf("%d. ", i);
                for (int j = 0; j < val.Length; j++) {
                    printf("%c", val.TabWord[j]);
                }
                printf("\n");
                Push(&sTemp, val);
                i++;
            }
            while (IsStackEmpty(S)) {
                Pop(&sTemp, &val);
                Push(&S, val);
            }
        }
    }   
}
/* Menampilkan daftar history permainan */
/* I.S. Stack S yang merupakan daftar history permainan terdefinisi 
        int n terdefinisi, merupakan jumlah history permainan yang ingin ditampilkan */
/* F.S. Daftar history permainan ditampilkan ke layar sesuai dengan n */

void DELETEHISTORY (Stack *S, info gameName) {
    Stack sTemp;
    info val;
    CreateEmptyStack(&sTemp);
    while (!IsStackEmpty(*S)) {
        Pop(S, &val);
        if (!IsWordSame(val, gameName)) {
            Push(&sTemp, val);
        }
    }
    while (!IsStackEmpty(sTemp)) {
        Pop(&sTemp, &val);
        Push(S, val);
    }
}
/* Menghapus gameName dari Stack S */
/* I.S. Stack S yang merupakan daftar history permainan terdefinisi 
        gameName yang merupakan nama game terdefinisi */
/* F.S. Apabila gameName terdapat dalam Stack S, maka gameName dihapus dari Stack S 
        Apabila gameName tidak terdapat dalam Stack S, maka Stack S tetap */

void RESETHISTORY (Stack *S) {
    info temp;
    Word command1, command2;
    boolean valid;

    do {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
        printf("  (YA/TIDAK)  >> ");
        Scan(&command1, &command2);
        valid = true;
        if (command2.Length != 0) {
            valid = false;
        } else {
            if (!(IsWordSame(command1, StringToWord("YA")) || IsWordSame(command1, StringToWord("TIDAK")))) {
                valid = false;
            }
        }
    } while (!valid);

    if (IsWordSame(StringToWord("YA"), command1)) {    
        printf("\nHistory berhasil di-reset.\n\n");
        while (!IsStackEmpty(*S)) {
            Pop(S, &temp);
        }
    } else {
        printf("History tidak jadi di-reset. ");
        DISPLAYHISTORY(*S, MaxEl);
    }
}
/* Mengosongkan Stack S apabila user memilih untuk melakukan reset history */
/* I.S. Stack S yang merupakan daftar history permainan terdefinisi */
/* F.S. Apabila user memilih untuk melakukan reset history, maka Stack S menjadi kosong
        Apabila user membatalkan reset history, maka Stack S tetap dan daftar history permainan pada Stack S ditampilkan */