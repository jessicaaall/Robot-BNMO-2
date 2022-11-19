#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DD2.h"

const int IDX_UNDEF = -1;
const int CAPACITY = 15;

void CreateQueue2(Queue2 *q){
    (*q).IdxHead = IDX_UNDEF;
    (*q).IdxTail = IDX_UNDEF;
    (*q).Count = 0;
}

boolean IsEmpty(Queue2 q){
    return ((q.IdxHead == IDX_UNDEF) && (q.IdxTail == IDX_UNDEF));
}

Pesanan CreateRanPesanan(int noAntrian){
    Pesanan p;
    int a = GenerateDurasi();
    int b = GenerateDurasi();
    int c = GenerateHarga();
    (p).Makanan[0] = 'M';
    if (noAntrian < 10) {
        (p).Makanan[1] = noAntrian+48;
        (p).Makanan[2] = '\0';
    } else {
        (p).Makanan[1] = '1';
        (p).Makanan[2] = (noAntrian%10)+48;
        (p).Makanan[3] = '\0';
    }
    (p).DurasiMasak = a;
    (p).Ketahanan = b;
    (p).Harga = c;

    return (p);
}

void Inisialisasi(Queue2 *qPesanan){
    for (int i = 0; i < 3; i++){
        Pesanan p = CreateRanPesanan(i);
        Enqueue(qPesanan, p);
    }
}

int GenerateHarga(){
    srand(time(NULL));
    return ((rand() % (50000-10000+1)) + 10000);
}

int GenerateDurasi(){
    srand(time(NULL));
    return ((rand() % (5-1+1)) + 1);
}

void TampilkanPesanan(Queue2 qPesanan){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Masak | Ketahanan | Harga\n");
    printf("------------------------------------------\n");
    if (IsEmpty(qPesanan)){
        printf("        |              |           |\n");
    } else {
        for (int i = 0; i < qPesanan.Count; i++){
            int b, c, d;
            b = qPesanan.buffer[i].DurasiMasak;
            c = qPesanan.buffer[i].Ketahanan;
            d = qPesanan.buffer[i].Harga;
            printf("%s      | %d            | %d         | %d\n", (qPesanan).buffer[i].Makanan, b, c, d);
        }
    }
}

void TampilkanDimasak(Queue2 qDiproses){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (IsEmpty(qDiproses)){
        printf("        |\n");
    } else {
        int count = 0;
        for (int i = 0; i < qDiproses.Count; i++) {
            if (qDiproses.buffer[i].DurasiMasak > 0) {
                count++;
                int d = qDiproses.buffer[i].DurasiMasak;
                printf("%s      | %d\n", (qDiproses.buffer[i].Makanan), d);
            }
        }
        if (count <= 0) {
            printf("        |\n");
        }
    }
}

void TampilkanSajian(Queue2 qDiproses){
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("--------------------------------\n");
    if (IsEmpty(qDiproses)){
        printf("        |\n");
    } else {
        int count = 0;
        for (int i = 0; i < qDiproses.Count; i++) {
            if ((qDiproses.buffer[i].DurasiMasak <= 0) && (qDiproses.buffer[i].Ketahanan > 0)) {
                count++;
                int d = qDiproses.buffer[i].Ketahanan;
                printf("%s      | %d\n", (qDiproses.buffer[i].Makanan), d);
            }
        }
        if (count <= 0) {
            printf("        |\n");
        }
    }
}

void Enqueue(Queue2 *q, Pesanan p){
    if (IsEmpty(*q)) {
        (*q).IdxHead = 0;
        (*q).IdxTail = 0;
        (*q).buffer[0] = p;
        (*q).Count = 1;
    } else {
        (*q).IdxTail++;
        int idx = ((*q).IdxTail);
        (*q).buffer[idx] = p;
        (*q).Count++;
    }
}

void Dequeue(Queue2 *q, Pesanan *p){
    *p = (*q).buffer[(*q).IdxHead];
    if ((*q).Count == 1) {
        (*q).IdxHead = IDX_UNDEF;
        (*q).IdxTail = IDX_UNDEF;
        (*q).Count = 0;
    } else {
        for (int i = 0; i < (*q).Count-1; i++){
            (*q).buffer[i] = (*q).buffer[i+1];
        }
        (*q).IdxTail--;
        (*q).Count--;
    }
}

void Eliminate(Queue2 *q, char foodId[]){
    int idx = GetIdx((*q), foodId);
    for (int i = idx; i < (*q).IdxTail; i++) {
        (*q).buffer[i] = (*q).buffer[i+1];
    }
}

