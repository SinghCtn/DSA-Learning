#include<iostream>
using namespace std;

void Sort(int *A, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int temp = A[i];
        while(j >= 0 && A[j] > temp){
            A[j+1] = A[j];
            j--;
        }
        A[j + 1] = temp;
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