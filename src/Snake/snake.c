#include "snake.h"


void move(List *snake, char input, int *tempX, int *tempY){
    address P;
    P = Prev(Last(*snake));
    *tempX = X(Prev(Last(*snake)));
    *tempY = Y(Prev(Last(*snake)));
    if (input == 'W'){
       while (Prev(P)!=Nil){
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
       while (Prev(P)!=Nil){
        X(P) = X(Prev(P));
        Y(P) = Y(Prev(P));
        P = Prev(P); 
       } 
       X(First(*snake)) = (X(First(*snake))+1) % 5;
    }
    else if (input == 'D'){
       while (Prev(P)!=Nil){
        X(P) = X(Prev(P));
        Y(P) = Y(Prev(P));
        P = Prev(P); 
       } 
       Y(First(*snake)) = (Y(First(*snake))+1) % 5;
    }
    else if(input == 'A'){
       while (Prev(P)!=Nil){
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
        if (Search(*snake,x,y)==Nil){
            if (X(First(*snake))!=x && Y(First(*snake))!=y){
                InsVLast(snake,x,y);
                check =true;
            }
        }
    }
    
}

void Peta(List snake, int x, int y){
    address P;
    matriks tabel;
    MakeEmpty(&tabel);
    P = First(snake);
    int i = 0;
    printf("Berikut adalah peta permainan\n");
    while (Next(P)!=Nil){
        if (i==0){
            tabel.TI[X(P)][Y(P)]=999;
        }
        else{
            tabel.TI[X(P)][Y(P)]=i;
        }
        P = Next(P);
        i++;
    }
    tabel.TI[X(P)][Y(P)]=-1;
    tabel.TI[x][y]= -2;
    Display(tabel);
}

void nabrak(boolean * check, List snake){
    address P= Next(First(snake));
    while (Next(P)!=Nil){
        if (X(P)== X(First(snake)) && Y(P)== Y(First(snake))){
            *check = true;
        }
        P = Next(P);
    }
}

boolean bekas_meteor(List snake,int x,int y,char input){
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
void snake(int *skor){
    int a,i,tempX,tempY,meteor_x,meteor_y,bekas_meteor_x,bekas_meteor_y,turn;
    char input;
    char letak_badan = 'a';
    List snake;
    address P;
    boolean end = false;
    meteor_x=-1;
    meteor_y=-1;
    turn=1;
    CreateEmpty(&snake);
    printf("Selamat datang di snake on meteor!\n\nMengenerate peta, snake dan makanan . . . \nBerhasil digenerate!\n");
    food(&snake);
    Peta(snake,-1,-1);
    bekas_meteor_x=-1;
    bekas_meteor_y=-1;
    while (!end){
        printf("TURN %d\nSilahkan masukkan command anda :",turn);
        CommandCC.Length = 0;
        STARTCOMMAND2();
        CommandCC = WordUpper(CommandCC);
        printf("\n");
        if (IsWordSame(CommandCC, StringToWord("A")) || IsWordSame(CommandCC, StringToWord("W")) || IsWordSame(CommandCC, StringToWord("S")) || IsWordSame(CommandCC, StringToWord("D")) ){
            input = CommandCC.TabWord[0];
            if (!bekas_meteor(snake,meteor_x,meteor_y,input)){
            if (input != letak_badan ){
                move(&snake,input,&tempX,&tempY);
                printf("Berhasil bergerak!\n");
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
                        DelP(&snake,Search(snake,meteor_x,meteor_y));
                    }
                }
                else{
                    end = true;
                    printf("Kepala snake terkena meteor!\n");
                }
                
                
            }
            else{
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n");}
            
            }
            else{
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n\n");
            }}
        else {
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        }
    }
    printf("Game berakhir, skor anda %d\n", Length(snake)-2);
    *skor = (Length(snake)-2) * 2;
}