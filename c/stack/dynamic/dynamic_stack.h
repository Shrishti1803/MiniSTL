#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

struct node{
    int data;
    struct node* next;
};
typedef struct node* nodeptr;
nodeptr top;

void initstack();
int isempty();
void push();
void pop();
void display();

#endif