#include<iostream>
#include "binarytree.h"
#define VERTEX TreeNode<int>*

using namespace std;
template<typename Ty>
class Func{
    public:
        void operator()(Ty &e){
            std::cout<<e->data<<" ";
        }
};
int main(void){
    Tree<int> itree;
    itree.insertAsRoot(1);
    
    Func<VERTEX> funcobj;
    itree.traverse(funcobj);
    VERTEX n1 = itree.root();
    VERTEX n2 = itree.insertAsLeft(n1,2);
    VERTEX n3 = itree.insertAsRight(n1,3);
    VERTEX n4 = itree.insertAsRight(n2,4);
    VERTEX n5 = itree.insertAsRight(n3,5);
    VERTEX n6 = itree.insertAsLeft(n2,6);
    VERTEX n7 = itree.insertAsLeft(n5,7);
    std::cout<<std::endl;
    itree.traverse(funcobj);
    cout<<endl;
    itree.traverse_pre_recursive_version1([](VERTEX &node){cout<<node->data<<" ";});
    cout<<endl;
    itree.traverse_pre_recursive_version_2([](VERTEX &node){cout<<node->data<<" ";});
    cout<<endl;
    itree.traverse_in_recursive([](VERTEX &node){cout<<node->data<<" ";});
    cout<<endl;
    itree.treverse_post_recursive([](VERTEX &node){cout<<node->data<<" ";});
}
