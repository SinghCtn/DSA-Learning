#include <iostream>
using namespace std;

class Matrix{
    private: 
        int *A;
        int n;
    
    public:
        Matrix(int sz){
            n = sz;
            A = new int [sz];
        }
       
        ~Matrix(){
            delete []A;
        }

        void set(int i, int j, int x);

        int get(int i, int j);

        void display();
};

void Matrix::set(int i, int j, int x){
    if(i == j && i < n && j < n){
        A[i] = x;
        return;
    }
    cout<<"index out of bounds !!"<<endl;
}

int Matrix::get(int i, int j){
    if(i == j && i < n && j < n){
        return A[i];
    }
    return 0;
}

void Matrix::display(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if( i == j ){
                cout<<" "<<A[i]<<" ";
            }else{
                cout<<" 00 ";
            }
        }
        cout<<endl;
    }
    
}

int main(){
    Matrix m(5);
    m.set(0, 0, 43);
    m.set(1, 1, 69);
    m.set(2, 2, 79);
    m.set(3, 3, 69);
    m.set(4, 4, 50);

    m.display();
   
    // cout<<m.get(0, 0)<<endl;
    // cout<<m.get(1, 1)<<endl;
    // cout<<m.get(2, 2)<<endl;
    // cout<<m.get(3, 3)<<endl;
    // cout<<m.get(4, 4)<<endl;


    return 0;
}