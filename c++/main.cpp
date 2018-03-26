#include<iostream>
#include<vector>

using namespace std;

int main(void){
    vector<int> ivec{1,2,3,4,5,6,7};
    for(vector<int>::iterator it = ivec.begin();it!=ivec.end();++it){
        std::cout<<*it<<" ";
    }  
}