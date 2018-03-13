#ifndef LIST_H
#define LIST_H

#include "node.h"

template<typename T>
class List{
    private:
        int _size;
        pNode head; 
        pNode tail;

    protected:
        void init();
        int clear();    // return erased node amount.
        pNode GetKth(int k) const;

    public:
        List();
        ~List();
        pNode remove(pNode e);
        T& operator[] (int it);

        inline pNode begin() const {return head->next; }    //return head node.
        inline pNode rend() const {return head; }
        inline pNode end() const {return tail;}   //return tail node.
        inline pNode rbegin() const {return tail->prior;}
        inline int size() const {return _size;}     // return size of list.
        // insert operatoion.
        pNode insert(pNode position,T data);
        pNode insert(int position, T data);
        pNode push_back(T data);
        pNode push_front(T data);

        // remove operation.
        T erase(pNode node);
        T erase(int k);
        int erase(pNode rm_begin, pNode rm_end);    // return how many element removed. from rm_begin before rm_end.

        // find operation.
        pNode find(T data, pNode f_begin, pNode f_end ) const;       //return the pointer to find element else return head/rend(); 
        pNode find(T data) const;
        pNode rfind(T data, pNode rf_begin, pNode rf_end) const;
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
pNode List<T>::GetKth(int k) const {
    if(_size<=k||k<0){
        throw("EXCEPTION_INDEX.");  // if input index is invaild, then throw an exception.
    }
    pNode ret = head->next;
    for(int i=0;i!=k;++i){
        ret = ret->next;
    }
    return ret;
}

template<typename T>
int List<T>::clear(){
    pNode temp = head->next;
    while(temp !=tail){
        delete temp;
    }
    head->next = tail;
    tail->prior = head;
    int ret = _size;
    _size = 0;
    return ret;
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
T& List<T>::operator[](int it){
    pNode result = GetKth(it);
    return result->data;
}

template<typename T>
pNode List<T>::insert(int position,T data){
    pNode cursor = GetKth(position);
    return insert(cursor,data);
}

template<typename T>
pNode List<T>::insert(pNode node, T data){
    pNode in_node = new Node<T>(data,node->prior,node);
    node->prior->next = in_node;
    node->prior = in_node;
    ++_size;
    return in_node;
}

template<typename T>
pNode List<T>::push_back(T data){
    insert(end(),data);
}

template<typename T>
pNode List<T>::push_front(T data){
    insert(begin(),data);
}

template<typename T>
T List<T>::erase(int k){
    pNode result = GetKth(k);
    return erase(result);
}

template<typename T>
T List<T>::erase(pNode node){
    T ret = node->data;     // node is the node to be removed.
    node->prior->next = node->next;
    node->next->prior = node->prior;
    --_size;
    free(node);       // release memery of removed node.
    return ret; 
}

template<typename T>
int List<T>::erase(pNode rm_begin, pNode rm_end){
    pNode node = rm_begin;
    pNode node_next = node->next;
    int ret = 0;
    while(node!=rm_end){
        erase(node);
        node = node_next;
        node_next = node->next;
        ++ret;
    }
    return ret;
}

// find and rfind.
template<typename T>
pNode List<T>::find(T data, pNode f_begin, pNode f_end) const {
    pNode ret = f_begin;
    while((ret->data!=data)&&(ret!=f_end)){
        ret=ret->next;
    }
    return ret;
}
template<typename T>
pNode List<T>::find(T data) const {
    pNode ret = head->next;
    while((ret->data!=data)&&(ret!=end())){
        ret=ret->next;
    }
    return ret;
}

template<typename T>
pNode List<T>::rfind(T data, pNode rf_begin, pNode rf_end) const{
    pNode ret = rf_begin;
    while((ret->data!=data)&&(ret!=rf_end)){
        ret = ret->next;
    }
    return ret;
}


#endif