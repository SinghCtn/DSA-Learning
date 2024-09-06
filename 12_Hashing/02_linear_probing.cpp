#include<iostream>
using namespace std;

int Hash(int key){
    return key % 10;
}

void Insert(int H[], int key){
    int index = Hash(key);

    int i = 1;

    while(H[index] != 0){
        index = Hash(index + 1);
        i++;
        if(i == 10){
            cout<<"Table is full"<<endl;
            return;
        }
    }
    H[index] = key;
}

int Search(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while(key != H[index] && H[index] != 0){
        index = (index + 1)%10;
        i++;
        if(i == 10){
            cout<<key<<" not found."<<endl;
            return -1;
        }
    }
    if (H[index] == key) {
        return index;  
    } else {
        cout << key << " not found." << endl;
        return -1;  
    }
}

void PrintHashTable(int H[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": " << H[i] << endl;
    }
}

int main(){
    int HT[10] = {0};  // Initialize all slots to 0 (indicating empty)

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 52);
    Insert(HT, 62);

    PrintHashTable(HT, 10);  // Print the hash table

    int searchKey = 62 ;
    int index = Search(HT, searchKey);  // Search for a key
    if (index != -1) {
        cout << "Key " << searchKey << " found at index " << index << endl;
    }
    return 0;
}