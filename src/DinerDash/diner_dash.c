#include <stdio.h>
#include <time.h>
#include "diner_dash.h"
#include "mesinkatacommand.h"

void diner_dash(){
    printf("\nSelamat Datang di Diner Dash!\n");

    Queue qPesanan, qDiproses , qSelesai;
    CreateQueue(&qPesanan);
    CreateQueue(&qDiproses);
    CreateQueue(&qSelesai);

    Inisialisasi(&qPesanan);
    int antrian = 2;
    int saldo = 0;

    do {
        printf("\nSALDO: %d\n\n", saldo);
        TampilkanPesanan(qPesanan);
        printf("\n");
        TampilkanDimasak(qDiproses);
        printf("\n");
        TampilkanSajian(qDiproses);

        printf("\n\n");

        Decrement(&qDiproses);
        
        printf("MASUKKAN COMMAND: ");
        char command[5], foodId[3];
        STARTCOMMAND();
        SettingCommand(CommandCC, command, foodId);
        while (!IsCommandValid(command, foodId, qPesanan, qDiproses)) {
            printf("\nMasukkan Invalid\n");
            printf("MASUKKAN COMMAND: ");
            STARTCOMMAND();
            SettingCommand(CommandCC, command, foodId);
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

    printf("\nPermainan Selesai\n");
    printf("qSelesai : %d\n", qSelesai.Count);
    if (qSelesai.Count >= 15) {
        printf("Anda Menang\n");
    } else {
        printf("Anda Kalah\n");
    }
}

int main() {
    diner_dash();

    return 0;
}