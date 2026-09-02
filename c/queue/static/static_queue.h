#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#define MAX 10
struct queue{
    int front,rear;
    int data[MAX];
}q;

void initqueue();
int isempty();
int isfull();
void add();
void del();
void display();

#endif