#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

struct node{
    int data;
    struct node* next;
};
typedef struct node* nodeptr;
nodeptr front;
nodeptr rear;

void initqueue();
int isempty();
void add();
void del();
void display();

#endif