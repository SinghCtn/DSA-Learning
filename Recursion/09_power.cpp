#include<iostream>
using namespace std;

int pow(int m, int n){
    if( n == 0) return 1;

    return pow(m, n-1) * m;
}

int EffiPow(int m, int n){
    if( n == 0){
        return 1;
    }
    if( n%2 == 0){
        return EffiPow(m*m, n/2);
    }else{
        return m * EffiPow(m*m, n/2);
    }
}

int Ipow (int m, int n){
    int x = 1;
    
    while( n > 0){
        if(n%2 != 0){
            x = x * m;
        }
        m *= m;
        n /= 2;
    }

    return x;
}

int main(){

    cout<<"Iterative: "<<Ipow(2, 9)<<endl;
    cout<<"Efficient Recursive: "<<EffiPow(2, 9)<<endl;
    cout<<"Recursive: "<<pow(2, 9)<<endl;

    return 0;
}