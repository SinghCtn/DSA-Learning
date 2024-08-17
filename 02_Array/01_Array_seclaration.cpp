#include<iostream>
using namespace std;

void print(int A[], int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    } 
}


int main(){
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[5] = {2, 4};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5, 6};

    cout<<"A: "; print(A, 5); cout<<endl;
    cout<<"B: "; print(B, 5); cout<<endl;
    cout<<"C: "; print(C, 5); cout<<endl;
    cout<<"D: "; print(D, 5); cout<<endl;
    cout<<"E: "; print(E, 6); cout<<endl;

    /*
    A: 1 -1613542728 1749024769 69447548 1 
    B: 1 2 3 4 5 
    C: 2 4 0 0 0 
    D: 0 0 0 0 0 
    E: 1 2 3 4 5 6 
    */

//    See array adresses
    cout<<"Adresses in array: ";
    for(int i = 0; i < 5; i++){
        cout<<&A[i]<<" ";
    }
    cout<<endl;

// Adresses in array: 0x16f41f3a4 0x16f41f3a8 0x16f41f3ac 0x16f41f3b0 0x16f41f3b4
// above can be seen the adresses are contigues.

// access array;
    cout<<B[2]<<endl; // 3
    cout<<2[B]<<endl; // 3
    cout<<*(B+2)<<endl; // 3

    return 0;
}