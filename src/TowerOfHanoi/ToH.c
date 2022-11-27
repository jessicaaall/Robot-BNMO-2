#include <stdio.h>
#include "ToH.h"

void CreateEmpty (Stack *S) {
    Top(*S) = Nil;
}

boolean IsEmpty (Stack S) {
    return (Top(S) == Nil);
}

void Push(Stack *S, int X) {
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop(Stack *S, int *X) {
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

void GetInt (Word in, int *number) {
    boolean valid = true;
    int i = 0;

    while ((valid) && (i < in.Length)) {
        if ((in.TabWord[i] < '0') || (in.TabWord[i] > '9')) {
            valid = false;
        }
        i++;
    }

    *number = 0;
    if (valid) {
        for (i = 0; i < in.Length; i++) {
            *number = (*number)*10 + (in.TabWord[i] - '0');
        }
    }
    if (*number > 500) {
        *number = 0;
    }
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
        printf("Masukan jumlah piringan tidak valid.\n\n");
    }

    return valid;
}

void GetChar (Word in1, Word in2, char *c) {
    char strTemp[20];
    WordToString(in1, strTemp);
    if ((strTemp[1] == '\0') && (in2.Length == 0) && (in1.Length == 1)) {
        *c = strTemp[0];
    } else {
        *c = 'Z';
    }
}

boolean IsInputValid (char src, char dst) {
    boolean valid = false;
    printf("\n");
    if (((src == 'A') || (src == 'B') || (src == 'C')) && ((dst == 'A') || (dst == 'B') || (dst == 'C'))){
        if (src != dst) {
            valid = true;
        } else {
            printf("Tidak terjadi pemindahan. Tiang asal dan tiang tujuan sama.\n\n");
        }
    } else {
        if ((src != 'A') && (src != 'B') && (src != 'C')) {
            printf("Masukan tiang asal tidak valid.\n");
        }
        if ((dst != 'A') && (dst != 'B') && (dst != 'C')) {
            printf("Masukan tiang tujuan tidak valid.\n");
        }
        printf("\n");
    }

    return valid;
}

boolean IsCommandValid (char src, char dst, Stack a, Stack b, Stack c) {
    boolean valid = false;
    Stack sSrc, sDst;
    sSrc = GetStack(src, a, b, c);
    sDst = GetStack(dst, a, b ,c);
    if (IsEmpty(sSrc)) {
        printf("Pemindahan gagal. Tiang asal kosong.\n\n");
    } else if (IsEmpty(sDst)) {
        valid = true;
    } else if (InfoTop(sSrc) < InfoTop(sDst)) {
        valid = true;
    } else if (InfoTop(sSrc) > InfoTop(sDst)) {
        printf("Pemindahan gagal. Piringan teratas pada tiang tujuan lebih kecil.\n\n");
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
    printf("Step: %d\n", step);
    printf("Step Max: %d\n", StepMax);
    int score;
    if (step <= StepMax) {
        score = 10;
    } else {
        score = 10 - (step - StepMax);
        if (score <= 1) {
            score = 1;
        }
    }
    if (piringan >= 5) {
        score += (piringan - 5);
    } else {
        score -= (5 - piringan);
    }
    
    return score;
}