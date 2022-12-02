// Driver Tower of Hanoi
// akses : gcc -o drive driverToH.c ToH.c mesinkata.c mesinkarakter.c

#include <stdio.h>
#include "stackToH.h"
#include "../TowerOfHanoi/towerofhanoi.h"

int main() {
    StackToH S;
    // CreateEmpty, IsEmpty
    printf("Cek IsEmpty dan CreateEmpty\n");
    CreateSEmpty(&S);
    if (IsSEmpty(S)) {
        printf("Stack S kosong, True\n\n");
    }

    // Push, Pop, Length
    printf("Cek Push dan Pop\n");
    printf("Push 3\n");
    PushS(&S, 3);
    printf("Push 10\n");
    PushS(&S, 10);
    printf("Length Stack: %d\n", LengthS(S));
    int x;
    printf("Pop\n");
    PopS(&S, &x);
    printf("Pop\n");
    PopS(&S, &x);
    printf("2 kali pop. Cek apakah true dengan fungsi IsEmpty\n");
    if (IsSEmpty(S)) {
        printf("Stack S kosong\n\n");
    }

    // inisialisasi, JumlahMaksBintang, Display Stack
    printf("Cek Inisialisasi\n");
    int piringan = 5;
    printf("Misal piringan = 5\n\n");
    InisialisasiS(&S, piringan);
    DisplayStack(S, piringan);
    printf("\n");

    // Print bintang
    printf("Cek PrintBintang\n");
    printf("Misal, print 3 bintang dari 6 silinder\n");
    int n = 3;
    piringan = 6;
    printf("Misal, piringan = 6, n = 3\n");
    PrintBintang(n, piringan);

    // GetStack
    printf("\nCek GetStack\n");
    printf("Misal, Stack A, B, dan C terdiri dari 5 piringan\n");
    printf("A diinisialisasi dengan jumlah 5 piringan\n");
    printf("Didefinisikan Stack tes1 dam tes2\n");
    printf("Stack tes1 merupakan Stack dengan input 'A'\n");
    printf("Stack tes1 merupakan Stack dengan input 'C'\n");
    printf("Hasil diinginkan : tes1 = A dan tes2 = C\n");
    piringan = 5;
    StackToH A, B, C;
    CreateSEmpty(&A);
    CreateSEmpty(&B);
    CreateSEmpty(&C);
    InisialisasiS(&A, piringan);
    char input1 = 'A';
    char input2 = 'C';
    StackToH tes1 = GetStack(input1, A, B, C);
    StackToH tes2 = GetStack(input2, A, B, C);
    DisplayStack(tes1, piringan);
    DisplayStack(tes2, piringan);
    printf("\n");

    // IsInputValid
    printf("Cek IsInputValid\n");
    printf("Misal, input3 = 'A', input4 = 'B'\n");
    printf("      ,input5 = 'C', input6 = 'Z'\n");
    char input3 = 'A';
    char input4 = 'B';
    char input5 = 'C';
    char input6 = 'Z';
    printf("Cek IsInputValid 1 (src: input3, dst: input4)");
    if (IsInputValid(input3, input4)) {
        printf("True\n");
    }
    printf("Cek IsInputValid 2 (source sama)");
    if (!IsInputValid(input4, input4)) {
    }
    printf("Cek IsInputValid 3 (input == 'Z')");
    if (!IsInputValid(input6, input4)) {
    }

    // IsCommandValid, ProsesCommand
    printf("Cek IsCommandValid\n");
    printf("Misal, input3 = 'A', input3 = 'B',\n");
    printf("       input3 = 'C', input3 = 'Z'\n");
    printf("Jika src: input3 dan dst: input4\n");
    printf("Apakah valid?\n");
    if (IsCommandSValid(input3,input4, A, B, C)) {
        printf("Valid, diproses\n");
        ProsesCommandS(input3,input4, &A, &B, &C);
    }
    printf("Jika src: input3 dan dst: input4\n");
    printf("Apakah valid?\n");
    if (!IsCommandSValid(input3,input4, A, B, C)) {
    }

    // GameFinish
    // misal: stack C1 belum penuh, stack C2 sudah penuh
    printf("Cek GameFinish\n");
    printf("Misal, Stack C1, C2 merupakan Stack 5 piringan\n");
    printf("Stack C1 tidak penuh\n");
    printf("Stack C2 penuh\n");
    StackToH C1, C2;
    piringan = 5;
    CreateSEmpty(&C1);
    CreateSEmpty(&C2);
    PushS(&C1, 3);
    PushS(&C1, 1);
    InisialisasiS(&C2, piringan);

    printf("Cek GameFinish Stack C1\n");
    if (!GameFinish(C1, piringan)) {
        printf("Tidak penuh, True\n");
    }
    printf("Cek GameFinish Stack C2\n");
    if (GameFinish(C2, piringan)) {
        printf("Game penuh, True\n\n");
    }

    // CountScore
    // misal : piringan = 5, Score1 = 31, Score2 = 36, score3 = 50
    printf("Cek CountScore\n");
    printf("Misal ada 5 piringan\n");
    printf("step1: 31 step\n");
    printf("step2: 36 step\n");
    printf("step3: 50 step\n\n");
    piringan = 5;
    int step1, step2, step3;
    step1 = 31;
    step2 = 36;
    step3 = 50;
    printf("Score step1: %d\n", CountScore(step1, piringan));
    printf("Score step2: %d\n", CountScore(step2, piringan));
    printf("Score step3: %d\n", CountScore(step3, piringan));

    printf("\n\nDriver Selesai.\n");

    return 0;
}