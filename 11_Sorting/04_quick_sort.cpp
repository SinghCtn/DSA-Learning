#include<iostream>
using namespace std;

int partition(int A[], int l, int h){
    int i = l, j = h;
    int pivot = A[l];

    do{
        do{
            i++;
        }while(A[i] <= pivot);
        do{
            j--;
        }while(A[j] > pivot);
        if(i < j){
            swap(A[i], A[j]);
        }
    }while(i < j);

    swap(A[l], A[j]);

    return j;
}

void Sort(int A[], int l, int h){
    int j;
    if(l < h){
        j = partition(A, l, h);
        Sort(A, l, j);
        Sort(A, j+1, h);
    }
}

void Display(int A[], int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT16_MAX}, n = 11;

    Sort(A, 0, n);
    Display(A, 10);
    
    return 0;
}