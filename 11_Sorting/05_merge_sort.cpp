#include<iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h) {
    int B[h + 1];  // Temporary array to hold merged elements
    int i = l, j = mid + 1, k = l;

    // Merge elements into B
    while(i <= mid && j <= h) {
        if(A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy remaining elements from the left subarray (if any)
    while(i <= mid) {
        B[k++] = A[i++];
    }

    // Copy remaining elements from the right subarray (if any)
    while(j <= h) {
        B[k++] = A[j++];
    }

    // Copy merged elements back into original array A
    for(i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n) {
    int p, l, mid, h;

    // Merge subarrays in bottom-up manner
    for(p = 2; p <= n; p = p * 2) {
        int i;
        for(i = 0; i + p - 1 < n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }

        if (n - i > p / 2) {
            l = i;
            h = n - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }

    // Handle remaining elements
    if((p / 2) < n) {
        Merge(A, 0, (p / 2) - 1, n - 1);
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

    IMergeSort(A, n);  // Sort the array
    Display(A, n);     // Display the sorted array

    return 0;
}
