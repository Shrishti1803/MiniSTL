#ifndef SINGLY_CIRCULAR_LINKED_LIST_H
#define SINGLY_CIRCULAR_LINKED_LIST_H

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* nodeptr;

//SCLL operations
nodeptr create(nodeptr list);
void display(nodeptr list);
void search(nodeptr list);
nodeptr insert(nodeptr list);
nodeptr del(nodeptr list);

#endif