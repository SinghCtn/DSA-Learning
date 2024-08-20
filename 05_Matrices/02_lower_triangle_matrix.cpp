#include <iostream>
using namespace std;

class Matrix{
    private: 
        int *A;
        int n;

    public:

        Matrix(int sz){
            n = sz;
            A = new int [(sz)*(sz-1)/2];
        }

        // RM: Row major and CM: Column major.
        void setRM(int i, int j, int x);

        int getRM(int i, int j);
        
        void displayRM();

        void setCM(int i, int j, int x);

        int getCM(int i, int j);

        void displayCM();

        void enterAllElements();

        ~Matrix(){
            delete []A;
        }
};

void Matrix::setRM(int i, int j, int x){
    if(i >= j){
        A[((i*(i-1))/2) + j-1] = x;
    }
}

int Matrix::getRM(int i, int j){
    if(i >= j){
        return A[((i*(i-1))/2) + j-1];
    }
    return 0;
}

void Matrix::setCM(int i, int j, int x){

}

int Matrix::getCM(int i, int j){
    return 1;
}

void Matrix::displayRM(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if( i >= j){
                cout<<A[((i*(i-1))/2) + j-1]<<" ";
            }else{
                cout<<"00 ";
            }
        }
        cout<<endl;
    }
}

void Matrix::enterAllElements(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin>>x;
            setRM(i, j, x);
        }
    }
}



int main(){
    Matrix m(5);
    m.enterAllElements();

    m.displayRM();

    return 0;
}