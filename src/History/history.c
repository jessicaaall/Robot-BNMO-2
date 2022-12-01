#include "history.h"

void insertHistory (Stack *S, info gameName) {
    Push(S, gameName);
}

void displayHistory (Stack S, int n) {
    Stack sTemp;
    info val;
    int i = 1;
    CreateEmptyStack(&sTemp);
    if (IsStackEmpty(S)) {
        printf("Belum ada Game yang dimainkan\n");
    } else {
        if (n == 0) {
            printf("Masukan tidak valid, masukkan harus lebih besar dari 0\n");
        } else {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
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

void deleteHistory (Stack *S, info gameName) {
    Stack sTemp;
    info val;
    while (!IsStackEmpty(*S)) {
        Pop(S, &val);
        if (!IsWordSame(val, gameName)) {
            Push(&sTemp, val);
        }
    }
}

void resetHistory (Stack *S) {
    info temp;
    Word command1, command2;
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
    Scan(&command1, &command2);
    printf("\n");

    if (IsWordSame(StringToWord("YA"), command1)) {    
        printf("History berhasil di-reset.\n");
        while (!IsStackEmpty(*S)) {
            Pop(S, &temp);
        }
    } else {
        printf("History tidak jadi di-reset. ");
        displayHistory(*S, MaxEl);
    }
}