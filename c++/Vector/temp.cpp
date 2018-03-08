#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Scanner{
    private:
    istream &is;
    public:
        Scanner(istream &iste = cin):is(iste){}
        std::string operator()(){
            string in;
            getline(is,in);
            return in;
        }
        int nextInt(){
            int j;
            is>>j;
            return j;
        }
        double nextDouble(){
            double j;
            is>>j;
            return j;
        }
        string next(){
            string j;
            is>>j;
            return j;
        }
        string nextLine(){
            string in;
            getline(is,in);
            getline(is,in);
            return in;
        }
};
struct Func{
    void operator()(int &it) const{
        it++;;
    }
};
void increase(vector<int> &ivec,Func func){
    for(int i=0;i!=ivec.size();++i){
        func(ivec[i]);
    }
}

int search(const vector<int> &ivec,int e,int low,int high){
    int mid=(low+high)/2;
    while(low<high){
        if(ivec[mid]<e){
            low = mid+1;
        }else if(e<ivec[mid]){
            high = mid;
        }else{
            break;
        }
        mid=(low+high)/2;
    }
    return ivec[mid]==e?mid:-1;
}

class Number{
    private:
        int num;

    public:
        Number(int j):num(j){}
        Number():num(0){}
        Number& operator+= (Number &ot){
            num+=ot.num;
            return *this;
        }
        int getNum(){
            return num;
        }
};
int main(void)
{
    Scanner in;
    // string message =in();
    // cout<<message;
    // int *f = [] {return 3};
    // cout << f();
    vector<int> ivec{0,1,2,3,4,5,7,8,9};
    // Func func;
    // increase(ivec,Func());
    // for(vector<int>::iterator it = ivec.begin();it != ivec.end();++it){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // int result = search(ivec,10,0,ivec.size());
    // cout<<result;
    // Number num_1(2);
    // Number num_2(5);
    // num_1+=num_2;
    // cout<<num_1.getNum();
    
}