#include "creategame.h"

void CREATEGAME (Tab *daftargame) {

    printf("Masukkan nama game yang akan ditambahkan >> ");
    STARTCOMMAND2();
    CommandCC = WordUpper(CommandCC);
    
    int i = 0;
    boolean found = false;

    while ((!found) && (i < (*daftargame).Neff)) {
        if (IsWordSame(CommandCC, (*daftargame).TI[i])) {
            found = true;
        }
        i++;
    }

    if (found) {
        printf("\nGame ");
        PrintWord(CommandCC);
        printf(" gagal ditambahkan. Game sudah ada pada daftar game.\n");
    } else {
        if (!IsFullArray(*daftargame)) {
            (*daftargame).TI[(*daftargame).Neff].Length = 0;
            for (i = 0; i < CommandCC.Length; i++) {
                (*daftargame).TI[(*daftargame).Neff].TabWord[i] = CommandCC.TabWord[i];
                (*daftargame).TI[(*daftargame).Neff].Length++;
            }
            (*daftargame).Neff++;
            printf("\nGame ");
            PrintWord(CommandCC);
            printf(" berhasil ditambahkan.\n");
        } else {
            printf("\nDaftar game sudah penuh. Game ");
            PrintWord(CommandCC);
            printf(" gagal ditambahkan.\n");
        }
    }
}
/* Proses : Menerima input nama game yang akan ditambahkan 
            Menambahkan game baru pada daftar game */
/* I.S. Daftar game terdefinisi */
/* F.S. Apabila game yang ingin ditambahkan tidak ada pada daftar game, daftar game bertambah 
        Apabila game yang ingin ditambahkan sudah ada pada daftar game, daftar game tetap */