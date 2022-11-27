#include <stdio.h>
#include "ToH.h"
#include "towerofhanoi.h"

void TOWEROFHANOI() {
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
    Stack A, B, C;
    Word in1, in2;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);

    do {
        printf("Masukkan jumlah piringan >> ");
        Scan(&in1, &in2);
        if (in2.Length == 0) {
            GetInt(in1, &piringan);
        } else {
            piringan = 0;
        }
    } while (!IsPiringanValid(piringan));
    
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
                printf("TIANG ASAL >> ");
                Scan(&in1, &in2);
                GetChar(in1, in2, &src);
                printf("TIANG TUJUAN >> ");
                Scan(&in1, &in2);
                GetChar(in1, in2, &dst);
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
    printf("Skor didapatkan: %d\n", CountScore(step, piringan));
    char nama[10];
    printf("Nama: ");
    Scan(&in1, &in2);
    WordToString(in1, nama);
}