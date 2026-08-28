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
                //the destructor 
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
            
            void pop_front(){
                if(head == nullptr) return;
                Node* curr = head;
                head = curr->next;
                if(sz == 1) tail = nullptr;
                delete(curr);
                sz--;
                return;
            }

            /*
            * pop_back() is O(n) for a singly linked list.
            *
            * Even though we have a tail pointer, a singly linked list
            * cannot move backwards from the tail because each Node only
            * stores a pointer to the next Node.
            *
            * Therefore, we must traverse from head to find the node
            * just before the tail. This traversal takes O(n) time.
            */
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
                    sz++;
                    return;
                }
                if(pos == 1){
                    newnode->next = head;
                    head = newnode;
                    sz++;
                    return;
                }
                for(int i = 1, curr = head; i!= (pos-1) && curr->next != nullptr; i++, curr = curr->next);
                newnode->next = curr->next;
                curr->next = newnode;
                if(pos >= sz+1){
                    tail = newnode;
                }
                sz++;
                return;
            }

            void erase(size_t pos){ //Same as del from C side implementation
               Node* curr = head;
               Node* curr1;
               if(pos == 0) return;
               if(head == nullptr) return;
               if(pos == 1){
                    head = curr->next;
                    if(sz == 1) tail = nullptr;
                    delete(curr);
                    sz--;
                    return;
               }
                for(int i = 1, curr = head; i!= (pos-1) && curr->next != nullptr; i++, curr = curr->next);
                if(curr->next == nullptr) return;
                curr1 = curr->next;
                if(pos == sz) tail = curr;
                curr->next = curr1->next;
                delete(curr1);
                sz--;
                return;
            }

    };

}
#endif
