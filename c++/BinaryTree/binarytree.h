#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "treenode.h"
#include<stack>
#include<queue>
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
        void visitAlongLeft(Vertex ,std::stack<Vertex>& ,void (*) (Vertex& ));
        void pushInAlongLeft(Vertex ,std::stack<Vertex>&);

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
        void traverse_pre_recursive_version1(void (* )(Vertex& ));
        void traverse_pre_recursive_version_2(void (* )(Vertex& ));
        void traverse_in_recursive(void (* )(Vertex& ));
        void treverse_post_recursive(void (* )(Vertex& ));
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
    ++_size;
    return node->insertAsLeft(e);
}

template<typename T>
Vertex Tree<T>::insertAsRight(Vertex &node, const T &e){
    ++_size;
    return node->insertAsRight(e);
}

template<typename T> template<typename VST>
void Tree<T>::travIn(Vertex& node, VST& visit){
    if(node){
        travIn(node->left_child, visit);
        visit(node);
        travIn(node->right_child, visit);
    }
}

template<typename T> template<typename VST>
void Tree<T>::travPre(Vertex& node, VST& visit){
    if(node){
        visit(node);
        travPre(node->left_child, visit);
        travPre(node->right_child, visit);
    }
}

template<typename T> template<typename VST>
void Tree<T>::travPost(Vertex& node, VST& visit){
    if(node){
        travPost(node->left_child, visit);
        travPost(node->right_child, visit);
        visit(node);
    }
}

template<typename T>
void Tree<T>::traverse_pre_recursive_version1(void (*visit)(Vertex& node)){
    std::stack<Vertex> istack;
    if(_root!=nullptr){
        istack.push(_root);
    }
    while(!istack.empty()){
        Vertex node = istack.top();
        istack.pop();
        visit(node);
        if(node->right_child!=nullptr){
            istack.push(node->right_child);
        }
        if(node->left_child!=nullptr){
            istack.push(node->left_child);    
        }   
    }
}

template<typename T>
void Tree<T>::visitAlongLeft(Vertex node, std::stack<Vertex> &istack, void (*visit)(Vertex& vnode)){
    while(node!=nullptr){
        visit(node);
        if(node->right_child!=nullptr) istack.push(node->right_child);
        node= node->left_child;
    }
}
template<typename T>
void Tree<T>::traverse_pre_recursive_version_2(void (*visit)(Vertex& node)){
    std::stack<Vertex> istack;
    visitAlongLeft(_root,istack,visit);
    while(!istack.empty()){
        Vertex rn = istack.top();
        istack.pop();
        visitAlongLeft(rn,istack,visit);
    }
}

template<typename T>
void Tree<T>::pushInAlongLeft(Vertex node, std::stack<Vertex> &istack){
    while(node!=nullptr){
        istack.push(node);
        node= node->left_child;
    }
}
template<typename T>
void Tree<T>::traverse_in_recursive(void (*visit)(Vertex& node)){
    std::stack<Vertex> istack;
    pushInAlongLeft(_root,istack);
    while(!istack.empty()){
        Vertex rn = istack.top();
        istack.pop();
        visit(rn);
        if(rn->right_child!=nullptr){
            pushInAlongLeft(rn->right_child,istack);
        }
    }
}

template<typename T>
void Tree<T>::treverse_post_recursive(void (*visit)(Vertex& node)){
    std::stack<Vertex> istack;
    if(_root!=nullptr)  istack.push(_root);
    Vertex pre=nullptr;
    while(!istack.empty()){
        Vertex rn = istack.top();
        if((rn->left_child==nullptr&&rn->right_child==nullptr)||(pre!=nullptr&&(pre==rn->left_child||pre==rn->right_child))){
            visit(rn);
            istack.pop();
            pre = rn;
        }else{
            if(rn->right_child!=nullptr)    istack.push(rn->right_child);
            if(rn->left_child!=nullptr)    istack.push(rn->left_child);
        }
    }
}

template<typename T> template<typename VST>
void Tree<T>::traverse(VST& visit){
    if(_root){
        travPost(_root,visit);
    }
}




#endif


