#include <stdio.h>
#include <stdlib.h>
#include "c/queue/static/static_queue.h"

void initqueue(){
    q.front = q.rear = -1;
}

int isempty(){
    return (q.front == q.rear);
}

int isfull(){
    return (q.rear == MAX-1);
}

void add(){
    if(isfull() == 1) printf("Queue is full!\n");
    else{
        q.rear++;
        printf("Enter number : ");
        scanf("%d", &q.data[q.rear]);
    }
}

void del(){
    if(isempty() == 1) printf("Queue is empty !\n");
    else{
        q.front++;
        printf("Deleted element = %d", q.data[q.front]);
    }
}

void display(){
    int i;
    if(isempty() == 1) printf("Queue is empty! \n");
    else{
        for(i = q.front+1; i <= q.rear ; i++){
            printf("%d ", q.data[i]);
        }
    }
}