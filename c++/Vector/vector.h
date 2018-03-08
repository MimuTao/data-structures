#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template<typename T>
class Vector{
    protected:
        int _size;
        int _capacity;
        T* _array;
        void copyFrom(T* array,int low,int high);
        void expand();
        void shrink();
    public:
        Vector(int capacity =10);
        ~Vector();
        int size();
        int capacity();
        T at(int i);
        void set(int i, T e);
        T& operator[](int i);
        void insert(int i, T e);
        void push_back(T e);
        void push_front(T e);
        T erase(int i);
        int erase(int low,int high);
        T pop_back();
        T pop_front();
        template<typename F>
        void traverse(F func);
        bool emtpy();
        int find(const T &e, int low, int high);
        int disordered() const;
        void bubbleSort();
};


template<typename T>
Vector<T>::Vector(int capacity):_size(0),_capacity(capacity){
    _array = new T[_capacity];
}

template<typename T>
Vector<T>::~Vector(){
    delete [] _array;
}

template<typename T>
int Vector<T>::size(){
    return _size;
}

template<typename T>
int Vector<T>::capacity(){
    return _capacity;
}

template<typename T>
T Vector<T>::at(int i){
    return _array[i];
}

template<typename T>
void Vector<T>::set(int i, T e){
    if(i<0 || _size <= i){
        throw "IndexException.";
    }
    _array[i] = e;
}

template<typename T>
T& Vector<T>::operator[](int i){
    if(i<0 || _size<=i){
        throw "IndexException.";
    }
    return _array[i];
}

template<typename T>
void Vector<T>::insert(int i, T e){
    if(i<0 || _size<i){
        throw "IndexException.";
    }
    expand();   
    for(int it = _size;it!=i;--it){
       _array[it] = _array[it-1];
    }
    _array[i]=e;
    ++_size;
}

template<typename T>
void Vector<T>::push_back(T e){
    insert(_size,e);
}

template<typename T>
void Vector<T>::push_front(T e){
    insert(0,e);
}

template<typename T>
T Vector<T>::erase(int i){
    if(i<0 || _size<=i){
        throw "IndexException.";
    }
    for(int it=i;it!=_size-1;++it){
        _array[it] = _array[it+1];
    }
    shrink();
    return _array[--_size];
}

template<typename T>
int Vector<T>::erase(int low,int high){
    if(low == high)
        return 0;
    while(high!=_size){
        _array[low++]=_array[high++];
    }
    _size = _size+low-high;    
    shrink(); 
    return high - low;
}

template<typename T>
T Vector<T>::pop_back(){
    return erase(_size-1);
}

template<typename T>
T Vector<T>::pop_front(){
    return erase(0);
}

template<typename T> template<typename F>
void Vector<T>::traverse(F func){
    for(int i=0;i!=_size;++i){
        func(_array[i]);
    }
}

template<typename T>
bool Vector<T>::emtpy(){
    return _size == 0;
}

template<typename T>
int Vector<T>::find(const T &e, int low,int high){
    while(--high>=low){
        if(_array[high]==e)
            break;
    }
    return high;    // if find return pos, not find return low-1;
}

template<typename T>
int Vector<T>::disordered() const{
    int ret=0;
    for(int i=1;i!=_size;++i){
        if(_array[i-1]>_array[i])
            ++ret;
    }
    return ret;
}

template<typename T>
void Vector<T>::bubbleSort(){
    for(int i = 0; i!= _size;++i){
        bool ordered = true;
        for(int j =0;j!=_size -i-1;++j){
            if(_array[j]>_array[j+1]){
                T temp = _array[j];
                _array[j] = _array[j+1];
                _array[j+1] = temp;
                ordered = false;
            }
        }
        if(ordered)
            break;
    }
}

template<typename T>
void Vector<T>::copyFrom(T* const array, int low, int high){
    _array = new T[_capacity = 2*(high - low)];
    _size = 0;
    while(low < high){
        _array[_size++] = array[low++];
    }
}

template<typename T>
void Vector<T>::expand(){
    if(_size<_capacity){
        return;
    }
    _capacity = 2*_capacity;
    T* early = _array;
    _array = new T[_capacity];
    copyFrom(early,0,_size);
    delete [] early;
}

template<typename T>
void Vector<T>::shrink(){
    if(_capacity/4<_size){
        return;
    }
    T* before = _array; 
    _array = new T[_capacity = _capacity/2];
    for(int i=0;i!=_size;++i){
        _array[i]=before[i];
    }
    delete [] before;
}


#endif // VECTOR_H
