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
    TreeNode(T e):parent(nullptr),left_child(nullptr),right_child(nullptr),data(e),height(0){};
    Vertex insertAsLeft(T e);
    Vertex insertAsRight(T e);
};
template<typename T>
Vertex TreeNode<T>::insertAsLeft(T e){
    Vertex node = new TreeNode(e);
    node->parent = this;
    this->left_child = node;
    return node;
}

template<typename T>
Vertex TreeNode<T>::insertAsRight(T e){
    Vertex node = new TreeNode(e);
    node->parent = this;
    this->right_child = node;
    return node;
}


#endif