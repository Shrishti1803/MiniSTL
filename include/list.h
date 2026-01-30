#include<cstddef> //for the size_t 
#ifndef MINI_LIST_H
#define MINI_LIST_H
namespace mini{


    template <typename T>
    class list{
        private:
            struct Node{
                T data;
                Node* next;
            };
            Node* head;
            Node* tail;
            size_t sz; //it is a type for sizes/counts...It's unsigned 

        public:
            list() : head(nullptr), tail(nullptr), sz(0){
                //the constructor
            }

            ~list(){
                //the deconstructor 
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
                Node* newNode = new Node(value);
                newNode->next = head;
                head = newNode;
                if(sz == 0) tail = newNode; //we check this because if...initially the list is empty.. i.e the size == 0 ... then as soon as we push_front the first element, head and tail both will point to the newNode... ..Because tail = the Last Node
                sz++;
            }
            

            void push_back(const T& value){
                Node* newNode = new Node(value);
        
                if(head == nullptr){ //this is only for the case when initially the list is empty 
                    newNode->next = nullptr;
                    head = newNode;
                    tail = newNode;
                    sz++;
                    return;
                }

                tail->next = newNode;
                tail = newNode;
                sz++;
            }



            size_t size() const{
                return sz;
            }


            bool empty() const{
                return sz == 0;
            }


    };

}
#endif