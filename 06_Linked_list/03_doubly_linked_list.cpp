#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
}; 

class DLinkedList{
    private:
        Node *head;
    
    public:
        DLinkedList(){
            head = nullptr;
        }

        void createFromArray(int A[], int n);
        void display();
        void insert(int index, int x);
        int Delete(int index);
        void reverse();
};

void DLinkedList::createFromArray(int A[], int n){
    if(n <= 0){ return; }

    Node *temp, *p;
    
    head = new Node;
    head->data = A[0];
    head->prev = nullptr;
    head->next = nullptr;
    p = head;

    for(int i = 1; i < n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->prev = p;
        temp->next = nullptr;
        p->next = temp;
        p = temp;
    }
}

void DLinkedList::display(){
    if(!head) return;

    Node * p = head;

    while(p){
        cout<<p->data<<" -> ";
        p = p->next;
    }

    cout<<"NULL"<<endl;
}

void DLinkedList::insert(int index, int x){
    if(index < 0) return;

    Node *temp;

    temp = new Node;
    temp->data = x;
    temp->prev = nullptr;
    temp->next = nullptr;

    if(index == 0){
        if(!head){
            head = temp;
            return;
        }

        temp->next = head;
        head->prev = temp; 
        head = temp;
        return;
    }

    Node *p = head;

    for(int i = 1; i < index; i++){
        p = p->next;
        if(!p){
            cout<<"Index out of bounds for index: "<<index<<endl;
            return ;
        }
    }

    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
    if(temp->next){ 
        temp->next->prev = temp; 
    }
}

int DLinkedList::Delete(int index){
    if(index < 0 || !head) return -1;

    int x;
    Node *p = head;

    if(index == 0){
        x = head->data;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete p;
        return x;
    }

    for(int i = 0; i < index; i++){
        p = p->next;
        if(!p){
            return -1;
        }
    }

    x = p->data;
    p->prev->next = p->next;
    if(p->next){
        p->next->prev = p->prev;
    }
    delete p;    
    return x;
}

void DLinkedList::reverse(){
    if(!head || !head->next) return;

    Node *p = head;
    Node *temp = nullptr;

    while(p){
        temp = p->next;  // Store the next node
        p->next = p->prev;  // Reverse the next pointer
        p->prev = temp;  // Reverse the prev pointer
        if(p->prev == nullptr) {  // When p->prev is nullptr, we are at the new head
            head = p;
        }
        p = p->prev;  // Move to the next node in the original list (which is prev in the reversed list)
    }
}



int main(){
    DLinkedList list;

    int A[] = {2, 4, 8, 92, 103};
    list.createFromArray(A, 5);

    list.display();

    // list.insert(0, 1);
    // list.insert(3, 6);
    // list.insert(7, 169);
    // list.insert(10, 200);

    // list.display();

    // cout<<"Deleted: "<<list.Delete(0)<<endl;
    // list.display();
    // cout<<"Deleted: "<<list.Delete(2)<<endl;
    // list.display();
    // cout<<"Deleted: "<<list.Delete(5)<<endl;
    // list.display();
    // cout<<"Deleted: "<<list.Delete(5)<<endl;
    // list.display();

    list.reverse();

    list.display();

    return 0;
}