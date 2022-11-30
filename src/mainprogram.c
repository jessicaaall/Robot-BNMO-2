#include "./ADT/Array/array.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/Map/map.h"
#include "./ADT/ArrayOfMap/arrayofmap.h"
#include "./Command/load.h"
#include "./Command/start.h"
#include "./Command/save.h"
#include "./CreateGame/creategame.h"
#include "./ListGame/listgame.h"
#include "./DeleteGame/deletegame.h"
#include "./QueueGame/queuegame.h"
#include "./PlayGame/playgame.h"
#include "./SkipGame/skipgame.h"
#include "./Quit/quit.h"
#include "./Help/help.h"
#include "./Scoreboard/scoreboard.h"
#include "boolean.h"
#include <stdio.h>


int main() {
    printf("=========================================================================================================\n");
    printf("__        __ _____  _       ____   ___   __  __  _____     _____   ___      ____   _   _  __  __   ___\n");
    printf("\\ \\      / /| ____|| |     / ___| / _ \\ |  \\/  || ____|   |_   _| / _ \\    | __ ) | \\ | ||  \\/  | / _ \\ \n");
    printf(" \\ \\ /\\ / / |  _|  | |    | |    | | | || |\\/| ||  _|       | |  | | | |   |  _ \\ |  \\| || |\\/| || | | |\n");
    printf("  \\ V  V /  | |___ | |___ | |___ | |_| || |  | || |___      | |  | |_| |   | |_) || |\\  || |  | || |_| |\n");
    printf("   \\_/\\_/   |_____||_____| \\____| \\___/ |_|  |_||_____|     |_|   \\___/    |____/ |_| \\_||_|  |_| \\___/\n");
    printf("=========================================================================================================\n");

    printf("\n\n\n                        ..::^^^^^^~~~~~~~~!!!!!!77777??????????7!!~^:..\n");                                   
    printf("                     ^?J?77!!!!!~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^~~!!7?????7!~:..\n");                          
    printf("                    5P~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~!!7?JJYJ?7!^:.\n");                  
    printf("                   ^&?7777!!!~~~^^^^^^^^^^!?JJJYYYYYYYYYYYYYY55555555555555YYYYYYY55PPPGP:\n");                
    printf("                   ~&JJJJJJYYJJ????77!!~JGP5YYYJJJJJJJJ???????????????????????????J??77?5#.\n");               
    printf("                   ^&JJJ??JBG??YB5?JJJJY&Y77777?JJJJJYYYYY5555555PPPPPPPPPPPP5555555PP???&^\n");               
    printf("                   ^&JJJJP5JJJJJ5Y??JJ?P&????JGP5YYYJJ???77!!!~~~^^^:::::............BP7?&^\n");               
    printf("                   ^&JJJYG5?JGG??5GJJJ?P#?7??#J......................................PB7?&:\n");               
    printf("                   ^&JJJJ?JYJJJ??5PJJJ?P#???J&~......................................5B7J&:\n");               
    printf("                   ^&JJJ??Y#5?JGP??JJJ?P#???J&~.........::..................^B#7.....5B7J&:\n");               
    printf("                   ^&JJJYYJJJ??5Y????J?P#???J&~........?&&~.................!@@J.....5B7J&:\n");               
    printf("                   ^&J?J&&&&##BGP55YJJ?P#???J&~........J&&^..................^~......5#7J&:\n");               
    printf("                   ^&J?Y&@&G&@@&&&&&G??P#???J&~.........::...:!:.......:!5:..........5B7J&:\n");               
    printf("                   ~&J?J&@#Y#@@B?P@@B??P#???J&^...............?YYJ???JYYJ^...........5B7J&:\n");               
    printf("                   ~&JJ?G@@@@&&&&&@@G??P#???J&^..................::^::...............5B7J&:\n");               
    printf("                   ~&JJ?JPB#B5Y#&&&BJ??P#???J&^......................................5B7J&:\n");               
    printf("                   ~&J??G&#BGP5Y55Y?JJ?P&??7J&^......................................PB7J&:\n");               
    printf("                   ~&JJ?5GB#&&&&&&&BJ??P&??7J&^......................................BG7J&:\n");               
    printf("                   ~&J??J5PGB#&&&&&#J??5&J?7J&:........................:::^^~~!!77?J5BJ7J&.\n");               
    printf("                   ~&J??P@@@@&#BP5JJJJ?5&J???#?::^^^~~~!!77??JJYY5555PPPPPPPP55PGP5YJ???J&.\n");               
    printf("                   ~&JJ?YGB##&&&&&&BJJ?5&J???JPP5P55555555555YYY55555PPP?7777?GBBBBY7???J&.\n");               
    printf("                   ~&J??G&#BGGPPGGBGJJ?Y&J?????5PPPGGGBB#####&&&&&&&&&&&J????JBBBB#Y????J&.\n");               
    printf("                   ~&JJ?5B#&&&&&&&#BJ??Y&J7??75&&&&&&&&&&####BBBGGGPP55Y???????Y55J????7Y&.\n");               
    printf("                   ~&JJJ????YPB&@@@&Y??Y&Y????J555YYJJJJ??????7777777777???????777??????Y#\n");                
    printf("                   ~&JJJJJ??5&@&&&PYJJ?Y&Y?????7777J55PYYG?7????????????77??????????????Y#\n");                
    printf("                   !&JJ?P&#BGB&&&&#YJJ?J&Y???????JJGG5Y.:GPYYJ?????????JPGG5Y???????????5#\n");                
    printf("                   7#JJ?YB##&&&&@@@#JJJJ&57?????GYBJ77^::~!~YG?????????GGG!~5P?????????75#\n");                
    printf("                   ?#?JJ???JY5PPGGBGJJJJ&57?????BJB7!7~..~??55????????GGG~^^^JGJ?5BBGPPJ5#\n");                
    printf("                   J#?JJJG#&&&&&&B5?JJ?J&57?????JYYGGYY::5P??????????PBGPYYYYY5?5##?77?BGB\n");                
    printf("                   J#?JJ&@@&#B#&@@&BJJJJ&57?????777JP5PYY5J???????????????JJYJ?7YB#GYYPGP#.\n");               
    printf("                   Y#??5@&&&!~~7#@&&5?JJ&P7???????????7??7????????????7?PB#####B5JYPGPY?P#J?^\n");             
    printf("                   YB?JJ#@@&?~~~7#@&Y?JJ&P7???????????????????????????JBB#GP555PBBJ77777PB~!?J7:\n");          
    printf("                   !&J?JJG&@&?~~~!BGJ?JJ#P7????????????77???7777777??7P##B5555555#G7???7G#?!~~!JJ~\n");        
    printf("                    BGJ???J5GGY!~~~YG5J?#P7?????7?????JJJ?JY555PPGGJ??J###P55555G#Y7????GG:?J7~^~?Y7.\n");     
    printf("                     YBPYJ????5GJ~~~!YP5#G7?????PBB#####&5G&&&&&##&57??JGB##BBBGPJ7????7GG  .~P5Y7~7Y7.\n");   
    printf("                      .!J5PGP5YJ5PJ!~~!JGGJ?7???P#BBBGGPPJJ55YYYJJ????7?JJJY5YJ?7777777J&7   JG55BJ~75P7\n");  
    printf("                           .^7Y5PGBBP7~~~7YP5J?7????77777?77777777777?5GPGG???JJJYY55PGB7   ~BY5YGBYPBBP.\n"); 
    printf("                                 .^!YP5J7~^~7Y55J???????JJJJYYY555555GB5YYB####BBGGGGGGPYYJ7GPY5YB7.~7:\n");   
    printf("                                       .!JJ7~~~755GBBBBBBBGGB#BPY?!^.PPY5YB7.:~7JY5PPP5555555YYYPB.\n");       
    printf("                                          .~?J7JPPBP7Y5PPPP55Y5555P55G5YY5B.       .:~!?Y55PPPPPY.\n");        
    printf("                                             .^7JP?     .^!?J5PPPPP55555PB7                 ...\n");           
    printf("                                                               .:^~7?JJJ7:\n\n\n\n");
    printf("=============================\n");
    printf("||          M E N U        ||\n");
    printf("=============================\n");
    printf("||  START                  ||\n");
    printf("||  LOAD <filename>        ||\n");
    printf("=============================\n\n");

	Word command1 = StringToWord("\0");
	Word command2 = StringToWord("\0");
    Tab listgame;
    Stack historygame;
    TabMap listscoreboard;
    Queue antriangame;
    boolean check = false, IsQuit = false, IsCommandStart = true, Skip;

    CreateQueue(&antriangame);

    while (!check) {
        printf("\nENTER COMMAND >> ");
        InitialScan(&command1, &command2);
        if ((IsWordSame(StringToWord("START"), command1)) && (command2.Length == 0)) {
            STARTFILE(&listgame, &historygame, &listscoreboard);
            check = true;
        } else if (IsWordSame(StringToWord("LOAD"), command1)) {
            if ((command2.Length != 0) && (ValidTxt(command2))) {
                LOAD(command2.TabWord, &listgame, &historygame, &listscoreboard);
                if (listgame.Neff != 0) {
                    check = true;
                    IsCommandStart = false;
                } else {
                    printf("Filename ");
                    PrintWord(command2);
                    printf(" tidak ditemukan.\n");
                }
            } else {
                printf("\nMasukan tidak valid. Silahkan masukkan nama file .txt yang ingin dibaca.\n");
            }
        } else {
            printf("\nCommand tidak valid. Silahkan masukkan command START atau LOAD <filename> terlebih dahulu.\n");
        }
    }

    if (check) {
        printf("\n");
        if (IsCommandStart) {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
        } else {
            printf("%s berhasil dibaca. BNMO berhasil dijalankan.", command2.TabWord);
        }
        printf("\n");
    }

    while (!IsQuit) {
        printf("\nENTER COMMAND >> ");
        Scan(&command1, &command2);
        printf("\n");

        if ((IsWordSame(StringToWord("START"), command1)) || (IsWordSame(StringToWord("LOAD"), command1))) {
            printf("Anda telah melakukan pembacaan file.");
        } else if (IsWordSame(StringToWord("CREATE"), command1) && IsWordSame(StringToWord("GAME"), command2)) {
            CREATEGAME(&listgame, &listscoreboard);
        } else if (IsWordSame(StringToWord("LIST"), command1) && IsWordSame(StringToWord("GAME"), command2)) {
            LISTGAME(listgame);
        } else if (IsWordSame(StringToWord("DELETE"), command1) && IsWordSame(StringToWord("GAME"), command2)) {
            DELETEGAME(&listgame, antriangame, &listscoreboard);
        } else if (IsWordSame(StringToWord("QUEUE"), command1) && IsWordSame(StringToWord("GAME"), command2)) {
            QUEUEGAME(listgame, &antriangame);
        } else if (IsWordSame(StringToWord("PLAY"), command1) && IsWordSame(StringToWord("GAME"), command2)) {
            if (isEmpty(antriangame)) {
                printf("Daftar antrian game-mu kosong. Tidak ada game untuk dimainkan.\n");
            } else {
                printf("Berikut adalah daftar antrian game-mu\n");
                displayQueueGame(antriangame);
                printf("\n");
                PLAYGAME(&antriangame, &listscoreboard, listgame);
            }
        } else if (IsWordSame(StringToWord("SKIPGAME"), command1)) {
            if (command2.Length != 0) {
                Skip = SKIPGAME(command2, &antriangame);
                if (Skip){
                    PLAYGAME(&antriangame, &listscoreboard, listgame);
                }
            } else {
                printf("\nMasukan tidak valid. Silahkan masukkan jumlah permainan yang ingin dilewatkan.\n");
            }
        } else if ((IsWordSame(StringToWord("QUIT"), command1)) && (command2.Length == 0)) {
            QUIT();
            IsQuit = true;
        } else if ((IsWordSame(StringToWord("HELP"), command1)) && (command2.Length == 0)) {
            HELP();
        } else if (IsWordSame(StringToWord("SAVE"), command1)) {
            if ((command2.Length != 0) && (ValidTxt(command2))) {
                SAVE(command2, listgame, historygame, listscoreboard);
            } else {
                printf("Masukan tidak valid. Silahkan masukkan nama file .txt yang akan disimpan.\n");
            }
        } else if ((IsWordSame(StringToWord("SCOREBOARD"), command1)) && (command2.Length == 0)) {
            SCOREBOARD(listscoreboard, listgame);
        } else if ((IsWordSame(StringToWord("RESET"), command1)) && (IsWordSame(StringToWord("SCOREBOARD"), command2))) {
            RESETSCOREBOARD(listgame, &listscoreboard);
        } else {
            printf("Command tidak dikenali. Silahkan masukkan command yang valid.\n");
        }

        printf("\n");
    }

    return 0;
}