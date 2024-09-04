#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void SortedInsert(Node **H, int x) {
    Node *t, *q = nullptr, *p = *H;

    t = new Node;
    t->data = x;
    t->next = nullptr;

    if (!*H) {  // If the list is empty
        *H = t;
        return;
    }

    if ((*H)->data > x) {  // Inserting at the head
        t->next = *H;
        *H = t;
        return;
    }

    while (p && p->data < x) {  // Finding the correct position
        q = p;
        p = p->next;
    }

    q->next = t;  // Insert between q and p
    t->next = p;
}

Node* Search(Node *p, int key) {
    while (p) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

int Hash(int key) {
    return key % 10;  // Simple hash function
}

void Insert(Node *H[], int key) {
    int index = Hash(key);
    // Check for duplicates before inserting (optional)
    if (!Search(H[index], key)) {
        SortedInsert(&H[index], key);
    }
}

// Function to print the hash table for debugging
void PrintHashTable(Node *H[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        Node *p = H[i];
        while (p) {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "nullptr" << endl;
    }
}

int main() {
    Node *HT[10];  // Array of linked lists
    for (int i = 0; i < 10; i++) {
        HT[i] = nullptr;  // Initialize all heads to nullptr
    }

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 52);

    PrintHashTable(HT, 10);  // Print the hash table for debugging

    return 0;
}
