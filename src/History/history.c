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
        printf("Berikut adalah daftar Game yang telah dimainkan\n");
        while (!IsStackEmpty(S) && i <= n) {
            Pop(&S, &val);
            print("%d. ", i);
            for (int j = 0; j < val.Length; j++) {
                printf("%c", val.TabWord[j]);
            }
            Push(&sTemp, val);
        }
        while (IsStackEmpty(S)) {
            Pop(&sTemp, &val);
            Push(&S, val);
        }
    }   
}

void deleteHistory (Stack *S, info gameName) {
    Stack sTemp;
    info val;
    while (!IsStackEmpty(*S)) {
        Pop(&S, &val);
        if (!IsWordSame(val, gameName)) {
            Push(&sTemp, val);
        }
    }
}

void resetHistory (Stack *S) {
    info temp;
    Word command1, command2;
    Scan(&command1, &command2);
    printf("\n");

    if (IsWordSame(StringToWord("YA"), command1)) {    
        while (!IsStackEmpty(*S)) {
            Pop(&S, &temp);
        }
    } else {
        print("History tidak jadi di-reset. ");
        displayHistory(*S, MaxEl);
    }
}