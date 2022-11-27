#include "hangman.h"


void readfile(char *filename, Tab *listkata) {
    int i = 0;

    STARTWORD(filename);
    while (!EOP) {
        (*listkata).TI[i] = CWord;
        ADVWORD();
        i++;
    }
    if (CWord.TabWord[0] != '\0') {
        (*listkata).TI[i] = CWord;
        i++;
    }
    (*listkata).Neff = i;
}
/* Membaca filename.txt, lalu menyimpan isi filename.txt ke dalam Tab listkata */
/* I.S. filename terdefinisi, dengan isi file yang mungkin kosong */
/* F.S. listkata berisi isi dari filename.txt */


void writefile(char *filename, Tab listkata) {
    int i;
    FILE *f;
    
    f = fopen(filename, "w");
    for (i = 0; i < listkata.Neff; i++) {
        fprintf(f, "%s\n", GetElmtArray(listkata, i).TabWord);
    }
    fclose(f);
}
/* Menyimpan isi Tab listkata ke dalam filename.txt */
/* I.S. filename terdefinisi
        listkata terdefinisi, mungkin kosong */
/* F.S. filename.txt berisi isi dari Tab listkata */


int randomword(Tab listkata) {
    int x;
    srand(time(NULL));
    x = rand() % listkata.Neff;
    return x;
}
/* Mengembalikan integer random antara 0 sampai indeks efektif terakhir Tab listkata */


