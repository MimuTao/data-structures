#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "treenode.h"

template<typename T, typename RT>
class Tree{
    private:
        int _height;
        int _size;
        Vertex _iroot;

    public:
        Tree();
        Vertex& root();
        int size() const;
        bool empty() const;
        int height()const;
};

template<typename T,typ>
Tree<T>::Tree(){
    _iroot = new TreeNode<T>();
    _height = -1;
    _size =0;
}

template<typename T>
inline int Tree<T>::size() const{
    return _size;
}

template<typename T>
inline bool Tree<T>::empty() const{
    return _size==0;
}

template<typename T>
inline int Tree<T>::height() const{
    return _height;
}

#endif


