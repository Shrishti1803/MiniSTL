#include <stdio.h>
#include <stdlib.h>
#include "c/queue/priority_queue/asc_priorityqueue.h"

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
    int i,n;
    if(isfull() == 1) printf("Queue is full !\n");
    else{
        printf("Enter the number : ");
        scanf("%d",&n);
        for(i = q.rear ; i != q.front ; i--){
            if(q.data[i] > n) q.data[i+1]= q.data[i];
            else break;
        }
        q.data[i+1]=n;
        q.rear++;
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