void Cook(Queue2 qPesanan, Queue2 *qDiproses, char foodId[]){
    if ((*qDiproses).Count <= 5) {
        Pesanan p;
        p = qPesanan.buffer[GetIdx(qPesanan, foodId)];
        Enqueue(qDiproses, p);
        printf("Berhasil memasak %s\n", p.Makanan);
    } else {
        printf("Tidak dapat memasak lebih dari 5 makanan dalam waktu yang sama\n");
    }
}

void Serve(Queue2 *qPesanan, Queue2 *qDiproses, Queue2 *qSelesai, char foodId[]){
    if (GetIdx((*qDiproses), foodId) == IDX_UNDEF) {
        printf("%s tidak sedang diproses\n", foodId);
    } else {
        if ((*qDiproses).buffer[GetIdx((*qDiproses), foodId)].DurasiMasak > 0){
            printf("%s belum selesai dimasak\n", (*qDiproses).buffer[GetIdx((*qDiproses), foodId)].Makanan);
        } else {
            // Dequeue seluruh elemen qDiproses dengan elemen yang Ketahanannya <= 0
            Pesanan p;
            int idx = 0;
            while ((*qDiproses).buffer[idx].Ketahanan <= 0) {
                Dequeue(qDiproses, &p);
                idx++;
            }
            int idx1 = GetIdx((*qDiproses), foodId);
            if ( idx1 > 0) {
                printf("%s belum dapat disajikan karena %s belum selesai\n", (*qDiproses).buffer[idx1].Makanan, (*qDiproses).buffer[0].Makanan);
            } else {
                Dequeue(qDiproses, &p);
                Enqueue(qSelesai, p);
                Eliminate(qPesanan, foodId);
                (*qPesanan).Count--;
                (*qPesanan).IdxTail--;
                printf("Berhasil mengantar %s\n", p.Makanan);
            }
        }
    }
}

void Decrement(Queue2 *qDiproses) {
    if (!IsEmpty(*qDiproses)) {
        for (int i = 0; i <= (*qDiproses).IdxTail; i++){
            if ((*qDiproses).buffer[i].DurasiMasak <= 0) {
                (*qDiproses).buffer[i].Ketahanan--;
            } else {
                (*qDiproses).buffer[i].DurasiMasak--;
            }
        }
    }
}

boolean IsCook(char command[]){
    boolean retVal = false;
    if ((command[0] == 'C') || (command[0] == 'c')) {
        if ((command[1] == 'O') || (command[1] == 'o')) {
            if ((command[2] == 'O') || (command[2] == 'o')) {
                if ((command[3] == 'K') || (command[3] == 'k')) {
                    retVal = true;
                }
            }
        }
    }

    return retVal;
}

boolean IsServe(char command[]){
    boolean retVal = false;
    if ((command[0] == 'S') || (command[0] == 's')) {
        if ((command[1] == 'E') || (command[1] == 'e')) {
            if ((command[2] == 'R') || (command[2] == 'r')) {
                if ((command[3] == 'V') || (command[3] == 'v')) {
                    if ((command[4] == 'E') || (command[4] == 'e')) {
                        retVal = true;
                    }
                }
            }
        }
    }

    return retVal;
}

boolean IsSkip(char command[]){
    boolean retVal = false;
    if ((command[0] == 'S') || (command[0] == 's')) {
        if ((command[1] == 'K') || (command[1] == 'k')) {
            if ((command[2] == 'I') || (command[2] == 'i')) {
                if ((command[3] == 'P') || (command[3] == 'p')) {
                    retVal = true;
                }
            }
        }
    }

    return retVal;
}

boolean CheckId(char str[]) {
    boolean valid = false;
    if ((str[0] == 'M') || (str[0] == 'm')) {
        int idx = 1;
        while (str[idx] != '\0') {
            if ((str[idx] >= 48) && (str[idx] <= 57)) {
                valid = true;
                idx++;
            } else {
                valid = false;
                break;
            }
        }
    }

    return valid;
}

