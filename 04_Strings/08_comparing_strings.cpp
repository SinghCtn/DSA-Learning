#include<iostream>
using namespace std;

int main(){
    string A = "Painter";
    // string B = "Painter";
    // string B = "Paintar";
    string B = "Painting";

    int i, j;

    for( i = 0, j = 0; A[i] != '\0' || A[j] != '\0'; i++, j++){
        if(A[i] != B[j]){
            break;
        }
    }

    if(A[i] == B[j]){
        cout<<"equal"<<endl;
    }else if(A[i] < B[j]){
        cout<<"smaller"<<endl;
    }else{
        cout<<"greater"<<endl;
    }
}