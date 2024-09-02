#include<iostream>
using namespace std;

int Max(int A[], int  n){
    int max = A[0];
    for(int i = 1; i < n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n){
    int max, i, j;
    int *C;
    max = Max(A, n);
    C = new int [max];

    for( i = 0; i < max + 1; i++){
        C[i] = 0;
    }

    for( i = 0; i < n; i++){
        C[A[i]]++;
    }

    i = 0, j = 0;

    while(i < max + 1){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        } else {
            i++;
        }
    } 
}

void Display(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);  // Calculate the size of the array

    CountSort(A, n);  // Sort the array
    Display(A, n);

    return 0;
}