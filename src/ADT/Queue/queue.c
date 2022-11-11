#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q){
    return (length(q) == CAPACITY);   
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    } else {
        return (IDX_TAIL(q) + 1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q)++;
    }
    TAIL(*q)=val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" */

void dequeue(Queue *q, ElType *val){
    int i;
    (*val) = HEAD(*q);

    if ((IDX_HEAD(*q) == 0) && (IDX_TAIL(*q) == 0)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        for (i = 0; i < IDX_TAIL(*q); i++){
            (*q).buffer[i] = (*q).buffer[i+1];
        }
        IDX_TAIL(*q)--;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S. , 
		semua elemen mulai dari IDX_HEAD+1 sampai IDX_TAIL digeser
		IDX_TAIL "maju"
        q mungkin kosong */


/* *** Display Queue *** */
void displayQueueGame(Queue Q){
    int i, j;
    for (i = 0; i <= IDX_TAIL(Q); i++) {
        printf("%d. ", i+1);
        PrintWord(Q.buffer[i]);
        printf("\n");
        }
        printf("\n");
}
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong, menulis daftar antrian game*/