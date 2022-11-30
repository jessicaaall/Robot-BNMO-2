#include "snakeonmeteor.h"


void move(List *snake, char input, int *tempX, int *tempY){
    addresslist P;
    P = Prev(Last(*snake));
    *tempX = X(Prev(Last(*snake)));
    *tempY = Y(Prev(Last(*snake)));
    if (input == 'W'){
       while (Prev(P)!=Niil){
        X(P) = X(Prev(P));
        Y(P) = Y(Prev(P));
        P = Prev(P); 
       } 
       if (X(First(*snake))==0){
        X(First(*snake)) = 4;
       }
       else{X(First(*snake)) = (X(First(*snake))-1);}
       
    }
    else if (input == 'S'){
       while (Prev(P)!=Niil){
        X(P) = X(Prev(P));
        Y(P) = Y(Prev(P));
        P = Prev(P); 
       } 
       X(First(*snake)) = (X(First(*snake))+1) % 5;
    }
    else if (input == 'D'){
       while (Prev(P)!=Niil){
        X(P) = X(Prev(P));
        Y(P) = Y(Prev(P));
        P = Prev(P); 
       } 
       Y(First(*snake)) = (Y(First(*snake))+1) % 5;
    }
    else if(input == 'A'){
       while (Prev(P)!=Niil){
        X(P) = X(Prev(P));
        Y(P) = Y(Prev(P));
        P = Prev(P); 
       } 
       if (Y(First(*snake))==0){
        Y(First(*snake)) = 4;
       }
       else{Y(First(*snake)) = (Y(First(*snake))-1);}
    }
}

void food(List *snake){
    int x,y;
    boolean check = false;
    while (!check){
        x= random1();
        y= random2();
        if (SearchList(*snake,x,y)==Niil){
            if (X(First(*snake))!=x && Y(First(*snake))!=y){
                InsVLast(snake,x,y);
                check =true;
            }
        }
    }
    
}

void Peta(List snake, int x, int y){
    addresslist P;
    matriks tabel;
    MakeEmptyMatriks(&tabel);
    P = First(snake);
    int i = 0;
    printf("Berikut adalah peta permainan\n");
    while (Next(P)!=Niil){
        if (i==0){
            tabel.TM[X(P)][Y(P)]=999;
        }
        else{
            tabel.TM[X(P)][Y(P)]=i;
        }
        P = Next(P);
        i++;
    }
    tabel.TM[X(P)][Y(P)]=-1;
    tabel.TM[x][y]= -2;
    Display(tabel);
}

void nabrak(boolean * check, List snake){
    addresslist P= Next(First(snake));
    while (Next(P)!=Niil){
        if (X(P)== X(First(snake)) && Y(P)== Y(First(snake))){
            *check = true;
        }
        P = Next(P);
    }
}

boolean bekas_meteor(List snake, int x, int y, char input){
    if (input=='A'){
        if (Y(First(snake))-1==y && X(First(snake))==x){
            return true;
        }
        else{
            return false;
        }
    }
    else if (input=='D'){
        if (Y(First(snake))+1==y && X(First(snake))==x){
            return true;
        }
        else{
            return false;
        }
    }
    else if (input=='W'){
        if (X(First(snake))-1==x && Y(First(snake))==y){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (X(First(snake))+1==x && Y(First(snake))==y){
            return true;
        }
        else{
            return false;
        }
    }
}

    
char ubah_letak_badan(char input){
    if (input == 'A'){
        return 'D';
    }
    else if (input =='D'){
        return 'A';
    }
    else if (input =='W'){
        return 'S';
    }
    else if (input =='S'){
        return 'W';
    }
}


void SNAKEONMETEOR(int *skor){
    int a,i,tempX,tempY,meteor_x,meteor_y,bekas_meteor_x,bekas_meteor_y,turn;
    char input;
    char letak_badan = 'a';
    List snake;
    addresslist P;
    boolean end = false;

    meteor_x=-1;
    meteor_y=-1;
    turn=1;
    CreateEmptyList(&snake);
    printf("\n===================================================================================================\n");
    printf(" ____   _   _     _     _  __ _____      ___   _   _     __  __  _____  _____  _____   ___   ____  \n");
    printf("/ ___| | \\ | |   / \\   | |/ /| ____|    / _ \\ | \\ | |   |  \\/  || ____||_   _|| ____| / _ \\ |  _ \\ \n");
    printf("\\___ \\ |  \\| |  / _ \\  | ' / |  _|     | | | ||  \\| |   | |\\/| ||  _|    | |  |  _|  | | | || |_) |\n");
    printf(" ___) || |\\  | / ___ \\ | . \\ | |___    | |_| || |\\  |   | |  | || |___   | |  | |___ | |_| ||  _ < \n");
    printf("|____/ |_| \\_|/_/   \\_\\|_|\\_\\|_____|    \\___/ |_| \\_|   |_|  |_||_____|  |_|  |_____| \\___/ |_| \\_\\\n");
    printf("\n===================================================================================================\n\n\n");
    printf("Mengenerate peta, snake dan makanan . . . \n\nBerhasil digenerate!\n");
    printf("_________________________________________________________\n\n");
    food(&snake);
    Peta(snake,-1,-1);
    bekas_meteor_x=-1;
    bekas_meteor_y=-1;
    while (!end){
        printf("\nTURN %d : \nSilahkan masukkan command >> ",turn);
        CommandCC.Length = 0;
        STARTCOMMAND2();
        CommandCC = WordUpper(CommandCC);
        if (IsWordSame(CommandCC, StringToWord("A")) || IsWordSame(CommandCC, StringToWord("W")) || IsWordSame(CommandCC, StringToWord("S")) || IsWordSame(CommandCC, StringToWord("D")) ){
            input = CommandCC.TabWord[0];
            if (!bekas_meteor(snake,meteor_x,meteor_y,input)){
            if (input != letak_badan ){
                move(&snake,input,&tempX,&tempY);
                printf("\nBerhasil bergerak!\n\n");
                turn++;
                nabrak(&end,snake);
                letak_badan = ubah_letak_badan(input);
                if (X(First(snake))==X(Last(snake)) && Y(First(snake))==Y(Last(snake))){
                    X(Last(snake))= tempX;
                    Y(Last(snake))= tempY;
                    food(&snake);
                    
                }
                meteor_x = random3();
                meteor_y = random4();
                if (!end){
                    Peta(snake,meteor_x,meteor_y);
                }
                if (!meteor_kena_kepala(snake,meteor_x,meteor_y)){
                    if (meteor_kena_badan(snake,meteor_x,meteor_y)){
                        DelP(&snake,SearchList(snake,meteor_x,meteor_y));
                    }
                }
                else{
                    end = true;
                    printf("\nKepala snake terkena meteor!\n\n");
                }
                
                
            }
            else{
                printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n");}
            
            }
            else{
                printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n\n");
            }}
        else {
            printf("\nCommand tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        }
    }
    *skor = (LengthList(snake)-2) * 2;
    printf("\n\n===============================\n");
    printf("||     G A M E   O V E R     ||\n");
    printf("===============================\n\n");
    printf("Skor akhir = %d\n\n", *skor);
}