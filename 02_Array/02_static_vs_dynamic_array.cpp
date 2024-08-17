#include<iostream>
using namespace std;

int main(){

    // static array 
    int A[10] = {2, 4, 6, 8, 10};

    // dynamic array
    // in c
    int *p;
    p = (int *)malloc(5*sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    for(int i = 0; i < 5; i++){
        cout<<p[i]<<" "<<A[i]<<" ";
    } // 1 2 3 4 5 6 7 8 9 10
    cout<<endl;

    // in c++
    int *q;
    q = new int[5];
    q[0] = 1;
    q[1] = 3;
    q[2] = 5;
    q[3] = 7;
    q[4] = 9;
    for(int i = 0; i < 5; i++){
        cout<<q[i]<<" "<<A[i]<<" ";
    } // 1 2 3 4 5 6 7 8 9 10
    cout<<endl;

    delete []p;
     for(int i = 0; i < 5; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;


    return 0;
}