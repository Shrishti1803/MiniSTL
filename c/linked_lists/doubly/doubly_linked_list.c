#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

nodeptr create(nodeptr list){
    nodeptr curr, newnode;
    int n;
    printf("How many list elements? : ");
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
        newnode = (nodeptr) malloc(sizeof(struct Node));
        printf("Element %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(list == NULL){
            list = curr = newnode;
        }
        else{
            curr->next = newnode;
            newnode->prev = curr;
            curr = newnode;
        }
    }
    return list;
}

void display(nodeptr list){
    nodeptr curr = list;
    int i;
    for(i =1 ; curr != NULL; i++, curr = curr->next){
        printf("%d\n", curr->data);
    }
}

void search(nodeptr list){
    int s;
    printf("Enter the element you wish to search : ");
    scanf("%d", &s);
    nodeptr curr = list;
    int i ;
    for(i = 1; curr != NULL ; i++ , curr = curr->next){
        if(s == curr->data){
            printf("Element %d found at position %d\n", s, i);
            return;
        }
    }
    printf("Element not found\n");
    
}

/*insertion works in 4 ways :
1. insertion in empty list 
2. insertion on first element 
3. insertion at mid in the existing list 
4. insertion at last
*/

nodeptr insert(nodeptr list){

    nodeptr newnode, curr = list;
    int pos,i;

    printf("Enter the position you where you want to insert : ");
    scanf("%d", &pos);

    newnode = (nodeptr) malloc(sizeof(struct Node));
    printf("Insert the element : \n");
    scanf("%d", &newnode->data);

    newnode->next = newnode->prev = NULL;


   if(list == NULL){
        list = newnode;
        return list;
   }

    if(pos == 1){
        newnode->next = list;
        curr->prev = newnode;
        list = newnode;
        return list;
    }

    for(i = 1, curr = list ; i != (pos-1) && curr->next != NULL ; i++, curr = curr->next);

    newnode->next = curr->next;
    newnode->prev = curr;
    curr->next->prev = newnode;
    curr->next = newnode;
    return list;
}

//Delete function has similar cases
nodeptr del(nodeptr list){
    nodeptr curr = list;
    nodeptr curr1;
    int i, pos;

    printf("Enter the position you want to delete : ");
    scanf("%d",&pos);
    if(list == NULL){
        printf("Nothing to delete!\n");
        return list;
    }

    if(pos == 1){
        list = curr->next;
        curr->next->prev = curr->prev;//HERE we are showing the links rather that hardcoding NULL // we can also assign curr->next->prev = NULL
        free(curr);
        return list;
    }

    for(i = 1 , curr = list; i != (pos-1) && curr->next != NULL ; i++, curr = curr->next);

    if(curr->next == NULL){
        printf("The position is out of range");
        return list;
    }
    curr1 = curr->next; //assign the value of curr1 because in the end this curr1 is the elemnet that needs to be deleted. 
    curr->next = curr1->next;
    curr1->next->prev = curr;
    free(curr1);
    return list;
}
