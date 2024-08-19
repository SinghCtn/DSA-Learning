#include<iostream>
using namespace std;

int main(){
    // using hashtable.
    string A = "finding";
    int arr[26] = {0};

    for(int i = 0; A[i] != '\0'; i++){
        arr[A[i]-97]++;
    }

    for(int i = 0; i < 26; i++){
        if(arr[i] > 1){
            cout<<char(i + 97)<<" appears "<<arr[i]<<" time."<<endl;
        }
    }cout<<endl;


    return 0;
} 