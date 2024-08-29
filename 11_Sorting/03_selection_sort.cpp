#include<iostream>
using namespace std;

void Sort(int *A, int n){
    for(int i = 0; i < n-1; i++){
        int j, k;
        j = k = i;
        for(; j < n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(A[i], A[k]);
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