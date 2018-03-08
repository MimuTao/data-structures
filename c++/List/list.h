#ifndef LIST_H
#define LIST_H

#include "node.h"
template<typename T>
pNode Node<T>::insertNext(const T &e){

}

template<typename T>
class List{
    private:
        int _size;
        pNode head; 
        pNode tail;

    protected:
        void init();
        int clear();    // return erased node amount.

    public:
        List();
        ~List();
        pNode remove(pNode e);
        T operator[] (int it);
        pNode get()

};

template<typename T>
void List<T>::init(){
    _size = 0;
    head = new Node<T>;
    tail = new Node<T>;
    head->next = tail; head->prior = nullptr;
    tail->next = nullptr;tail->prior = head;
}

template<typename T>
int List<T>::clear(){
    int ret = _size;
    // deal later.
}

template<typename T>
List<T>::List(){
    init();
}

template<typename T>
List<T>::~List(){
    clear();
    delete head; delete tail;
}

template<typename T>
T List<T>::operator[](int it){
    pNode pret = head;
    for(int i=0;i<=it;++i){
        pret = pret->next;
    }
    retrn pret;
}


#endif