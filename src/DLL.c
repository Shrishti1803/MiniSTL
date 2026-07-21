#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node* prev;
};
typedef struct Node* nodeptr;

nodeptr create(nodeptr list){
    list = NULL;
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
            newnode->prev = NULL;
        }
        else{
            curr->next = newnode;
            newnode->next = NULL;
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

    nodeptr newnode;
    newnode = (nodeptr) malloc(sizeof(struct Node));

   //CODE for case 1 :

   if(list == NULL){
        printf("Insert the element : \n");
        scanf("%d", &newnode->data);
        newnode->next = list;
        newnode->prev = NULL;
        list = newnode;
        return list;
   }

    //CODE for case 2 :
    int pos;
    printf("Enter the position you where you want to insert : ");
    scanf("%d", &pos);
    if(pos == 1){
        printf("Insert the element : \n");
        scanf("%d", &newnode->data);
        newnode->next = list;
        newnode->prev = NULL;
        list = newnode;
        return list;
    }

   //CODE for case 3 :
        nodeptr curr;
        int i ;
        for(i = 1, curr = list ; i != (pos-1) && curr->next != NULL ; i++, curr = curr->next);
        printf("Insert the element : \n");
        scanf("%d", &newnode->data);
        newnode->next = curr->next;
        newnode->prev = curr;
        curr->next = newnode;
        return list;
}





int main(){
    nodeptr list;
    int opt;
   
    do{
        printf("\n 0. Exit \n 1.Create \n 2.Display \n 3.Search \n 4.Insert \n 5.Delete\n\n");

        printf("\n\nChoose the option : ");
        scanf("%d", &opt);
        switch(opt){
            case 0 :printf("\nGoodbye!\n");
                    exit(0);

            case 1 :list = create(list);
                    break;

            case 2 :display(list);
                    break;
            
            case 3 :search(list);
                    break;
            
            case 4 :list = insert(list);
                    printf("The list after adding the element is : \n");
                    display(list);
                    break;

            case 5 :list = del(list);
                    printf("The list after deleting the element is : \n");
                    display(list);
                    break;
                
            default : printf("Invalid option !\n\n");
        }

    }
    while(opt != 0);

    
    return 0;
}