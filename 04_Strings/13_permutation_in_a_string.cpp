#include <iostream>
using namespace std;

void Perm(string s, int k){
    static char res[10], A[10] = {0};
    if(s[k] == '\0'){
        cout<<res<<endl;
    }else{
        for(int i = 0; s[i] != '\0'; i++){
            if(A[i] == 0){
                res[k] = s[i];
                A[i] = 1;
                Perm(s, k+1);
                A[i] = 0;
            }
        }
    }
}

int main(){ 
    string str = "ABCD";
    Perm(str, 0);

    return 0;
}