#include<iostream>
using namespace std;

double iterative(int x, int n){
    double s = 1;

    while(n != 0){
        s = 1 + (x * s) / n;
        n--;
    }
    return s;
}

double recursive (int x, int n){
    static double s = 1;
    if(n == 0) return s;
    s = 1 + (x * s)/ n ;

    return recursive(x, n-1);
}

int main(){
    
    cout<<"Iterative: "<<iterative(2, 10)<<endl;
    cout<<"Recursive: "<<recursive(2, 10)<<endl;
    

    return 0;

}