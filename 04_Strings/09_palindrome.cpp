#include <iostream>
using namespace std;

int main(){
    string A = "NAMANA";

    int i = 0, j = 0;

    for(; A[j] != '\0'; j++){}

    j -= 1;

    for(; i < j; i++, j--){
        if(A[i] != A[j]){
            break;
        }
    } 

    if(i >= j){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not-Palindrome"<<endl;
    }

    return 0;
}