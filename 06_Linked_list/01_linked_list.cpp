#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head;
    
    public: 
        LinkedList(){
            head = nullptr;
        }

        void createFromArray(int A[], int i);
        void display();
        // void displayR();
        int count();
        // int countR(int c);
        int sum();
        int max();
        int min();
        Node * search(int x);
        Node * searchH(int key);
        void insert(int index, int x);
};

void LinkedList::createFromArray(int A[], int n){
    Node *last, *temp;
    
    for(int i = 0; i < n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        
        if(!head){
            head = temp;
            last = head;
            continue;
        }

        last->next = temp;
        last = temp;
    }
}

void LinkedList::display(){
    Node *p = head;
    while(p){
        cout<<p->data<<" --> ";
        p = p->next;
    }
    cout<<"NULL"<<endl;
    p = head;
}

// for displaying elements recursively
// void LinkedList::displayR(){
//     static Node *p = head;
//     if(p){
//         cout<<p->data<<" --> ";
//         p = p->next;
//         displayR();
//     }else{
//         cout<<"NULL"<<endl;
//         p = head;
//     }
    
// }

int LinkedList::count(){
    Node *p = head;
    int c = 0; 
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

// Recursive counting 
// int LinkedList::countR(int c){
//     static Node *p = head;
//     if(p){
        
//         p = p->next;
//         c = countR(c) + 1;
//     }
//     p = head;
//     return c;
// }

int LinkedList::sum(){
    int s = 0;
    Node *p = head;
    while(p){
        s += p->data;
        p = p->next;
    }
    return s;
}

int LinkedList::max(){
    int max = INT8_MIN;
    Node *p = head;

    while(p){
        if(max < p->data) max = p->data;
        p = p->next;
    }

    return max;
}

int LinkedList::min(){
    int min = INT8_MAX;
    Node *p = head;

    while(p){
        if(min > p->data) min = p->data;
        p = p->next;
    }

    return min;
}

Node * LinkedList::search(int x){
    Node *p = head;
    while(p){
        if(p->data == x)return p;
        p = p->next;
    }

    return p;
}

// leniar search and iplementing move to head
Node * LinkedList::searchH(int key){
    Node *p = head;
    Node *q = nullptr;
    while(p){
        if(p->data == key){
            if(p == head){
                return p;
            }
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return nullptr;
}

// inserting in a linked list
void LinkedList::insert(int index, int x){
    Node *temp = new Node;
    temp->data = x;

    if(index == 0){
        temp->next = head;
        head = temp;
        return;
    }

    Node *p = head;
    for(int i = 1; i < index; i++){
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;
}

int main(){
    LinkedList list;
    int A[] = {3, 5, 7, 10, 15, 17};

    list.createFromArray(A, 6);

    // cout<<list.countR(0)<<endl;
    cout<<"count: "<<list.count()<<endl;

    cout<<"Sum: "<<list.sum()<<endl;

    cout<<"Max: "<<list.max()<<endl;

    cout<<"Min: "<<list.min()<<endl;

    cout<<"At: "<<list.search(3)<<endl;
    // cout<<"At: "<<list.searchH(7)<<endl;

    list.insert(0, 2);
    list.insert(3, 2);

    list.display();
    
    
    // list.displayR();
    // list.displayR();

    return 0;
}