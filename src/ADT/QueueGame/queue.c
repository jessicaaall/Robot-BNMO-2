#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;

}

boolean isEmpty(Queue q){
    return (IDX_HEAD(q)==IDX_UNDEF)&&(IDX_TAIL(q)==IDX_UNDEF);
}

boolean isFull(Queue q){
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY - 1));   
}

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    }
    else{
    return (IDX_TAIL(q)+1);
    }
}

void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
        TAIL(*q)=val;
    }
    else {
        IDX_TAIL(*q)++;
        TAIL(*q)=val;
    }}


void dequeue(Queue *q, ElType *val){
    int i;
    if ((IDX_HEAD(*q)==0)&&(IDX_TAIL(*q)==0)){
        (*val)=HEAD(*q);
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        (*val)=HEAD(*q);
        for (i=0;i<IDX_TAIL(*q);i++){
            q->buffer[i]=q->buffer[i+1];
        }
        IDX_TAIL(*q)--;
    }
}

void displayQueueGame(Queue Q){
    int i;
    for (i=0;i<=IDX_TAIL(Q);i++){
        printf("%d. %s\n", i+1, Q.buffer[i]);
    }
}

