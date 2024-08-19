#include <iostream>
using namespace std;

int main(){
    string str1 = "Chetan";

    int i = 0;
    for(;str1[i] != '\0'; i++){
    }
    char str2[i]; 
    int j = 0;
    i -= 1;
    for(; i >= 0; i--, j++){
        str2[j] = str1[i];
    }
    str2[j] = '\0';

    cout<<str2<<endl;

    return 0;
}