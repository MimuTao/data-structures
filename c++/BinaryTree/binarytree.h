#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "treenode.h"

template<typename T>
class Tree{
    private:
        int _size;
        Vertex _root;
    protected:
        template<typename VST> void travIn(Vertex&, VST&);
        template<typename VST> void travPre(Vertex& , VST& );
        template<typename VST> void travPost(Vertex& , VST& );
        template<typename VST> void trvaLevel(Vertex& , VST& );

    public:
        Tree();
        Vertex& root();
        int size() const;
        bool empty() const;
        int height()const;
        Vertex insertAsRoot(const T &e);
        Vertex insertAsLeft(Vertex&, const T &);
        Vertex insertAsRight(Vertex&, const T &);
        template<typename VST> void traverse(VST&);
};

template<typename T>
Tree<T>::Tree(){
    _size =0;
    _root = nullptr;
}

template<typename T>
Vertex & Tree<T>::root(){
    return _root;
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
    // toto 
}

template<typename T>
Vertex Tree<T>::insertAsRoot(const T &e){
    _root = new TreeNode<T>(e);
    ++_size;
    return _root;
}

template<typename T>
Vertex Tree<T>::insertAsLeft(Vertex &node, const T &e){
    return node->insertAsLeft(e);
}

template<typename T>
Vertex Tree<T>::insertAsRight(Vertex &node, const T &e){
    return node->insertAsRight(e);
}

template<typename T> template<typename VST>
void Tree<T>::travIn(TreeNode<T>* &node, VST& visit){
    if(node){
        visit(node);
        travIn(node->left_child, visit);
        travIn(node->right_child, visit);
    }
}

template<typename T> template<typename VST>
void Tree<T>::traverse(VST& visit){
    if(_root){
        travIn(_root,visit);
    }
}




#endif


