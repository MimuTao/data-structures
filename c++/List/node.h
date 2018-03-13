#ifndef NODE_H
#define NODE_H


#define pNode Node<T>*
template<typename T>
struct Node{
    T data;
    pNode next;
    pNode prior;
    Node() {};    // for head and tail.
    Node(T e, pNode p = nullptr, pNode n = nullptr):data(e),next(n),prior(p){};
    // pNode insertNext(const T &e);
    // pNode insertPrior(const T &e);
};

// template<typename T>
// pNode Node<T>::insertNext(const T &e){
//     pNode _next = new Node(e,this);
//     return _next;
// }

// template<typename T>
// pNode Node<T>::insertPrior(const T &e){
//     pNode _prior = new Node(e,nullptr,this);
//     return _prior;
// }

#endif
