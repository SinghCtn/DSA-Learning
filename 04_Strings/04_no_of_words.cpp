#include<iostream>
using namespace std;

int main(){
    char A[] = "how is the day going ?";
    int spaces = 0;

    for(int i = 0; A[i] != '\0'; i++){
        if(A[i] == ' ' && A[i - 1] != ' ') spaces++; // here we are also checking that the previous one was not a whitespace so that multiple witespaces can't lead to miss calculation of no. of words
    }

    cout<<"no. of words is: "<<spaces + 1<<endl;

    return 0;
}