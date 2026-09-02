#include <stdio.h>
#include <stdlib.h>
#include "c/stack/dynamic/dynamic_stack.h"

void initstack(){
    top = NULL;
}

int isempty(){
    return (top == NULL);
}

void push(){
    nodeptr newnode;
    newnode = (nodeptr) malloc (sizeof(struct node));
    newnode->next = NULL;
    printf("Enter data : ");
    scanf("%d" , &newnode->data);
    if(top == NULL) top = newnode;
    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop(){
    nodeptr curr = top;
    if(isempty() == 1) printf("Stack is empty!\n");
    else{
        printf("Popped element : %d" , curr->data);
        top = curr->next;
        free(curr);
    }
}

void display(){
    nodeptr curr;
    if(isempty() == 1) printf("Stack is empty !\n");
    else{
        for(curr = top; curr != NULL ; curr = curr->next){
            printf("%d\n", curr->data);
        }
    }
}