boolean IsCommandValid(char command[], char foodId[], Queue2 qPesanan, Queue2 qDiproses){
    boolean retVal = false;
    if ((foodId[0] == '\0') && (!IsSkip(command))){
        printf("Masukan invalid\n\n");
    } else if (IsSkip(command)) {
        retVal = true;
    } else if (!CheckId(foodId)){
        printf("Masukan invalid\n\n");
    } else if (IsCook(command)) {
        int val = GetIdx(qPesanan, foodId);
        if ((val != IDX_UNDEF)) {
            // hitung jumlah memasak
            int countDimasak = 0;
            for (int i = 0; i < qDiproses.Count; i++) {
                if (qDiproses.buffer[i].DurasiMasak > 0) {
                    countDimasak++;
                }
            }
            if (countDimasak <= 5) {
                retVal = true;
            } else {
                printf("Tidak dapat memasak lebih dari 5 makanan dalam waktu yang sama\n");
            }
        } else {
            printf("Tidak ada pesanan %s dalam daftar pesanan\n\n", foodId);
        }
    } else if (IsServe(command)) {
        int val = GetIdx(qDiproses,foodId);
        if ((val != IDX_UNDEF)) {
            if (qDiproses.buffer[val].DurasiMasak <= 0) {
                Pesanan p;
                int idx = 0;
                while (qDiproses.buffer[idx].Ketahanan <= 0) {
                    Dequeue(&qPesanan, &p);
                    idx++;
                }
                int val1 = GetIdx(qDiproses, foodId);
                if (val1 == 0) {
                    retVal = true;
                } else {
                    printf("%s belum dapat disajikan karena %s belum selesai\n\n", (qDiproses).buffer[val1].Makanan, (qDiproses).buffer[0].Makanan);
                }
            } else {
                printf("%s belum selesai dimasak\n", foodId);
            }
        } else {
            printf("%s tidak sedang diproses\n\n",foodId);
        }
    } else {
        printf("Masukan invalid\n\n");
    }

    return retVal;
}

void SettingCommand(Word kata, char command[], char foodId[]){
    if (IsCook(kata.TabWord) && (kata.Length >= 5)) {
        if (kata.TabWord[0] == 'C') {
            if (kata.TabWord[1] == 'O') {
                if (kata.TabWord[2] == 'O') {
                    if (kata.TabWord[3] == 'K') {
                        if (kata.TabWord[4] == ' ') {
                            for (int i = 5; i < kata.Length; i++) {
                                foodId[i-5] = kata.TabWord[i];
                            }
                            for (int i = 0; i < 4; i++) {
                                command[i] = kata.TabWord[i];
                            }
                        }
                    }
                }
            }
        }
    } else if (IsSkip(kata.TabWord) && (kata.Length >= 4)) {
        for (int i = 0; i < 4; i++) {
            command[i] = kata.TabWord[i];
        }
    } else if (IsServe(kata.TabWord) && (kata.Length >= 5)) {
        for (int i = 6; i < kata.Length; i++) {
            foodId[i-6] = kata.TabWord[i];
        }
        for (int i = 0; i < 5; i++) {
            command[i] = kata.TabWord[i];
        }
    } else if (!IsWordSame(kata, StringToWord("RanPisan"))) {
        command[0] = 'N';
        command[1] = 'I';
        command[2] = 'L';
    }
}

void ProsesCommand(char command[], char foodId[], Queue2 *qPesanan, Queue2 *qDiproses, Queue2 *qSelesai){
    if (IsCook(command)) {
        Cook(*qPesanan, qDiproses, foodId);
    } else if (IsServe(command)) {
        Serve(qPesanan, qDiproses, qSelesai, foodId);
    } else if (IsSkip(command)) {
        
    }
    for (int j = 0; j < (*qDiproses).Count; j++) {
        if ((*qDiproses).buffer[j].DurasiMasak == 0) {
            printf("Makanan %s telah selesai dimasak\n", (*qDiproses).buffer[j].Makanan);
            (*qDiproses).buffer[j].DurasiMasak = IDX_UNDEF;
        }
    }
}

boolean IsDuaDigit(char str[]){
    if ((str[2] == '\0')) {
        return false;
    } else if ((str[1] >= 49) && (str[3] != '\0')){
        return true;
    }
}

int StrToInt(char str[]) {
    if (CheckId(str)) {
        int idx = 1;
        int count = 0;
        int derajat = 1;
        while (str[idx] != '\0') {
            count = derajat * (str[idx]-48);
            idx++;
            derajat *= 10;
        }
        return count;
    }
}

int GetId(char str[]){
    if (CheckId(str)){
        return (StrToInt(str));
    }
}

int GetIdx(Queue2 q, char foodId[]){
    int idx = 0;
    boolean found = false;
    if (IsDuaDigit(foodId)) {
        // geser sampe 2 digit
        while (!IsDuaDigit(q.buffer[idx].Makanan)) {
            idx++;
        }
        while ((idx <= q.IdxTail) && (!found)){
            if (IsWordSame(StringToWord(q.buffer[idx].Makanan), StringToWord(foodId))){
                found = true;
            }
            idx++;  
        }
        if (found) {
            return (idx-1);
        } else {
            return IDX_UNDEF;
        }
    } else {
        while ((idx <= q.IdxTail) && (!found)) {
            if (IsWordSame(StringToWord(q.buffer[idx].Makanan), StringToWord(foodId))) {
                found = true;
            }
            idx++;
        }
        if (found) {
            return (idx-1);
        } else {
            return IDX_UNDEF;
        }
    }
}

boolean IsFinish(Queue2 qPesanan, Queue2 qSelesai){
    return ((qPesanan.Count == 8) || (qSelesai.Count == 15));
}


