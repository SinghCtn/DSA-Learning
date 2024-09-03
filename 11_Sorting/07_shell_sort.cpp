#include<iostream>
using namespace std;

void ShellSort(int A[], int n){
    int gap, i, j;

    // Start with a big gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (i = gap; i < n; i++) {
            int temp = A[i];
            j = i - gap;

            // Shift earlier gap-sorted elements up until the correct location for A[i] is found
            while (j >= 0 && A[j] > temp) {
                A[j + gap] = A[j];
                j -= gap;
            }

            // Put temp (the original A[i]) in its correct location
            A[j + gap] = temp;
        }
    }
}

void Display(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);  // Calculate the size of the array

    ShellSort(A, n);  // Sort the array
    Display(A, n);    // Display the sorted array

    return 0; 
}
