#include<iostream>
using namespace std;

struct Array{
    // int *A; // this is for dynamic array

    int A[10];
    int size;
    int length;
};

// to display array elements
void Display(struct Array arr){
    cout<<"Elements are: ";
    for(int i = 0; i < arr.length; i++){
        cout<<arr.A[i]<<" ";
    }cout<<endl;
}

// to add elements in the end or append
void Append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }else{
        cout<<endl<<"Array is full"<<endl;
    }
}

// to insert element at an particular place
void Insert(struct Array *arr, int index, int x){
    if(index >= 0 && index <= arr->length){
        int i = arr->length;
        for(; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }else{
        cout<<endl<<"Index out of bounds"<<endl;
    }
}

// deletion of element in the array
int Delete(Array *arr, int index){
    int x = 0;
    if(index >= 0 && index < arr->length){
        int i = index; 
        x = arr->A[index];
        for(; i < arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
    return x;
}

// linear search
int LinearSearch(Array arr, int key){
    
    for(int i = 0; i < arr.length; i++){
        if(arr.A[i] == key){
            return i;
        }
    }
    return -1;

}

// swap to swap array elements
void Swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    
}

// LinearSearch by swapng the element with previous one (Transposition)
int TLinearSearch(Array *arr, int key){
    
    for(int i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            if(i != 0){ 
                Swap(&arr->A[i], &arr->A[i-1]);
            }
           
            return i;
        }
    }
    return -1;

}

// LinearSearch by swapng the element with 0 index one (move to head)
int HLinearSearch(Array *arr, int key){
    
    for(int i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            if(i != 0){ 
                Swap(&arr->A[i], &arr->A[0]);
            }
           
            return i;
        }
    }
    return -1;

}

