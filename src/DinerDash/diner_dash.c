#include <stdio.h>
#include <time.h>
#include "DD2.h"
#include "diner_dash.h"

void DINNERDASH(){
    printf("\nSelamat Datang di Diner Dash!\n");

    Queue2 qPesanan, qDiproses , qSelesai;
    CreateQueue2(&qPesanan);
    CreateQueue2(&qDiproses);
    CreateQueue2(&qSelesai);

    Inisialisasi(&qPesanan);
    int antrian = 2;
    int saldo = 0;
    char command[10], foodId[10];

    do {
        printf("\nSALDO: %d\n\n", saldo);
        TampilkanPesanan(qPesanan);
        printf("\n");
        TampilkanDimasak(qDiproses);
        printf("\n");
        TampilkanSajian(qDiproses);

        printf("\n\n");

        Decrement(&qDiproses);
        
        printf("MASUKKAN COMMAND >> ");
        Word a, b;
        Scan(&a, &b);
        WordToString(a, command);
        WordToString(b, foodId);

        while (!IsCommandValid(command, foodId, qPesanan, qDiproses)) {
            printf("MASUKKAN COMMAND >> ");
            Scan(&a, &b);
            WordToString(a, command);
            WordToString(b, foodId);
        }

        printf("\n"); 

        ProsesCommand(command, foodId, &qPesanan, &qDiproses, &qSelesai);
        antrian++;
        Pesanan p;
        p = CreateRanPesanan(antrian);
        Enqueue(&qPesanan, p);

        printf("\n");
        saldo = 0;
        for (int i = 0; i <= qSelesai.IdxTail; i++){
            saldo += qSelesai.buffer[i].Harga;
        }
        printf("\n");



    } while (!IsFinish(qPesanan, qSelesai));

    printf("\n===== Permainan Selesai =====\n");
    printf("\nSkor Akhir : %d\n", saldo);
}
