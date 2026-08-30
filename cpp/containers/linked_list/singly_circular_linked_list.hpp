#pragma once
#include<cstddef> 

namespace mini{
    template <typename T>
    class sclist{
        private:
            struct Node{
                T data;
                Node* next;

            };
            Node* head; 
            Node* tail;
            size_t sz; 

        public:
            list() : head(nullptr), tail(nullptr), sz(0){}

            ~list(){
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
                newnode->next = head;
                if(sz == 0){
                    tail = head = newnode; 
                    tail->next = newnode;
                    sz++;
                    return;
                }
                head = newnode;
                tail->next = newnode;
                sz++;
            }
            

            void push_back(const T& value){
                Node* newnode = new Node(value);
                if(head == nullptr){ 
                    head = tail = newnode;
                    newnode->next = head;
                    sz++;
                    return;
                }
                tail->next = newnode;
                newnode->next = head;
                tail = newnode;
                sz++;
            }
            
            void pop_front(){
                if(head == nullptr) return;
                Node* curr = head;
                head = curr->next;
                tail->next = curr->next;
                if(sz == 1) head = tail = nullptr;
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
                Node* curr;
                for(curr = head; curr->next!=tail; curr = curr->next);
                curr->next = currdel->next;
                tail = curr;
                sz--;
                delete(currdel);
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
                Node* newnode = new Node(value);
                newnode->next = nullptr;
                if(head == nullptr){
                    head = tail = newnode;
                    tail->next = newnode;
                    sz++;
                    return;
                }
                if(pos == 1){
                    newnode->next = head;
                    head = newnode;
                    tail->next = newnode;
                    sz++;
                    return;
                }
                for(int i = 1, curr = head; i!= (pos-1) && curr->next != head; i++, curr = curr->next);
                newnode->next = curr->next;
                curr->next = newnode;
                if(pos >= sz+1){
                    tail = newnode;
                }
                sz++;
                return;
            }

            void erase(size_t pos){ 
                if(pos == 0) return;
                if(head == nullptr) return;
                Node* curr = head;
                Node* curr1;
                if(pos == 1){
                    head = curr->next;
                    tail->next = head;
                    if(sz == 1) head = tail = nullptr;
                    delete(curr);
                    sz--;
                    return;
                }
                for(int i = 1, curr = head; i!= (pos-1) && curr->next != head; i++, curr = curr->next);
                if(curr->next == head) return;
                curr1 = curr->next;
                if(pos == sz){
                    tail = curr;
                    tail->next = head;
                    delete(curr1);
                    sz--;
                    return;
                }
                curr->next = curr1->next;
                delete(curr1);
                sz--;
                return;
            }

    };

}