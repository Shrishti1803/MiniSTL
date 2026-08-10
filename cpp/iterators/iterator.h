#ifndef MY_ITERATOR_H
#define MY_ITERATOR_H
#include<cstddef>
#include "list.h"

namespace mini{

class Iterator{
    private:
        Node* current;

    public:
        //constructor : the starting point 
        Iterator(Node* N) : current(N){
            //empty in this case 
        }

        //dereference : what is there at this position
        int& operator*(){
            return current->data;
        }

        //prefix incr : move to next valid position in the linkedlist
        Iterator& operator++(){
            current = current->next; //pehle we increment the iterator's position
            return *this; //then we return the iterator 
        }

        //comparision : to specify when to stop 
        bool operator!=(const Iterator& other)const{
            return current != other.current; // 
        }

};

}

#endif