#include "D:\SPRING 2023\CS 2\assignments\assignment 3\template_queue.h"
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_customer.h" 

template<class T> queue <T> :: queue(){
    qu = new T[10]; // borrowing from the heap
    maxS = 10;
    front = 0; rear = -1; counterQ = 0;
}
template<class T> queue<T> :: ~queue(){
    delete [] qu; //returning to the heap
}
template<class T> bool queue<T> :: isEmpty(){
    if(!counterQ){return true;}
    else{return false;}
}
template<class T> bool queue<T> :: isFull(){
    if(counterQ< maxS){return false;}
    else{return true;}
}
template<class T> void queue<T> :: enqueue(T x){
    if(!isFull()){
    rear = (rear +1) % maxS;
    *(qu+rear) = x;
    counterQ ++; }
} 
template<class T> T queue<T> :: dequeue(){
    if(isEmpty()){
    exit(EXIT_FAILURE);
    }
    T x = *(qu+front);
    front = (front+1)%maxS; 
    counterQ--;
    return x;
}
template class queue <customer>; // to solve the problem of not defining the template 