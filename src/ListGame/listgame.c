#include "listgame.h"
#include "../ADT/Array/array.h"

void LISTGAME(Tab T){
    int i;
    for(i=0; i<NbElmtArray(T); i++){
        printf("%d. %s",i+1,T.TI[i]);
    }
}