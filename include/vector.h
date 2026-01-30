#include<cstddef>
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
/*Vectors are defined by three main objects : 
1) pointer to the first element 
2) size - the number of elements in the vector 
3)capacity - tells how many elements can fit in the vector without reallocating
*/
namespace mini{

    template<typename T>
    class vector{
        private:
        T* ptr;
        size_t sz;
        size_t cap;

        /*
        this helper function just allocates the new memory and deletes the old one.. does not return anything 
        the one work of this function is to copy the old
        elements to the newly allocated memory 
        and delete the old memory
        */
        void reallocation(size_t new_cap){ 
            T* new_ptr = new T[new_cap];
            for( size_t i = 0 ; i < sz ; i++){
                new_ptr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = new_ptr;
            cap = new_cap;
        }

        public:
        vector(): ptr(nullptr), sz(0), cap(0){
            //constructor 
        }
        
        ~vector(){
            //the deconstructor 
            delete[] ptr;
        }

        void push_back(const T& value){
            if(sz == cap){
                size_t new_cap = {(cap == 0) ? 1 : (cap*2)};
                reallocation(new_cap);
            }
            ptr[sz] = value;
            ++sz;
            
        }


    };
}
#endif

//This is the initial push_back code : the basic and lengthy version 

/*
void push_back(const T& value) {
    if (sz < cap) {
        ptr[sz] = value;
        sz++;
    }
    else if (sz == cap) {

        // Case 1: first insertion (cap == 0)
        if (cap == 0) {
            size_t new_cap = 1;
            T* new_ptr = new T[new_cap];

            for (size_t i = 0; i < sz; i++) {
                new_ptr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = new_ptr;
            cap = new_cap;

            ptr[sz] = value;
            sz++;
        }

        // Case 2: grow capacity (cap > 0)
        else {
            size_t new_cap = cap * 2;
            T* new_ptr = new T[new_cap];

            for (size_t i = 0; i < sz; i++) {
                new_ptr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = new_ptr;
            cap = new_cap;

            ptr[sz] = value;
            sz++;
        }
    }
}

*/