// Binary search Iterative
int BinarySearch(Array arr, int key){
    int l = 0;
    int h = arr.length - 1;
    
    while(l <= h){
        int mid = l + (h - l)/2;

        if(arr.A[mid] == key){
            return mid;
        }else if(arr.A[mid] > key){
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    return -1;

}

// Binary Search Recursive
int RBinarySearch(int a[], int l, int h, int key){
    if(l > h) return -1;

    int mid = l + (h - l)/2;

    if(a[mid] == key){
        return mid;
    }else if(a[mid] > key){
        return RBinarySearch(a, l, mid - 1, key);
    }else{
        return RBinarySearch(a, mid + 1, h, key);
    }
}

// Get is to get an element at a particular index
int Get(Array arr, int index) {
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

// Set is used to change the value at a given index
void Set(Array *arr, int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
}

// To find the maximum element in the array
int Max(Array arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

// To find the minimum element in the array
int Min(Array arr){
    int min = arr.A[0];
    for(int i = 0; i < arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

// Sum of all elements
int Sum (Array arr){
    int sum = 0;
    for(int i = 0; i < arr.length; i++){
        sum += arr.A[i];
    }
    return sum;
}

// Recursive sum of all the elements
int RSum(int arr[], int n){
    if(n < 0) return 0;
    return RSum(arr, n - 1) + arr[n];
}

// Average of the array
int Average(Array arr){
    return Sum(arr)/arr.length;
}

// Reverse contents of Array
void Reverse(Array *arr){
    int *B;
    B = new int[arr->length];

    for(int i = arr->length - 1, j = 0; i >= 0; i--, j++){
        B[j] = arr->A[i];
    }

    for(int i = 0; i < arr->length; i++){
        arr->A[i] = B[i];
    }
}

// Reverse by swaping
void SReverse(Array *arr){
    for(int i = 0, j = arr->length - 1; i < j ;){
        Swap(&arr->A[i++], &arr->A[j--]);
    }
}

// Inserting an element in sorted array
void InsertSort(Array *arr, int x){
    if(arr->length == arr->size) return;

    int i = arr->length - 1;
    while(i >= 0 && arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

// Check if array is sorted
int isSorted(Array arr){
    for(int i = 0; i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]) return 0;
    }
    return 1;
}

// Rearange te -ve's to left and +ve's to the right
void Rearrange(Array *arr){
    int i = 0;
    int j = arr->length - 1;

    while(i < j){
        while(arr->A[i] < 0) i++;
        while(arr->A[j] > 0) j--;
        if(i < j){
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

// Merge two sorted arrays
Array * Merge(Array arr1, Array arr2){
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array;
    

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] > arr2.A[j]) arr3->A[k++] = arr2.A[j++];
        else arr3->A[k++] = arr1.A[i++];
    }

    for(; i < arr1.length; i++){
        arr3->A[k++] = arr1.A[i];
    }
    
    for(; j < arr2.length; j++){
        arr3->A[k++] = arr2.A[j];
    }

    arr3->length = arr1.length + arr2.length;
    arr3->size = 10;

    return arr3;
}

// Union for two sorted arrays
Array * Union(Array arr1, Array arr2){
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array;

    while( i < arr1.length && j < arr2.length){
        if(arr1.A[i] > arr2.A[j]){
            arr3->A[k++] = arr2.A[j++];
        }else if(arr1.A[i] < arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    for(; i < arr1.length;){
        arr3->A[k++] = arr1.A[i++];
    }
    for(; j < arr2.length;){
        arr3->A[k++] = arr2.A[j++];
    }

    arr3->size = 10;
    arr3->length = k;

    return arr3;
}

// Intersection of two sorted arrays
Array * Intersection(Array arr1, Array arr2){
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array;

    while( i < arr1.length && j < arr2.length){
        if(arr1.A[i] > arr2.A[j]){
            j++;
        }else if(arr1.A[i] < arr2.A[j]){
            i++;
        }else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->size = 10;
    arr3->length = k;

    return arr3;
}

// Diffrence b/w two arrays
Array * Diffrence(Array arr1, Array arr2){
    int i = 0, j = 0, k = 0;
    Array * arr3 = new Array;

    while( i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }else if(arr2.A[j] < arr1.A[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }

    for(; i < arr1.length;){
        arr3->A[k++] = arr1.A[i++];
    }

    arr3->size = 10;
    arr3->length = k;

    return arr3;
}

int main(){
    // creating an arr structure 
    /*
    struct Array arr;
    int n;
    cout<<"Enter size of an array: ";
    cin>>arr.size;
    arr.A = new int[arr.size];
    int lenght = 0;

    cout<<endl<<"Enter how many numbers to add in the array"<<endl;
    cin>>n;

    cout<<endl<<"Enter all the elements"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr.A[i];
    }

    arr.length = n;
    */

   Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // Append(&arr, 10);
    // Insert(&arr, 5, 28);
    // cout<<Delete(&arr, 3)<<endl;
    // cout<<LinearSearch(arr, 6)<<endl;
    // cout<<TLinearSearch(&arr, 3)<<endl;
    // cout<<HLinearSearch(&arr, 6)<<endl;
    // cout<<BinarySearch(arr, 4)<<endl;
    // cout<<RBinarySearch(arr.A, 0, arr.length - 1, 6)<<endl; 
    // cout<<Get(arr, 3)<<endl;
    // Set(&arr, 4, 15);
    // cout<<Max(arr)<<endl;
    // cout<<Min(arr)<<endl;
    // cout<<Sum(arr)<<endl;
    // cout<<RSum(arr.A, arr.length)<<endl;
    // cout<<Average(arr)<<endl;
    // Reverse(&arr);
    // SReverse(&arr);
    // InsertSort(&arr, 1);
    // cout<<isSorted(arr)<<endl;

    /*Array arr2 = {{1, -4, 4, -5, -2, 10, 3, 9, -6}, 9, 9};
    Rearrange(&arr2);
    Display(arr2);*/

    // Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    // Array arr2 = {{3, 4 ,7 , 18, 20}, 10, 5};
    // Array * arr3;
    // arr3 = Merge(arr1, arr2);
    // Display(*arr3);
    
    Array arr1 = {{2, 6, 10, 15, 25, 35}, 10, 6};
    Array arr2 = {{3, 6 ,7 , 15, 20, 25}, 10, 6};
    Array * arr3;
    // arr3 = Union(arr1, arr2);
    // arr3 = Intersection(arr1, arr2);
    arr3 = Diffrence(arr1, arr2);
    Display(*arr3);




    // Display(arr);
    
    return 0;
}