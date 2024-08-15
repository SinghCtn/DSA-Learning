#include<iostream>
using namespace std;

void funB(int n); // this is used because in cpp we can't call a function before it's declared

int fun(int n){
    if(n> 100){
        return n -10;
    }
    return fun(fun(n + 11));
}


int main(){
    cout<<fun(95)<<endl;
    return 0;
}