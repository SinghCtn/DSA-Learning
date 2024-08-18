#include <iostream>
using namespace std;

template <class T>

class Array{
    private: 
        T *A;
        int size;
        int length;
    
    public:
        Array(){
            size = 10;
            A = new T [10];
            length = 0;
        }
        Array(int sz){
            size = sz;
            A = new T [size];
            length = 0;
        }
        ~Array(){
            delete []A;
        }

        void Display();
        void Insert(int index, T x);
        T Delete (int index);
};

template<class T>
void Array<T>::Display(){
    for(int i = 0; i < length; i++){
        cout<<A[i]<<" ";
    }cout<<endl;
}

template<class T>
void Array<T>::Insert(int index, T x){
    if(index >= 0 && index <= length){
        int i = length - 1;
        for(; i >= index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }else{
        cout<<endl<<"Index out of bounds"<<endl;
    }
}

template<class T>
T Array<T>::Delete(int index){
    T x = 0;
    if(index >= 0 && index < length){
        int i = index; 
        x = A[index];
        for(; i < length-1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

int main(){
    Array<float> arr(10);

    arr.Insert(0, 5.3);
    arr.Insert(1, 4.2);
    arr.Insert(2, 9.7);

    arr.Display();

    cout<<arr.Delete(1)<<endl;

    arr.Display();

    return 0;
}