#include <stdio.h>
#include <stdlib.h>
#include "doubly_circular_linked_list.h"

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
            newnode->next = newnode->prev = list; //different from DLL
        }
        else{
            curr->next = newnode;
            newnode->prev = curr;
            newnode->next = list; //diff from DLL
            list->prev = newnode; //diff from DLL
            curr = newnode;
        }
    }
    return list;
}

//Search and display are the same as SCLL
void display(nodeptr list){
    nodeptr curr;
    if(list == NULL){
        printf("Nothing to display! \n");
        return;
    }
    for(curr = list ; curr->next != list; curr = curr->next){
        printf("%d\n", curr->data);
    }
    printf("%d\n", curr->data); //for printing the last element 

}

void search(nodeptr list){
    int s;
    if(list == NULL){
        printf("Nothing to search.\nList is empty! \n");
        return;
    }
    printf("Enter the element you wish to search : ");
    scanf("%d", &s);
    nodeptr curr = list;
    int i ;
    for(i = 1; curr->next != list ; i++ , curr = curr->next){
        if(s == curr->data){
            printf("Element %d found at position %d\n", s, i);
            return;
        }
    }
    //same logic as display, we check the condition here as well.
    if(s == curr->data){
        printf("Element %d found at position %d\n", s, i);
        return;
    }

    printf("Element not found\n");
    
}

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
        newnode->next = newnode->prev = list;
        return list;
   }

    if(pos == 1){
        newnode->next = list;
        curr->prev = newnode;
        for(curr = list; curr->next != list; curr = curr->next); //This will shift current from element 1 to element last
        curr->next = newnode;
        newnode->prev = curr;
        list = newnode;
        return list;
    }

    for(i = 1, curr = list ; i != (pos-1) && curr->next != list ; i++, curr = curr->next);

    newnode->next = curr->next;
    newnode->prev = curr;
    curr->next->prev = newnode;
    curr->next = newnode;
    return list;
}


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
        curr1 = curr;
        curr->next->prev = curr->prev;//HERE we are showing the links rather that hardcoding NULL // we can also assign curr->next->prev = NULL
        for(i = 1, curr = list ; i != (pos-1) && curr->next != list ; i++, curr = curr->next);
        curr->next = curr1->next;
        list = curr1->next;
        free(curr1);
        return list;
    }

    for(i = 1 , curr = list; i != (pos-1) && curr->next != list ; i++, curr = curr->next);

    if(curr->next == list){
        printf("The position is out of range");
        return list;
    }
    curr1 = curr->next; //assign the value of curr1 because in the end this curr1 is the elemnet that needs to be deleted. 
    curr->next = curr1->next;
    curr1->next->prev = curr;
    free(curr1);
    return list;
}
