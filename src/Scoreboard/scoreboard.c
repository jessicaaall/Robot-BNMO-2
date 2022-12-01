#include "scoreboard.h"

void INSERTSCOREBOARD(int score, TabMap *TM, int idx) {
    Word name1;
    Word name2;
    Map M;

    M = GetElmtArrMap(*TM, idx);
    do {
        printf("Nama >> ");
        Scan(&name1, &name2);
        printf("\n");
        if (name2.Length != 0) {
            printf("Masukan nama tidak valid. Nama hanya boleh terdiri dari satu kata. Mohon masukkan nama lain.\n\n");
        } else if (IsMember(M, name1)) {
            printf("Masukan nama tidak valid. Nama sudah pernah terpakai. Mohon masukkan nama lain.\n\n");
        }
    } while (IsMember(M, name1) || name2.Length != 0);

    InsertSort(&M, name1, score);
    TM->Elmt[idx] = M;
    printf("Skor berhasil dimasukkan ke dalam scoreboard!\n\n");
}
/* Proses : Meminta input nama sampai input nama belum terdapat dalam key pada Elmt ke-idx
            Menambahkan key berupa nama dan value berupa score ke dalam TabMap TM Elmt ke-idx */
/* I.S. score terdefinisi, idx terdefinisi, TabMap terdefinisi */
/* F.S. TabMap pada Elmt ke-idx mengandung key berupa input nama dan value berupa score */


void DISPLAYSCOREBOARD(TabMap TM, Tab T) {
    Map currBoard;
    int i, j, k;
    int keylength, valuelength;
    Word kata;

    printf("\n");
    for (i = 0; i < NbElmtArray(T); i++) {
        currBoard = GetElmtArrMap(TM, i);
        printf("***** SCOREBOARD GAME ");
        PrintWord(T.TI[i]);
        printf(" *****\n");

        keylength = 15;
        valuelength = 10;
        if (MaxKeyLength(currBoard) > keylength) {
            keylength = MaxKeyLength(currBoard) + 3;
        }

        printf("| NAMA");
        for (j = 0; j < keylength-4; j++) {
            printf(" ");
        }
        printf("| SKOR");
        for (j = 0; j < valuelength-4; j++) {
            printf(" ");
        }
        printf("|\n");

        if (currBoard.Count == 0) {
            printf("------ SCOREBOARD KOSONG ------\n");
        } else {
            printf("|-");
            for (j = 0; j < keylength + valuelength + 2; j++) {
                printf("-");
            }
            printf("|\n");

            for (j = 0; j < currBoard.Count; j++) {
                printf("| ");
                PrintWord(currBoard.Elements[j].Key);
                for (k = 0; k < keylength - currBoard.Elements[j].Key.Length; k++) {
                    printf(" ");
                }
                printf("| %d", currBoard.Elements[j].Value);
                kata = IntToWord(currBoard.Elements[j].Value);
                for (k = 0; k < valuelength - kata.Length; k++) {
                    printf(" ");
                }
                printf("|\n");
            }
        }
        printf("\n");
    }
}
/* Menampilkan scoreboard untuk setiap game */
/* I.S. TabMap TM yang merupakan daftar scoreboard setiap game terdefinisi
        Tab T yang merupakan daftar game terdefinisi */
/* F.S. Menampilkan scoreboard untuk setiap game */


void RESETSCOREBOARD(Tab T, TabMap *TM){
    Word inp1, inp2;
    int i, angka;
    Map resetM;
    boolean valid;

    CreateEmptyMap(&resetM);

    printf("DAFTAR SCOREBOARD :\n0. ALL\n");
    for (i = 0; i < NbElmtArray(T); i++){
        printf("%d. ", i+1);
        PrintWord(T.TI[i]);
        printf("\n");
    }

    do {
        printf("\nSCOREBOARD YANG INGIN DIHAPUS >> ");
        Scan(&inp1, &inp2);
        valid = true;
        if (inp1.Length != 0) {            
            if (inp2.Length == 0) {
                i = 0;
                while ((valid) && (i < inp1.Length)) {
                    if ((inp1.TabWord[i] < '0') || (inp1.TabWord[i] > '9')) {
                        valid = false;
                    }
                    i++;
                }
                if (valid) {
                    angka = WordToInt(inp1);
                    if (angka > NbElmtArray(T)) {
                        valid = false;
                    }
                }
            } else {
                valid = false;
            }
            if (!valid) {
                printf("\nMasukan nomor scoreboard tidak valid. Mohon masukkan nomor scoreboard pada daftar scoreboard.\n");
            }
        } else {
            valid = false;
            printf("\nMohon masukkan nomor scoreboard yang ingin dihapus.\n");
        }
    } while (!valid);

    do {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
        if (angka == 0) {
            printf("ALL");
        } else {
            PrintWord(T.TI[angka-1]);
        }
        printf("  (YA/TIDAK)  >> ");
        Scan(&inp1, &inp2);

        valid = true;
        if (inp2.Length != 0) {
            valid = false;
        } else {
            if (!(IsWordSame(inp1, StringToWord("YA")) || IsWordSame(inp1, StringToWord("TIDAK")))) {
                valid = false;
            }
        }
    } while (!valid);

    if (IsWordSame(inp1, StringToWord("YA"))) {
        printf("\nScoreboard ");
        if (angka == 0) {
            for (i = 0; i < NbElmtArray(T); i++) {
                TM->Elmt[i] = resetM;
            }
            printf("ALL");
        } else {
            TM->Elmt[angka-1] = resetM;
            PrintWord(T.TI[angka-1]);
        }
        printf(" berhasil di-reset.\n\n");
    } else {
        printf("\nReset scoreboard ");
        if (angka == 0) {
            printf("ALL");
        } else {
            PrintWord(T.TI[angka-1]);
        }
        printf(" dibatalkan.\n\n");
    }
}
/* Proses : Menampilkan daftar scoreboard
            Meminta input nomor scoreboard yang ingin dihapus sampai valid 
            Menghapus scoreboard yang ingin dihapus pada TabMap TM */
/* I.S. TabMap TM yang merupakan daftar scoreboard terdefinisi 
        Tab T yang merupakan daftar game terdefinisi */
/* F.S. Menghapus scoreboard dari daftar scoreboard pada TabMap TM berdasarkan input nomor scoreboard */