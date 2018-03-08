#include<iostream>
#include"Vector.h"
#include<string>
using namespace std;
struct Out{
    void operator()(const int &i){
        std::cout<<i <<" ";
    }
};
int main(int argc, char *argv[]){
    Vector<int> ivec(10);
    cout<<ivec.size()<<endl;
    try{
        ivec.insert(100,4);
    }catch(const char* e){
        cout<<e<<endl;
    }
    for(int i=0; i!=22;++i){
        ivec.push_back(i);
    }
    cout<<"The size of Vector now is: "<<ivec.size()<<endl;
    cout<<"Elements in ivec are:";
    Out out;
    ivec.traverse(out);
    // ivec.traverse([](const int i) {cout<<i<<" ";});
    cout<<endl;
    cout<<"Set ivec[2] =0"<<endl;
    // ivec.set(2,0);
    ivec[2]=110;
    cout<<"ivec[2] = "<<ivec.at(2)<<endl;
    // ivec.traverse(out);
    cout<<endl;
    cout<<"size:"<<ivec.size()<<" capacity:"<<ivec.capacity()<<endl;
    cout<<"erase numbers:"<<ivec.erase(0,13)<<endl;
    // ivec.traverse(out);
    cout<<endl<<"size:"<<ivec.size()<<" capacity:"<<ivec.capacity()<<endl;
    Vector<int> ivec2;
    ivec2.push_back(5);
    ivec2.push_back(7);
    ivec2.push_back(3);
    ivec2.push_back(1);
    ivec2.push_back(4);
    ivec2.push_back(6);
    ivec2.bubbleSort();
    for(int i = 0; i!=ivec2.size();++i){
        cout<<ivec2[i]<< " ";
    }
    cout<<endl;
}