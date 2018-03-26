#include<iostream>
#include "list.h"
using namespace std;

int main(int argc, char *argv[]){
    List<int> list;
    cout<<"list size is :"<<list.size()<<endl;
    for(int i=0;i!=10;i++){
        list.push_back(i);
    }
    cout<<"Size of list after insert:"<<list.size()<<endl;
    cout<<"elements in list are:";
    for(Node<int>* it = list.begin();it!=list.end();it=it->next){
        cout<<it->data<<" ";
    }
    cout<<endl;
    Node<int> *result = list.find(0);
    if(result!=list.end()){
        cout<<"Found it:"<<result->data<<endl;
    }else{
        cout<<"Not found."<<endl;
    }
    int rm_data = list.erase(3);
    cout<<"Size of list after remove:"<<list.size()<<endl;
    cout<<"elements in list are:";
    for(Node<int>* it = list.begin();it!=list.end();it=it->next){
        cout<<it->data<<" ";
    }
    cout<<endl;

    for(List<int>::iterator iter = list.iter_begin();iter!=list.iter_end();++iter){
        cout<<*iter<<". ";
    }
    cout<<endl;
}
