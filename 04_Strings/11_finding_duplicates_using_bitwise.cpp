#include <iostream>
using namespace std;

int main(){

    string A = "finding";
    int h = 0;

    for(int i = 0; A[i] != '\0'; i++){
        int x = 1;
        x = x << (A[i] - 97);

        if((x & h) > 0){
            cout<<A[i]<<" is duplicate"<<endl;
        }else{
            h = (h | x);
        }
    }

    return 0;
}