#include "./ADT/Array/array.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "./ADT/Queue/queue.h"
#include "boolean.h"
#include <stdio.h>


int main(){

    boolean check1,check2;
    boolean check = false;
    Word command1;
    Word command2;
    Queue Q;
    Tab T;
    
    printf("ENTER COMMAND : ");
    InitialScan(&command1, &command2);
    printf("\n");
    if (IsWordSame(StringToWord("START"), command1)){
            START();
    }
    else if (IsWordSame(StringToWord("LOAD"), command1)){
        //fungsi Load
        if (T.Neff==1){
            check=true;
            //print kata2 exit
            }
    }
    else {
        QUIT(&check);
    }

   
    while (!check){
        printf("ENTER COMMAND : ");
        Scan(&command1, &command2);
        printf("\n");
        if (IsWordSame(StringToWord("CREATE"), command1) && IsWordSame(StringToWord("GAME"), command2)){
            CREATEGAME(&T);
        }
        else if(IsWordSame(StringToWord("LIST"), command1) && IsWordSame(StringToWord("GAME"), command2)){
            LISTGAME(T);
        }
        else if(IsWordSame(StringToWord("DELETEGAME"), command1) && IsWordSame(StringToWord("GAME"), command2)){
            DELETEGAME(&T,Q);
        }
        else if(IsWordSame(StringToWord("QUEUE"), command1) && IsWordSame(StringToWord("GAME"), command2)){
            QUEUEGAME(T,&Q);
        }
        else if(IsWordSame(StringToWord("PLAY"), command1) && IsWordSame(StringToWord("GAME"), command2)){
            PLAYGAME(&Q);
        }
        else if(IsWordSame(StringToWord("HELP"), command1)){
            HELP();
        }
        else if(IsWordSame(StringToWord("SAVE"), command1)){

        }
        else if(IsWordSame(StringToWord("SKIP"), command1)){
            SKIPGAME(command2,&Q);
        }
        else if(IsWordSame(StringToWord("QUIT"), command1)){
            QUIT(&check);
        }
        else{
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
    
}