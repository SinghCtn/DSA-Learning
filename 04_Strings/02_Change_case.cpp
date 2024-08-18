#include<iostream>
using namespace std;

int main(){
    // change from upper to lowe case
    char A[] = "WELCOME";
    for(int i = 0; A[i] != '\0'; i++){
        A[i] = A[i] + 32;
    }
    cout<<A<<endl; // welcome

    // toggle the case;
    char B[] = "WeLcOmE";
    for(int i = 0; B[i]!='\0'; i++){
        if(B[i] >= 65 && B[i] <=90){
            B[i] += 32;
        }else if(B[i] >= 97 && B[i] <= 122){
            B[i] -= 32;
        }
    }
    cout<<B<<endl;

    return 0;
}
