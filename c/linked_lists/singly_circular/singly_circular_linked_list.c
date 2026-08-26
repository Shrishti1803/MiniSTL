#include <stdio.h>
#include <stdlib.h>
#include "singly_circular_linked_list.h"

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
        if(list == NULL){
            list = curr = newnode;
            newnode->next = list; //different from SLL here
        }
        else{
            curr->next = newnode;
            newnode->next = list; //different from SLL here 
            curr = newnode;
        }
    }
    return list;
}

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

    nodeptr newnode, curr;
    int pos, i;

    //take the position :
    printf("Enter the position you where you want to insert : ");
    scanf("%d", &pos);

    if(pos <= 0){
        printf("Invalid position !\n");
        return list;
    }

    //memory alloc
    newnode = (nodeptr) malloc(sizeof(struct Node));

    //data input
    printf("Insert the element : \n");
    scanf("%d", &newnode->data);

    //next of newnode assigned to null
    newnode->next = NULL;

    //empty list
   if(list == NULL){
        list = newnode;
        newnode->next = list;
        return list;
   }

   //first element
    if(pos == 1){
        newnode->next = list;
        for(curr = list; curr->next != list; curr = curr->next); //This will shift current from element 1 to element last
        list = newnode;
        curr->next = list;
        return list;
    }

    //reach till the desired pos using this for loop
    for(i = 1, curr = list ; i != (pos-1) && curr->next != list ; i++, curr = curr->next);

    newnode->next = curr->next;
    curr->next = newnode;
    return list;
}


//Delete function has similar cases
nodeptr del(nodeptr list){
    nodeptr curr = list, curr1;
    int i, pos;

    printf("Enter the position you want to delete : ");
    scanf("%d",&pos);

    if(pos <= 0){
        printf("Invalid position !\n");
        return list;
    }


    if(list == NULL){
        printf("Nothing to delete!\n");
        return list;
    }

    if(pos == 1){
        curr1 = list;
        for(curr = list; curr->next != list; curr = curr->next); //again use this to traverse to the last element 
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
    curr1 = curr->next;
    curr->next = curr1->next;
    free(curr1);
    return list;
}
