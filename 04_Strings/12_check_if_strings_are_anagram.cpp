#include<iostream>
using namespace std;

int main(){
    string str1 = "decimal";
    string str2 = "medical";

    int A[26] = {0};

    //  TO DO: check length;

    for(int i = 0; str1[i] != '\0' ;i++){
        A[str1[i] - 97]++;
        A[str2[i] - 97]--;
    }

    // for(int i = 0; str2[i] != '\0'; i++){
    //     A[str2[i] - 97]--;
    // }

    for(int i = 0; i < 26; i++){
        if(A[i] != 0){
            cout<<"not a anagram"<<endl;
            break;
        } 
    }

    return 0;
}