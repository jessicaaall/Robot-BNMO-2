#include <stdio.h>
#include "ToH.h"

void CreateEmpty (Stack *S) {
    Top(*S) = Nil;
}

boolean IsEmpty (Stack S) {
    return (Top(S) == Nil);
}

void Push(Stack *S, int X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop(Stack *S, int *X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

void Inisialisasi (Stack *S) {
    int ground = 9;
    for (int i = 0; i < 5; i++) {
        Push(S, ground);
        ground -= 2;
    }
}

int Length (Stack S) {
    return (S.TOP+1);
}

int Max (Stack S) {
    int max = S.buffer[0];
    for (int i = 0; i < Length(S); i++) {
        if (S.buffer[i] > max) {
            max = S.buffer[i];
        }
    }
    return max;
}

void PrintBintang (int n) {
    // n = jumlah bintang
    if (n == 1) {
        printf("    *    \n");
    } else if (n == 3) {
        printf("   ***   \n");
    } else if (n == 5) {
        printf("  *****  \n");
    } else if (n == 7) {
        printf(" ******* \n");
    } else if (n == 9) {
        printf("*********\n");
    }
}

void DisplayStack (Stack S) {
    if (IsEmpty(S)) {
        for (int i = 0; i < 5; i++) {
            printf("    |\n");
        }
        printf("---------\n");
    } else {
        int tiang = 5-Length(S);
        int gap = (Max(S)-1)/2;
        for (int i = 0; i < tiang; i++) {
            printf("    |\n");
        }
        if (!IsEmpty(S)) {
            int idx = Top(S);
            for (int j = Length(S)-1; j >= 0; j--) {
                PrintBintang(S.buffer[j]);
                // PrintBintang(S.buffer[idx]);
                idx--;
            }
        }
        printf("---------\n");
    }
}

Stack GetStack(char input, Stack a, Stack b, Stack c) {
    if (input == 'A') {
        return a;
    } else if (input == 'B') {
        return b;
    } else if (input == 'C'){
        return c;
    }
}

boolean IsInputValid (char src, char dst) {
    boolean valid = false;
    if (((src == 'A') || (src == 'B') || (src == 'C')) && ((dst == 'A') || (dst == 'B') || (dst == 'C'))){
        if (src != dst) {
            valid = true;
        } else {
            printf("Tidak terjadi pemindahan\n\n");
        }
    } else {
        if ((src != 'A') && (src != 'B') && (src != 'C')) {
            printf("Source tidak valid\n");
        } else if ((dst != 'A') && (dst != 'B') && (dst != 'C')) {
            printf("Destinasi tidak valid\n\n");
        } 
    }

    return valid;
}

boolean IsCommandValid (char src, char dst, Stack a, Stack b, Stack c) {
    boolean valid = false;
    Stack sSrc, sDst;
    sSrc = GetStack(src, a, b, c);
    sDst = GetStack(dst, a, b ,c);
    if (IsEmpty(sSrc)) {
        printf("Source kosong\n\n");
    } else if (IsEmpty(sDst)) {
        valid = true;
    } else if (InfoTop(sSrc) < InfoTop(sDst)) {
        valid = true;
    } else if (InfoTop(sSrc) > InfoTop(sDst)) {
        printf("Destinasi lebih besar\n\n");
    }
    return valid;
}

void ProsesCommand (char src, char dst, Stack *a, Stack *b, Stack *c) {
    int x;
    if (src == 'A') {
        Pop(a, &x);
    } else if (src == 'B') {
        Pop(b, &x);
    } else if (src == 'C') {
        Pop(c, &x);
    }
    
    if (dst == 'A') {
        Push(a, x);
    } else if (dst == 'B') {
        Push(b, x);
    } else if (dst == 'C') {
        Push(c, x);
    }
    
    printf("\nMemindahkan piringan ke %c...\n\n", dst);
}

boolean GameFinish (Stack S) {
    return ((S.buffer[0] == 9) && (S.buffer[1] == 7) && (S.buffer[2] == 5) && (S.buffer[3] == 3) && (S.buffer[4] == 1));
}

int CountScore (int step) {
    int score;
    if (step <= 31) {
        score = 10;
    } else if (step <= 41) {
        score = 9;
    } else if (step <= 51) {
        score = 8;
    } else if (step <= 55) {
        score = 7;
    } else if (step <= 60) {
        score = 6;
    } else if (step <= 65) {
        score = 5;
    } else if (step <= 70) {
        score = 4;
    }else if (step <= 72) {
        score = 3;
    }else if (step <= 74) {
        score = 2;
    }else if (step <= 76) {
        score = 1;
    }

    return score;
}

int main() {
    int step = 0;
    char src, dst;
    Stack A, B, C;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);

    Inisialisasi(&A);

    while (!GameFinish(C)) {
        DisplayStack(A);
        printf("    A\n\n");
        DisplayStack(B);
        printf("    B\n\n");
        DisplayStack(C);
        printf("    C\n\n");
        do {
            do {
                printf("TIANG ASAL: ");
                scanf(" %c", &src);
                printf("TIANG TUJUAN: ");
                scanf(" %c", &dst);
            } while (!IsInputValid(src, dst));
        } while (!IsCommandValid(src, dst, A, B, C));
        ProsesCommand(src, dst, &A, &B, &C);
        step++;
    }
    DisplayStack(A);
    printf("    A\n\n");
    DisplayStack(B);
    printf("    B\n\n");
    DisplayStack(C);
    printf("    C\n\n");
    printf("\n\nKamu berhasil!\n\n");

    int score;
    char nama[10];
    score = CountScore(step);
    printf("Skor didapatkan: %d\n", score);
    printf("Nama: ");
    scanf("%s", nama);
    return 0;
}