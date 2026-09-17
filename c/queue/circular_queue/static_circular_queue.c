#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c/queue/circular_queue/static_circular_queue.h"

void initqueue(){
    q.rear = q.front = MAX-1;
}

int isempty(){
    return (q.front == q.rear);
}

int isfull(){
    return (q.front == (q.rear+1)%MAX);
}

void add(){
    if(isfull() == 1) printf("Queue is full !\n");
    else{
        q.rear = (q.rear+1)%MAX;
        printf("Enter the number : ");
        scanf("%d",&q.data[q.rear]);
    }
}

void del(){
    if(isempty() == 1) printf("Queue is empty!\n");
    else{
        q.front = (q.front+1)%MAX;
        printf("Deleted element : %d", q.data[q.front]);
    }
}

void display(){
    int i;
    if(isempty() == 1) printf("Queue is empty!\n");
    else{
        for(i = (q.front+1)%MAX ; i != (q.rear+1)%MAX ; i = (i+1)%MAX){
            printf("%d ",q.data[i]);
        }
    }
}
