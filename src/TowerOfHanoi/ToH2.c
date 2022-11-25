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

int JumlahMaksBintang (int piringan) {
    return ((2*piringan)-1);
}

void Inisialisasi (Stack *S, int piringan) {
    int ground = JumlahMaksBintang(piringan);
    int batas = piringan;
    for (int i = 0; i < batas; i++) {
        Push(S, ground);
        ground -= 2;
    }
}

int Length (Stack S) {
    return (S.TOP+1);
}

void GetInt (Word in, int *i) {
    char strTemp[10];
    WordToString(in, strTemp);
    if (strTemp[1] == '\0') {
        if ((strTemp[0] >= 49) && (strTemp[0] <= 57)) {
            *i = strTemp[0] - 48;
        } else {
            *i = -1;
        }
    } else {
        *i = -1;
    }
}

void GetPiringan (Word in, int *piringan) {

}

void PrintBintang (int n, int piringan) {
    // n = jumlah bintang
    int batas = JumlahMaksBintang(piringan);
    int bintang, space;
    bintang = 1;
    space = (batas-1)/2;
    while (bintang <= batas+1) {
        if (bintang == n) {
            for (int i = 0; i < space; i++) {
                printf(" ");
            }
            for (int j = 0; j < bintang; j++) {
                printf("*");
            }
            for (int k = 0; k < space; k++) {
                printf(" ");
            }
            printf("\n");
        }
        bintang += 2;
        space--;
    }
}

void DisplayStack (Stack S, int piringan) {
    int batas = JumlahMaksBintang(piringan);
    if (IsEmpty(S)) {
        for (int i = 0; i < piringan; i++) {
            for (int k = 0; k < (batas-1)/2; k++) {
                printf(" ");
            }
            printf("|\n");
        }
    } else {
        int tiang = piringan-Length(S);
        for (int i = 0; i < tiang; i++) {
            for (int k = 0; k < piringan-1; k++){
                printf(" ");
            }
            printf("|\n");
        }
        if (!IsEmpty(S)) {
            int idx = Top(S);
            for (int j = Length(S)-1; j >= 0; j--) {
                int temp;
                Pop(&S, &temp);
                PrintBintang(temp, piringan);
                idx--;
            }
        }
    }
    for (int k = 0; k < batas; k++) {
        printf("-");
    }
    printf("\n");
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

boolean IsPiringanValid (int piringan) {
    boolean valid = false;
    if (piringan >= 1) {
        valid = true;
    } else {
        printf("Jumlah piringan tidak valid\n\n");
    }

    return valid;
}

void GetChar (Word in, char *c) {
    char strTemp[20];
    WordToString(in, strTemp);
    if (strTemp[1] == '\0') {
        *c = strTemp[0];
    } else {
        *c = 'Z';
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
            printf("Source tidak valid\n\n");
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

boolean GameFinish (Stack S, int piringan) {
    int temp;
    int idx = 0;
    int base = 1;
    boolean retVal = true;
    while (idx < piringan) {
        Pop(&S, &temp);
        if (temp != base) {
            retVal = false;
        }
        idx++;
        base += 2 ;
    }
    return retVal;
}

int CountScore (int step, int piringan) {
    int StepMax = 1;
    for (int i = 0; i < piringan; i++) {
        StepMax *= 2;
    }
    StepMax--;
    printf("Step Max: %d\n", StepMax);
    int score;
    if (step <= StepMax) {
        score = 10;
    } else {
        while (step > StepMax) {
            StepMax--;
            score--;
        }
        if (score <= 0) {
            score = 1;
        }
    }
    return score;
}

int main() {
    int step = 0;
    int piringan;
    char src, dst;
    Stack A, B, C;
    Word in1, in2;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);

    printf("Jumlah piringan: ");
    Scan(&in1, &in2);
    GetInt(in1, &piringan);
    while (!IsPiringanValid(piringan)) {
        printf("Jumlah piringan: ");
        Scan(&in1, &in2);
        GetInt(in1, &piringan);

    }
    Inisialisasi(&A, piringan);

    printf("\n");
    while (!GameFinish(C, piringan)) {
        DisplayStack(A, piringan);
        for (int l = 0; l < piringan-1; l++) {
            printf(" ");
        }
        printf("A\n\n");
        DisplayStack(B, piringan);
        for (int m = 0; m < piringan-1; m++) {
            printf(" ");
        }
        printf("B\n\n");
        DisplayStack(C, piringan);
        for (int n = 0; n < piringan-1; n++) {
            printf(" ");
        }
        printf("C\n\n");
        boolean done = false;

        do {
            do {
                printf("TIANG ASAL: ");
                Scan(&in1, &in2);
                GetChar(in1, &src);
                printf("TIANG TUJUAN: ");
                Scan(&in1, &in2);
                GetChar(in1, &dst);
            } while (!IsInputValid(src, dst));
        } while (!IsCommandValid(src, dst, A, B, C));
        ProsesCommand(src, dst, &A, &B, &C);
        step++;
    }
    DisplayStack(A, piringan);
    for (int l = 0; l < piringan-1; l++) {
        printf(" ");
    }
    printf("A\n\n");
    DisplayStack(B, piringan);
    for (int m = 0; m < piringan-1; m++) {
        printf(" ");
    }
    printf("B\n\n");
    DisplayStack(C, piringan);
    for (int n = 0; n < piringan-1; n++) {
        printf(" ");
    }
    printf("C\n\n");

    printf("Kamu berhasil !\n\n");
    printf("Step: %d\n", step);
    printf("Skor didapatkan: %d\n", CountScore(step, piringan));
    char nama[10];
    printf("Nama: ");
    Scan(&in1, &in2);
    WordToString(in1, nama);

    return 0;    
}
