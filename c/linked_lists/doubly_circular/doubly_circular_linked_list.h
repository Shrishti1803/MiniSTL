#ifndef DOUBLY_CIRCULAR_LINKED_LIST_H
#define DOUBLY_CIRCULAR_LINKED_LIST_H

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node* nodeptr;

nodeptr create(nodeptr list);
void display(nodeptr list);
void search(nodeptr list);
nodeptr insert(nodeptr list);
nodeptr del(nodeptr list);

#endif 