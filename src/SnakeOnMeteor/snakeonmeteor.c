#include "snakeonmeteor.h"

boolean meteor_kena_kepala(List L,infotypelist X, infotypelist Y){
    boolean check = false;
    if (X(First(L))==X && Y(First(L))==Y){
            check=true;
        }
    else{
        check=false;
    }
    return check;
}

boolean meteor_kena_badan(List L,infotypelist X, infotypelist Y){
    boolean check = false;
    addresslist P;
    P = First(L);
    while (Next(P)!=Niil && !check){
        if (X(P)==X && Y(P)==Y){
            check = true;
        }
        else{
            P = Next(P);
        }
    }
    return check;
}

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

void food(List *snake,int X1,int Y1,int X2,int Y2){
    int x,y;
    boolean check = false;
    while(!check){    
        x= random1();
        y= random2();
        while(x== X1 && y == Y1||x== X2 && y == Y2 ){
            x= random1();
            y= random2();
        }
    if (SearchList(*snake,x,y)==Niil){
            if (X(First(*snake))!=x && Y(First(*snake))!=y){
                InsVLast(snake,x,y);
                check =true;
            }
        }
    }}
    


void Peta(List snake, int x, int y,int X1,int Y1,int X2,int Y2){
    addresslist P;
    matriks tabel;
    MakeEmptyMatriks(&tabel);
    P = First(snake);
    int i = 0;
    printf("\nBerikut adalah peta permainan\n");
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
    tabel.TM[X1][Y1]= -3;
    tabel.TM[X2][Y2]= -3;
    Display(tabel);
}

boolean nabrak(char input, List snake){
    addresslist P= Next(First(snake));
    boolean check = false;
    if (input == 'W'){
        while (Next(P)!=Niil){
        if (X(P)== X(First(snake))-1 && Y(P)== Y(First(snake))){
            check = true;
        }
        P = Next(P);
    }}
    else if (input == 'A'){
        while (Next(P)!=Niil){
        if (X(P)== X(First(snake)) && Y(P)== Y(First(snake))-1){
            check = true;
        }
        P = Next(P);
    }}
    else if (input == 'D'){
        while (Next(P)!=Niil){
        if (X(P)== X(First(snake)) && Y(P)== Y(First(snake))+1){
            check = true;
        }
        P = Next(P);
    }}
    else if (input == 'S'){
        while (Next(P)!=Niil){
        if (X(P)== X(First(snake))+1 && Y(P)== Y(First(snake))){
            check = true;
        }
        P = Next(P);
    }}
    return check;
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

boolean tambah_panjang(int X,int Y,List snake,int X1,int Y1,int X2,int Y2){
    addresslist P;
    boolean check= false;
    P = First(snake);
    while (Next(P)!=Niil && !check){
        if (X==X(P)&&Y==Y(P)){
            check = true;
        }
        else{
            P = Next(P);
        }
    }
    if ((X1==2 && Y1 ==2) || (X2==2 && Y2 ==2)){
        check = true;
    }
    return check;
}


void meteor(int *X,int *Y,List snake){
    *X = random3();
    *Y = random4();
    while ((X(Last(snake))==*X && Y(Last(snake))==*Y) || (*X==2 && *Y==2)){
        *X = random3();
        *Y = random4();
    }
}



void SNAKEONMETEOR(int *skor){
    int a,i,tempX,tempY,meteor_x,meteor_y,bekas_meteor_x,bekas_meteor_y,turn,obs_x1,obs_y1,obs_x2,obs_y2;
    char input;
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
    obs_x1 = (X(First(snake))+((random2()%2))+1)%5;
    obs_y1 = (Y(First(snake))+((random1()%2)+1))%5;
    obs_x2 = (X(First(snake))+((random3()%2)+1))%5;
    obs_y2 = (Y(First(snake))+((random4()%2)+1))%5;
    food(&snake,obs_x1,obs_y1,obs_x2,obs_y2);
    Peta(snake,-1,-1,obs_x1,obs_y1,obs_x2,obs_y2);
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
            if (!nabrak(input,snake)){
                move(&snake,input,&tempX,&tempY);
                printf("\nBerhasil bergerak!\n\n");
                turn++;
                if (X(First(snake))==X(Last(snake)) && Y(First(snake))==Y(Last(snake))){
                    if (!tambah_panjang(X(Prev(Last(snake))),Y(Prev(Last(snake)))-1,snake,obs_x1,obs_y1,obs_x2,obs_y2)){
                        X(Last(snake))=X(Prev(Last(snake)));
                        Y(Last(snake))=Y(Prev(Last(snake)))-1;
                    }
                    else if (!tambah_panjang(X(Prev(Last(snake)))-1,Y(Prev(Last(snake))),snake,obs_x1,obs_y1,obs_x2,obs_y2)){
                        X(Last(snake))=X(Prev(Last(snake)))-1;
                        Y(Last(snake))=Y(Prev(Last(snake)));
                    }
                    else if (!tambah_panjang(X(Prev(Last(snake)))+1,Y(Prev(Last(snake)))-1,snake,obs_x1,obs_y1,obs_x2,obs_y2)){
                        X(Last(snake))=X(Prev(Last(snake)))+1;
                        Y(Last(snake))=Y(Prev(Last(snake)));
                    }
                    else {
                        X(Last(snake))=X(Prev(Last(snake)));
                        Y(Last(snake))=Y(Prev(Last(snake)))+1;
                    }
                    food(&snake,obs_x1,obs_y1,obs_x2,obs_y2);
                    
                }
                meteor(&meteor_x,&meteor_y,snake);
                if ((X(First(snake))==obs_x1 && Y(First(snake))==obs_y1) ||(X(First(snake))==obs_x2 && Y(First(snake))==obs_y2)){
                    end =true;
                    printf("Kepala snake menabrak obstacle.\n");
                } 
                if (!end){
                    Peta(snake,meteor_x,meteor_y,obs_x1,obs_y1,obs_x2,obs_y2);
                    if (!meteor_kena_kepala(snake,meteor_x,meteor_y)){
                        if (meteor_kena_badan(snake,meteor_x,meteor_y)){
                            DelP(&snake,SearchList(snake,meteor_x,meteor_y));
                            printf("Anda terkena meteor!\n");
                            Peta(snake,meteor_x,meteor_y,obs_x1,obs_y1,obs_x2,obs_y2);
                        } else{
                            printf("Anda beruntung tidak terkena meteor! lanjutkan permainan\n");
                        }
                    } else{
                        end = true;
                        printf("\nKepala snake terkena meteor!\n\n");
                    }
                } 
                
                
            }
            else{
                if (nabrak('W',snake)&&nabrak('D',snake)&&nabrak('S',snake)&&nabrak('A',snake)){
                    end = true;
                    printf("Tidak bisa bergerak kemana-mana lagi\n");
                }
                else{
                printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan masukkan command lain.\n");}}
            
            }
            else{
                printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lain.\n\n");
            }}
        else {
            printf("\nMasukan command tidak valid! Silahkan masukkan command menggunakan huruf w/a/s/d.\n");
        }
    }
    *skor = (LengthList(snake)-2) * 2;
    printf("\n\n===============================\n");
    printf("||     G A M E   O V E R     ||\n");
    printf("===============================\n\n");
    printf("Skor akhir = %d\n\n", *skor);
}