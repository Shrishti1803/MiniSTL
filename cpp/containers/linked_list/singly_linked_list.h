#include<cstddef> //for the size_t 
#ifndef MINI_LIST_H
#define MINI_LIST_H
namespace mini{

// Template makes the list generic.
// T is a placeholder for the data type that the list will store.
// The actual type is specified when creating the list object.
    template <typename T>
    class list{
        private:
            struct Node{
                T data;
                Node* next;
                /*
                In C, we write "struct Node*" because "Node" alone is not
                the type name.
                In C++, once the struct is declared, "Node" itself can be
                used as the type name, so we can simply write "Node*".
                */
            };
            Node* head; //equivalent to "list" in the C SLL implementation
            Node* tail;
            size_t sz; //it is a type for sizes/counts...It's unsigned 
            /*
            Node, head, tail and sz are kept private because they are
            the internal working parts of the list.
            The user should not directly change them, otherwise the
            list can become invalid or inconsistent.
            The public functions are used to safely work with the list.
            */

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

/*
push_front()
push_back()

pop_front()
pop_back()

front()
back()

insert()
erase()

size()
empty()

display()       
*/