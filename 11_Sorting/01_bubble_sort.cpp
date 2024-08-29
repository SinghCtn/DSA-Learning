#include<iostream>
using namespace std;

void Sort(int *A, int n){
    if(n < 1) return;

    for(int i = 0; i < n - 1; i++){
        int j = 0;
        while(j < n - i - 1){
            if(A[j] > A[j + 1]){
                swap(A[j], A[j + 1]);
            }
            j++;
        }
    }
}

void Display(int A[], int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[] = {8, 5, 7, 3, 2};
    Sort(A, 5);
    Display(A, 5);
    return 0;
}