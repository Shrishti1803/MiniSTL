#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Node definition
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* nodeptr;

//SLL operations
nodeptr create(nodeptr list);
void display(nodeptr list);
void search(nodeptr list);
nodeptr insert(nodeptr list);
nodeptr del(nodeptr list);

#endif 