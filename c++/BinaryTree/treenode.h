#ifndef TREE_NODE_H
#define TREE_NODE_H

#define Vertex TreeNode<T>*       //Vertex is the pointer to TreeNode.
template<typename T>
struct TreeNode{
    T data;
    Vertex parent;
    Vertex left_child;
    Vertex right_child;
    int height;
    TreeNode():left_child(nullptr),parent(nullptr),right_child(nullptr),height(0){};
    TreeNode(const T &e):parent(nullptr),left_child(nullptr),right_child(nullptr),data(e),height(0){};
    Vertex insertAsLeft(const T &e);
    Vertex insertAsRight(const T &e);
    // template<typename VST> void travseIn(VST& );
    // template<typename VST> void travsePre(VST& );
    // template<typename VST> void travsePre(VST& );
    // template<typename VST> void travseLevel(VST& )
};
template<typename T>
Vertex TreeNode<T>::insertAsLeft(const T &e){
    Vertex node = new TreeNode(e);
    node->parent = this;
    this->left_child = node;
    return node;
}

template<typename T>
Vertex TreeNode<T>::insertAsRight(const T &e){
    Vertex node = new TreeNode(e);
    node->parent = this;
    this->right_child = node;
    return node;
}

#endif