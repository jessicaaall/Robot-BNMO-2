



#include <stdio.h>




int main(){

    boolean check1,check2;
    check = false;
    Word command1;
    Word command2;
    Queue Q;
    Tab T;
    
    printf("ENTER COMMAND : ");
    InitialScan(&command1, &command2);
    printf("\n");
    if (compareWord(StringToWord("START"), command1)){
            START();
    }
    else if (compareWord(StringToWord("LOAD"), command1)){
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
        if (compareWord(StringToWord("CREATE"), command1) && compareWord(StringToWord("GAME"), command2)){
            CREATEGAME(&T);
        }
        else if(compareWord(StringToWord("LIST"), command1) && compareWord(StringToWord("GAME"), command2)){
            LISTGAME(T);
        }
        else if(compareWord(StringToWord("DELETEGAME"), command1) && compareWord(StringToWord("GAME"), command2)){
            DELETEGAME(&T,Q);
        }
        else if(compareWord(StringToWord("QUEUE"), command1) && compareWord(StringToWord("GAME"), command2)){
            QUEUEGAME(T,&Q);
        }
        else if(compareWord(StringToWord("PLAY"), command1) && compareWord(StringToWord("GAME"), command2)){
            PLAYGAME(&Q);
        }
        else if(compareWord(StringToWord("HELP"), command1)){
            HELP();
        }
        else if(compareWord(StringToWord("SAVE"), command1)){

        }
        else if(compareWord(StringToWord("SKIP"), command1)){
            SKIPGAME(command2,&Q);
        }
        else if(compareWord(StringToWord("QUIT"), command1)){
            QUIT(&check);
        }
        else{
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
    
}

