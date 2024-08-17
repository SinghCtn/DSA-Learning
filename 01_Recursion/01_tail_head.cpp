#include <iostream>
using namespace std;

void funTail(int n){
    if(n>0){
        cout<<n;
        funTail(n-1);
    }
}

void funHead(int n){
    if(n>0){
        funHead(n-1);
        cout<<n;    
    }
}

int main(){
    int x = 3;
cout<<"For tail: ";
    funTail(x);
    cout<<endl;
    cout<<"For Head: ";
    funHead(x);
    return 0;
}