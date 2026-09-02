#include <stdio.h>
#include "c/stack/static/static_stack.h"

void initstack(){
    s.top = -1;
}

int isempty(){
    return (s.top == -1);
}

int isfull(){
    return (s.top == MAX-1);
}

void push(){
    if(isfull() == 1) printf("Stack is full !!\n");
    else{
        s.top++;
        printf("Enter the data : ");
        scanf("%d" , &s.data[s.top]);
    }
}

void pop(){
    if(isempty() == 1) printf("Stack is empty !!\n");
    else{
        printf("Data popped = %d", s.data[s.top]);
        s.top--;
    }
}

void display(){
    int i;
    if(isempty() == 1) printf("Stack is empty !!\n");
    else{
        for(i = s.top; i >= 0 ; i--){
            printf("%d\n" , s.data[i]);
        }
    }
}