void HANGMAN(int *skor) {
    printf("\n _   _      _      _   _    ____   __  __      _      _   _\n"); 
    printf("| | | |    / \\    | \\ | |  / ___| |  \\/  |    / \\    | \\ | |\n"); 
    printf("| |_| |   / _ \\   |  \\| | | |  _  | |\\/| |   / _ \\   |  \\| |\n"); 
    printf("|  _  |  / ___ \\  | |\\  | | |_| | | |  | |  / ___ \\  | |\\  |\n"); 
    printf("|_| |_| /_/   \\_\\ |_| \\_|  \\____| |_|  |_| /_/   \\_\\ |_| \\_|\n");
    printf("\n\n");                                             
    printf("===========================\n");
    printf("||         M E N U       ||\n");
    printf("===========================\n");
    printf("||  Play                 ||\n");
    printf("||  Add Word             ||\n");
    printf("===========================\n\n");

    Tab listofwords;
    Word word1, word2;
    boolean valid;
    int i;
    *skor = -1;

    MakeEmptyArray(&listofwords);
    readfile("listofwords.txt", &listofwords);
    
    do {
        printf("\nSilahkan masukkan menu yang diinginkan >> ");
        Scan(&word1, &word2);
    } while (!((IsWordSame(word1, StringToWord("ADD")) && IsWordSame(word2, StringToWord("WORD"))) || (IsWordSame(word1, StringToWord("PLAY")) && word2.Length == 0)));

    while (IsWordSame(word1, StringToWord("ADD")) && IsWordSame(word2, StringToWord("WORD"))) {
        if (!IsFullArray(listofwords)) {
            do {
                valid = true;
                printf("\nMasukkan sebuah kata yang ingin ditambahkan ke dalam daftar kata >> ");
                Scan(&word1, &word2);
                if ((word1.Length != 0) && (word2.Length == 0)) {
                    if (word1.Length != 1) {
                        i = 0;
                        while ((valid) && (i < word1.Length)) {
                            if ((word1.TabWord[i] < 'A') || (word1.TabWord[i] > 'Z')) {
                                valid = false;
                            }
                            i++;
                        }
                        if (!valid) {
                            printf("\nMasukkan kata tidak valid. Kata hanya boleh mengandung huruf.\n");
                        } else {
                            i = 0;
                            while ((valid) && (i < listofwords.Neff)) {
                                if (IsWordSame(word1, listofwords.TI[i])) {
                                    valid = false;
                                }
                                i++;
                            }
                            if (!valid) {
                                printf("\nKata ");
                                PrintWord(word1);
                                printf(" sudah terdapat dalam daftar kata. Mohon masukkan kata lain.\n");
                            }
                        }
                    } else {
                        valid = false;
                        printf("\nMasukan kata tidak valid. Mohon masukkan sebuah kata, bukan huruf.\n");
                    }
                } else {
                    valid = false;
                    if ((word1.Length != 0) && (word2.Length != 0)) {
                        printf("\nMasukan kata tidak valid. Anda hanya dapat memasukkan sebuah kata.\n");
                    } else {
                        printf("\nMasukan kata tidak valid. Mohon masukkan sebuah kata.\n");
                    }
                }
            } while (!valid);

            listofwords.TI[listofwords.Neff].Length = word1.Length;
            for (i = 0; i < word1.Length; i++) {
                listofwords.TI[listofwords.Neff].TabWord[i] = word1.TabWord[i];
            }
            listofwords.Neff++;
            printf("\nKata ");
            PrintWord(word1);
            printf(" berhasil ditambahkan ke dalam daftar kata.\n");

        } else {
            printf("\nMaaf, daftar kata sudah penuh. Anda tidak dapat menambahkan kata ke dalam daftar kata.\n");
        }
        
        printf("\n");
        do {
            printf("\nApakah Anda masih ingin menambahkan kata ke dalam daftar kata? (Ya/Tidak) >> ");
            CommandCC.Length = 0;
            STARTCOMMAND2();
            CommandCC = WordUpper(CommandCC);
        } while (!(IsWordSame(CommandCC, StringToWord("YA")) || IsWordSame(CommandCC, StringToWord("TIDAK"))));
        printf("\n");

        if (IsWordSame(CommandCC, StringToWord("YA"))) {
            word1.TabWord[0] = 'A';
            word1.TabWord[1] = 'D';
            word1.TabWord[2] = 'D';
            word1.Length = 3;
            word2.TabWord[0] = 'W';
            word2.TabWord[1] = 'O';
            word2.TabWord[2] = 'R';
            word2.TabWord[3] = 'D';
            word2.Length = 4;
        } else {
            writefile("listofwords.txt", listofwords);

            do {
                printf("\nApakah Anda ingin bermain Hangman? (Ya/Tidak) >> ");
                CommandCC.Length = 0;
                STARTCOMMAND2();
                CommandCC = WordUpper(CommandCC);
            } while (!(IsWordSame(CommandCC, StringToWord("YA")) || IsWordSame(CommandCC, StringToWord("TIDAK"))));

            if (IsWordSame(CommandCC, StringToWord("YA"))) {
                word1.TabWord[0] = 'P';
                word1.TabWord[1] = 'L';
                word1.TabWord[2] = 'A';
                word1.TabWord[3] = 'Y';
                word1.Length = 4;
                word2.Length = 0;
            } else {
                word1.TabWord[0] = 'E';
                word1.TabWord[1] = 'X';
                word1.TabWord[2] = 'I';
                word1.TabWord[3] = 'T';
                word1.Length = 4;
                word2.Length = 0;
            }
        }
    }
    

    if (IsWordSame(word1, StringToWord("PLAY")) && word2.Length == 0) {
        int kesempatan = 10, x;
        Tab takenword;
        Word kata, tebakan, huruftebakan;
        boolean done = true, found;

        MakeEmptyArray(&takenword);
        printf("\n\n");
        if (!IsEmptyArray(listofwords)) {
            printf("____ ____ _    ____ _  _ ____ ___    ___  ____ ____ _  _ ____ _ _  _\n");
            printf("[__  |___ |    |__| |\\/| |__|  |     |__] |___ |__/ |\\/| |__| | |\\ |\n");
            printf("___] |___ |___ |  | |  | |  |  |     |__] |___ |  \\ |  | |  | | | \\|\n\n");

            *skor = 0;
            while (kesempatan != 0) {
                if (done) {
                    do {
                        x = randomword(listofwords);
                        kata.Length = listofwords.TI[x].Length;
                        for (i = 0; i < kata.Length; i++) {
                            kata.TabWord[i] = listofwords.TI[x].TabWord[i];
                        }

                        valid = true;
                        if (takenword.Neff != listofwords.Neff) {
                            i = 0;
                            while ((valid) && (i < takenword.Neff)) {
                                if (IsWordSame(kata, takenword.TI[i])) {
                                    valid = false;
                                }
                                i++;
                            }
                        } else {
                            MakeEmptyArray(&takenword);
                        }
                    } while (!valid);
                    done = false;
                    takenword.TI[takenword.Neff].Length = kata.Length;
                    for (i = 0; i < kata.Length; i++) {
                        takenword.TI[takenword.Neff].TabWord[i] = kata.TabWord[i];
                    }
                    takenword.Neff++;
                    tebakan.Length = kata.Length;
                    huruftebakan.Length = 0;
                }
                
                printf("\n\nTebakan sebelumnya : ");
                if (huruftebakan.Length == 0) {
                    printf("-");
                } else {
                    for (i = 0; i < huruftebakan.Length; i++) {
                        printf("%c", huruftebakan.TabWord[i]);
                        if (i != huruftebakan.Length - 1) {
                            printf(", ");
                        }
                    }
                }

                printf("\nKata : ");
                for (i = 0; i < tebakan.Length; i++) {
                    if (tebakan.TabWord[i] == '\0') {
                        printf("_ ");
                    } else {
                        printf("%c ", tebakan.TabWord[i]);
                    }
                }
                printf("\nKesempatan : %d\n", kesempatan);
                if (kesempatan == 1) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |   ---|---\n");
                    printf(" |      |\n");
                    printf(" |     / \\\n");
                    printf(" |    /    \n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 2) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |   ---|---\n");
                    printf(" |      |\n");
                    printf(" |     /  \n");
                    printf(" |    /    \n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 3) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |   ---|---\n");
                    printf(" |      |\n");
                    printf(" |     /  \n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 4) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |   ---|---\n");
                    printf(" |      |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 5) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |   ---|---\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 6) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |   ---|\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 7) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |      |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 8) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |      O\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 9) {
                    printf(" ________\n");
                    printf(" |      |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                } else if (kesempatan == 10) {
                    printf(" ________\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf(" |\n");
                    printf("---\n");
                }

                do {
                    printf("\nMasukkan tebakan >> ");
                    Scan(&word1, &word2);
                    if ((word1.Length == 1) && (word2.Length == 0) && (word1.TabWord[0] >= 'A') && (word1.TabWord[0] <= 'Z')) {
                        i = 0;
                        valid = true;
                        while ((valid) && (i < huruftebakan.Length)) {
                            if (huruftebakan.TabWord[i] == word1.TabWord[0]) {
                                valid = false;
                            }
                            i++;
                        }
                        if (!valid) {
                            printf("\nAnda sudah menebak huruf %c sebelumnya. Mohon masukkan huruf lain. \n", word1.TabWord[0]);
                        }
                    } else {
                        valid = false;
                        printf("\nMasukan tebakan tidak valid. Mohon masukkan sebuah huruf.\n");
                    }
                } while (!valid);

                huruftebakan.TabWord[huruftebakan.Length] = word1.TabWord[0];
                huruftebakan.Length++;
                
                found = false;
                for (i = 0; i < kata.Length; i++) {
                    if (kata.TabWord[i] == word1.TabWord[0]) {
                        found = true;
                        tebakan.TabWord[i] = word1.TabWord[0];
                    }
                }

                if (!found) {
                    printf("Tebakan Anda salah. Huruf %c tidak terdapat pada kata.\n", word1.TabWord[0]);
                    kesempatan--;
                } else {
                    printf("Tebakan Anda benar.\n");
                }

                found = false;
                for (i = 0; i < tebakan.Length; i++) {
                    if (tebakan.TabWord[i] == '\0') {
                        found = true;
                    }
                }

                if (!found) {
                    done = true;
                    *skor += kata.Length;
                    printf("\nBerhasil menebak kata ");
                    PrintWord(kata);
                    printf("! Anda mendapatkan %d poin!\n", kata.Length);

                    for (i = 0; i < tebakan.Length; i++) {
                        tebakan.TabWord[i] = '\0';
                    }
                    tebakan.Length = 0;
                }
            }
            printf("\n\nYah.. Kesempatan Anda sudah habis.\n");
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |   ---|---\n");
            printf(" |      |\n");
            printf(" |     / \\\n");
            printf(" |    /   \\\n");
            printf(" |\n");
            printf("---\n");
            printf("\n\n");
            printf("===============================\n");
            printf("||     G A M E   O V E R     ||\n");
            printf("===============================\n\n");
            printf("Skor akhir = %d\n\n", *skor);

        } else {
            printf("\nMaaf, Hangman sedang tidak dapat dimainkan. Daftar kata kosong. Mohon menambahkan daftar kata terlebih dahulu.\n");
        }
    }


    if (IsWordSame(word1, StringToWord("EXIT"))) {
        printf("\n\nAnda berhasil keluar dari Hangman.\n\n");
    }
}