#include <stdio.h>
#include "towerofhanoi.h"


int JumlahMaksBintang (int piringan) {
    return ((2*piringan)-1);
}

void InisialisasiS (StackToH *S, int piringan) {
    int ground = JumlahMaksBintang(piringan);
    int batas = piringan;
    for (int i = 0; i < batas; i++) {
        PushS(S, ground);
        ground -= 2;
    }
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
    if (*number > MaxS) {
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

void DisplayStack (StackToH S, int piringan) {
    int batas = JumlahMaksBintang(piringan);
    if (IsSEmpty(S)) {
        for (int i = 0; i < piringan; i++) {
            for (int k = 0; k < (batas-1)/2; k++) {
                printf(" ");
            }
            printf("|\n");
        }
    } else {
        int tiang = piringan-LengthS(S);
        for (int i = 0; i < tiang; i++) {
            for (int k = 0; k < piringan-1; k++){
                printf(" ");
            }
            printf("|\n");
        }
        if (!IsSEmpty(S)) {
            int idx = TopS(S);
            for (int j = LengthS(S)-1; j >= 0; j--) {
                int temp;
                PopS(&S, &temp);
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

StackToH GetStack(char input, StackToH a, StackToH b, StackToH c) {
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

boolean IsCommandSValid (char src, char dst, StackToH a, StackToH b, StackToH c) {
    boolean valid = false;
    StackToH sSrc, sDst;
    sSrc = GetStack(src, a, b, c);
    sDst = GetStack(dst, a, b ,c);
    if (IsSEmpty(sSrc)) {
        printf("Pemindahan gagal. Tiang asal kosong.\n\n");
    } else if (IsSEmpty(sDst)) {
        valid = true;
    } else if (InfoTopS(sSrc) < InfoTopS(sDst)) {
        valid = true;
    } else if (InfoTopS(sSrc) > InfoTopS(sDst)) {
        printf("Pemindahan gagal. Piringan teratas pada tiang tujuan lebih kecil.\n\n");
    }
    return valid;
}

void ProsesCommandS (char src, char dst, StackToH *a, StackToH *b, StackToH *c) {
    int x;
    if (src == 'A') {
        PopS(a, &x);
    } else if (src == 'B') {
        PopS(b, &x);
    } else if (src == 'C') {
        PopS(c, &x);
    }
    
    if (dst == 'A') {
        PushS(a, x);
    } else if (dst == 'B') {
        PushS(b, x);
    } else if (dst == 'C') {
        PushS(c, x);
    }
    
    printf("\nMemindahkan piringan ke %c...\n\n", dst);
}

boolean GameFinish (StackToH S, int piringan) {
    int temp;
    int idx = 0;
    int base = 1;
    boolean retVal = true;
    while (idx < piringan) {
        PopS(&S, &temp);
        if (temp != base) {
            retVal = false;
        }
        idx++;
        base += 2 ;
    }
    return retVal;
}

int CountScore (int step, int piringan) {
    int StepMax, score;
    StepMax = pow(2,piringan) - 1;
    score = 10 + (piringan - 5);
    if (step > StepMax) {
        score -= (step - StepMax);
    }
    if (score <= 1) {
        score = 1;
    }
    
    return score;
}


void TOWEROFHANOI(int *skor) {
    printf("\n========================================================================================================\n");
    printf(" _____    ___   __        __  _____   ____       ___    _____     _   _      _      _   _    ___    ___ \n");
    printf("|_   _|  / _ \\  \\ \\      / / | ____| |  _ \\     / _ \\  |  ___|   | | | |    / \\    | \\ | |  / _ \\  |_ _|\n");
    printf("  | |   | | | |  \\ \\ /\\ / /  |  _|   | |_) |   | | | | | |_      | |_| |   / _ \\   |  \\| | | | | |  | | \n");
    printf("  | |   | |_| |   \\ V  V /   | |___  |  _ <    | |_| | |  _|     |  _  |  / ___ \\  | |\\  | | |_| |  | | \n");
    printf("  |_|    \\___/     \\_/\\_/    |_____| |_| \\_\\    \\___/  |_|       |_| |_| /_/   \\_\\ |_| \\_|  \\___/  |___|\n\n");
    printf("========================================================================================================\n\n\n");

    int step = 0;
    int piringan;
    char src, dst;
    StackToH A, B, C;
    Word in1, in2;
    CreateSEmpty(&A);
    CreateSEmpty(&B);
    CreateSEmpty(&C);

    do {
        printf("Masukkan jumlah piringan >> ");
        Scan(&in1, &in2);
        if (in2.Length == 0) {
            GetInt(in1, &piringan);
        } else {
            piringan = 0;
        }
    } while (!IsPiringanValid(piringan));
    
    InisialisasiS(&A, piringan);

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
                printf("TIANG ASAL >> ");
                Scan(&in1, &in2);
                GetChar(in1, in2, &src);
                printf("TIANG TUJUAN >> ");
                Scan(&in1, &in2);
                GetChar(in1, in2, &dst);
            } while (!IsInputValid(src, dst));
        } while (!IsCommandSValid(src, dst, A, B, C));
        ProsesCommandS(src, dst, &A, &B, &C);
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

    printf("\nSelamat, Anda berhasil!\n\n");
    *skor = CountScore(step, piringan);
    printf("\n===============================\n");
    printf("||     G A M E   O V E R     ||\n");
    printf("===============================\n\n");
    printf("Skor akhir = %d\n\n", *skor);
}