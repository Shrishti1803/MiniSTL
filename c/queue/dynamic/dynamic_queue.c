#include <stdio.h>
#include <stdlib.h>
#include "c/queue/dynamic/dynamic_queue.h"
void initqueue(){
    front = rear = NULL;
}

int isempty(){
    return (rear == NULL);
}

void add(){
    nodeptr newnode;
    newnode = (nodeptr) malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d" , &newnode->data);
    newnode->next = NULL;
    if(rear == NULL) front = rear = newnode;
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void del(){
    if(isempty() == 1) printf("Empty Queue!\n");
    else{
        nodeptr curr;
        curr = front;
        front = curr->next;
        free(curr);
        if(front == NULL) rear = NULL;
    }
}

void display(){
    if(isempty() == 1) printf("Empty Queue!\n");
    else{
        nodeptr curr;
        for(curr = front ; curr!=NULL ; curr = curr->next){
            printf("%d ", curr->data);
        }
    }
}