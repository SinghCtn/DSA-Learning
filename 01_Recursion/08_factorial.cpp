#include <iostream>
using namespace std;

int Ifac (int n){
    int fac = 1;
    for (int i = 1;  i <= n; i++){
        fac = fac * i;
    }
    return fac;
}

int fac (int n){
    if(n == 0){
        return 1;
    }
    return fac(n-1) * n;
}

int main(){

    cout<<"Iterative: "<<Ifac(5)<<endl;

    cout<<"Recursive: "<<fac(5)<<endl;

    return 0;
}