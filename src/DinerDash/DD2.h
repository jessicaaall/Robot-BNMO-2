#ifndef DD2_H
#define DD2_H
#include "boolean.h"

typedef struct {
    char Makanan[3];
    int DurasiMasak;
    int Ketahanan;
    int Harga;
} Pesanan;

typedef struct {
    Pesanan buffer[15];
    int IdxHead;
    int IdxTail;
    int Count;
} Queue;

void CreateQueue(Queue *q);
// Desc: Membuat Queue q kosong
/* IS: Queue q sembarang
   FS: Queue q kosong */

boolean IsEmpty(Queue q);
// Mengecek apakah Queue q kosong
// return True apabila kosong
// return false apabila tidak kosong

Pesanan CreateRanPesanan(int noAntrian);

void Inisialisasi(Queue *qPesanan);
// Desc: Mengeset 3 daftar pesanan awal 
/* IS: qPesanan kosong
   FS: qPesanan terisi dengan 3 pesanan yang digenerate secara random */

int GenerateHarga();
// Mengenerate harga secara random
// Harga yang digenerate berada pada rentang 10000-50000

int GenerateDurasi();
// Mengenerate durasi secara random
// Durasi yang digenerate berada pada rentang 1-5

void TampilkanPesanan(Queue qPesanan);
// Desc: Menampilkan pesanan pada tabel pesanan
/* IS: qPesanan tidak kosong
   FS: Menampilkan seluruh pesanan pada tabel pesanan */

void TampilkanDimasak(Queue qDiproses);
// Desc: Menampilkan pesanan yang sedang dimasak (DurasiMasak > 0)
/* IS: qDiproses, mungkin kosong
   FS: Menampilkan seluruh pesanan yang sedang dimasak */

void TampilkanSajian(Queue qDiproses);
// Desc: Menampilkan pesanan yang siap disajikan (DurasiMasak <= 0) && (Ketahanan > 0)
/* IS: qDiproses, mungkin kosong
   FS: Menampilkan seluruh pesanan yang siap disajikan */

void Enqueue(Queue *q, Pesanan p);
// Desc: Menambahkan pesanan pada index tail sebuah Queue q
/* IS: Queue q terdefinisi, mungkin kosong
   FS: Pesanan p ditambahkan pada q */

void Dequeue(Queue *q, Pesanan *p);
// Desc: Mengurangi pesanan pada index head sebuah Queue q
/* IS: Queue q terdefinisi, tidak kosong
   FS: Pesanan yang akan dihapus disimpan pada Pesanan p, p dihapus dari Queue q */

void Eliminate(Queue *q, char foodId[]);
// Desc: Menghapus pesanan pada indeks manapun
/* IS: Queue q terdefinisi, tidak kosong
   FS: Pesanan dengan id foodId dihapus dari Queue q */

void Cook(Queue qPesanan, Queue *qDiproses, char foodId[]);
// Desc: Melakukan command masak
/* IS: qPesanan dan qDiproses terdefinisi, qDiproses mungkin kosong, foodId terdefinisi pada qPesanan
   FS: Pesanan dengan id foodId berhasil dimasak, dienqueue pada qDiproses */

void Serve(Queue *qPesanan, Queue *qDiproses, Queue *qSelesai, char foodId[]);
// Desc: Melakukan command serve
/* IS: qPesanan, qDiproses, dan qSelesai terdefinisi. foodId terdefinisi pada qDiproses dan qPesanan
   FS: Pesanan dengan id foodId berhasil disajikan, dieliminasi dari Queue qPesanan, didequeue dari qDiproses, dienqueue ke qSelesai */

void Decrement(Queue *qDiproses);
// Desc: Mengurangi setiap DurasiMasak dan Ketahanan
/* IS: qDiproses terdefinisi, mungkin kosong
   FS: DurasiMasak dan Ketahanan dikurangi */

boolean IsCook(char command[]);
// Mengecek apakah command berisikan 'COOK'

boolean IsServe(char command[]);
// Mengecek apakah command berisikan 'SERVE'

boolean IsSkip(char command[]);
// Mengecek apakah command berisikan 'SKIP'

boolean IsCommandValid(char command[], char foodId[], Queue qPesanan, Queue qDiproses);
// Mengecek apakah command dan foofId yang diinput pengguna valid

void ProsesCommand(char command[], char foodId[], Queue *qPesanan, Queue *qDiproses, Queue *qSelesai);
// Desc: Memproses command dengan id foodId sesuai inputan
/* IS: command, foodId, qPesanan, qDiproses, dan qSelesai terdefinisi. 
   FS: Memproses command dengan id foodId sesuai inputan*/

boolean IsDuaDigit(char str[]);
// Mengecek apakah foodId 2 digit

int GetId(char str[]);
// Mendapatkan id dari sebuah string foodId

int GetIdx(Queue q, char foodId[]);
// Mendapatkan indeks lojik dari foodId pada Queue q

boolean IsFinish(Queue qPesanan, Queue qSelesai);
// Mengecek apakah permainan selesai
#endif


