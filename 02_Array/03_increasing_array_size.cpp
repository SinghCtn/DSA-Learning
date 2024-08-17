#include<iostream> 
using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int *p, *q;

    p = (int *)malloc(5*sizeof(int));
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    print(p, 5);

    q = new int[10];

    for(int i = 0; i < 5; i++){
        q[i] = p[i];
    }

    print(q, 10);

    delete []p;

    p = q;
    p[5] = 6;

    print(p, 10);

    q = NULL;

    return 0;
}