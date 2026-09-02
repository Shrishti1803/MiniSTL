#pragma once
#include<cstddef> 

namespace mini{

    template <typename T>
    class dclist{
        private:
            struct Node{
                T data;
                Node* next;
                Node* prev;
            };
            Node* head;
            Node* tail;
            size_t sz; 


        public:
            dlist() : head(nullptr), tail(nullptr), sz(0){
            }

            ~dlist(){
                Node* temp = head;
                while(temp != nullptr){
                    Node* nextNode = temp->next;
                    delete temp;
                    temp = nextNode;
                }
                head = nullptr;  
                tail = nullptr;
                sz = 0;  
            }

            void push_front(const T& value){
                Node* newnode = new Node(value);
                if(sz == 0){
                    head = tail = newnode; 
                    newnode->prev = newnode;
                    newnode->next = newnode;
                    sz++;
                    return;
                }
                newnode->next = head;
                head->prev = newnode;
                tail->next = newnode;
                newnode->prev = tail;
                head = newnode;
                sz++;
            }
            
            void push_back(const T& value){
                Node* newnode = new Node(value);
        
                if(head == nullptr){ 
                    newnode->next = newnode->prev = newnode;
                    head = tail = newnode;
                    sz++;
                    return;
                }
                newnode->prev = tail;
                newnode->next = tail->next;
                tail->next = newnode;
                tail = newnode;
                head->prev = newnode;
                sz++;
            }
            
            void pop_front(){
                if(head == nullptr) return;
                Node* curr = head;
                if(sz == 1) head = tail = nullptr;
                else{
                    curr->next->prev = curr->prev;
                    tail->next = curr->next;
                    head = curr->next;
                }
                delete(curr);
                sz--;
                return;
            }

            void pop_back(){
                if(tail == nullptr) return;
                Node* currdel = tail;
                if(sz == 1){
                    tail = head = nullptr;
                    sz--;
                    delete(currdel);
                    return;
                }
                Node* curr = tail->prev;
                curr->next = tail->next;
                head->prev = curr;
                tail = curr;
                delete(currdel);
                sz--;
            }

            size_t size() const{
                return sz;
            }


            bool empty() const{
                return sz == 0;
            }

            T& front(){
                return head->data;
            }
            const T& front() const{
                return head->data;
            }


            T& back(){
                return tail->data;
            }
            const T& back() const{
                return tail->data;
            }


            void insert(const T& value , size_t pos){
                if(pos == 0) return;
                Node* curr;
                int i;
                Node* newnode = new Node(value);
                newnode->next = newnode->prev = nullptr;
                if(head == nullptr){
                    newnode->next = newnode->prev = newnode;
                    head = tail = newnode;
                    sz++;
                    return;
                }
                if(pos == 1){
                    newnode->next = head;
                    newnode->prev = head->prev; //no such difference but yeah
                    head->prev = newnode;
                    tail->next = newnode;
                    head = newnode;
                    sz++;
                    return;
                }
                if(pos <= (sz/2)){
                    for(i = 1, curr = head; i!= (pos-1) ; i++, curr = curr->next);
                    newnode->next = curr->next;
                    newnode->prev =  curr;
                    curr->next->prev = newnode;
                    curr->next = newnode;
                    sz++;
                    return;
                }
                else{
                    for(i = sz, curr = tail; i > (sz/2) && i != (pos+1); --i, curr=curr->prev);
                    newnode->next = curr;
                    newnode->prev = curr->prev;
                    curr->prev->next = newnode;
                    curr->prev = newnode;
                    sz++;
                    return;
                }
            }

            void erase(size_t pos){ 
               if(pos == 0) return;
               if(head == nullptr) return;
               if(pos > sz) return;
               Node* curr = head;
               int i;
               if(pos == 1){
                    if(sz == 1){
                        head = tail = nullptr;
                        delete(curr);
                        sz--;
                        return;
                    }
                    curr->next->prev = curr->prev;
                    tail->next = curr->next;
                    head = curr->next;
                    delete(curr);
                    sz--;
                    return;
               }
               if(pos == sz){
                curr = tail;
                curr->prev->next = curr->next;
                head->prev = curr->prev;
                tail = curr->prev;
                delete(curr);
                sz--;
                return;
               }
                Node* curr1;
                if(pos <= (sz/2)){
                    for(i = 1, curr = head; i!= (pos-1) ; i++, curr = curr->next);
                    curr1 = curr->next;
                    curr->next = curr1->next;
                    curr1->next->prev = curr;
                    delete(curr1);
                    sz--;
                    return;
                }
                else{
                    for(i = sz, curr = tail; i > (sz/2) && i != (pos+1); --i, curr=curr->prev);
                    curr1 = curr->prev;
                    curr->prev = curr1->prev;
                    curr1->prev->next = curr;
                    delete(curr1);
                    sz--;
                    return;
                }

            }

    };

}