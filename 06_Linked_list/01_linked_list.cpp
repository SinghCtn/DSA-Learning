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
        void displayR();
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
}

// for displaying elements recursively
void LinkedList::displayR(){
    static Node *p = head;
    if(p){
        cout<<p->data<<" --> ";
        p = p->next;
        displayR();
    }else{
        cout<<"NULL"<<endl;
    }
}

int main(){
    LinkedList list;
    int A[] = {3, 5, 7, 10, 15};

    list.createFromArray(A, 5);
    list.display();

    LinkedList l2;
    l2.displayR();

    return 0;
}