#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#define MAX 10
struct stack{
    int top;
    int data[MAX];
}s;

void initstack();
int isempty();
int isfull();
void push();
void pop();
void display();

#endif