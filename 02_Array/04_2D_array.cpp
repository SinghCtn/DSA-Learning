#include<iostream>
using namespace std;



int main(){

    // creating 2D aray where everything is stored in the stack

    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;

    // creating the array of pointers that will point to the array's stored in the heap. here the array of pointers will be created of the size of the rows and every row will point to array that will be created in the heap

    int *B[3]; //creating array of pointers stored in the stack.

    B[0] = new int[4]; //creating array in heap and adding it's refrence to the array index 0 present in the stack 
    B[1] = new int[4];
    B[2] = new int[4];
    B[0][1] = 1;
    B[1][2] = 4;
    B[2][3] = 2;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;


    // creating array reference in stack and creating array in the heap;

    int **C; // create a double pointer (A double pointer is a pointer to a pointer, and it can be used to dynamically allocate a 2D array (or other complex data structures) in C++.)

    C = new int *[3]; // created an array of pointers in the heap and passed it's reference to a pointer to a pointer.

    C[0] = new int [4];
    C[1] = new int [4];
    C[2] = new int [4];

    C[0][3] = 1;
    C[1][0] = 4;
    C[2][2] = 2;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;




    return 0;
}