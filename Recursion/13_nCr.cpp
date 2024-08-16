#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0) return 1;
    return fact(n-1) * n;
}

int nCr(int n, int r){
    int num = 0, den = 0;

    num = fact(n);
    den = fact(r) * fact(n-r);

    return num / den;
}


// NCR is usesing pascal triangle concept.

int NCR(int n, int r){
    if(r == 0 || r == n){
        return 1;
    }
    return NCR(n-1, r-1) + NCR(n-1, r);
}


int main(){

    cout<<"nCr Recursive: "<<nCr(5, 2)<<endl;
    cout<<"NCR using Pascal's Triangle Recursive: "<<NCR(4, 2)<<endl;
    return 0; 
}