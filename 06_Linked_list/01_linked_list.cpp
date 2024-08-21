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
        Node * getHead();
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
        void insertSorted(int x);
        int Delete(int index);
        int checkSorted();
        void removeDuplicatesSorted();
        void reverse();
        void concat(Node * list);
        void merge(Node * list);
};

Node * LinkedList::getHead(){
    return head;
}

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
    if(index < 0) return;

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
    if(p){
    temp->next = p->next;
    p->next = temp;
    }else{
        delete temp;
        cout<<"Index out of bounds";
    }
}

// insert in a sorted list
void LinkedList::insertSorted(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    if(!head || head->data >= x){
        temp->next = head;
        head = temp;
        return;
    }

    Node *p = head;
    while(p->next){
        if(p->next->data > x){
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    }

    p->next = temp;
}

int LinkedList::Delete(int index){
    if(!head) return -1;

    Node *p = head;
    int x;
    if(index == 0){
        x = head->data;
        head = head->next;
        delete p;
        return x;
    }

    Node *q = nullptr;

    for(int i = 0; i < index; i++){
        q = p;
        p = p->next;

        if(!p) return -1;
    }
    x = p->data;
    q->next = p->next;
    delete p;
    return x;
}

// check if linked list is sorted or not
int LinkedList::checkSorted(){
    Node *p = head;

    while(p->next){
        if(p->data > p->next->data) return 0;
        p = p->next;
    }

    return 1;
}

// delete duplicates from sorted linked list
void LinkedList::removeDuplicatesSorted(){
    if(!head || !head->next) return;

    Node *p = head->next;
    Node *q = head;

    while(p){
        if(p->data == q->data){
            q->next = p->next;
            delete p;
            p = q->next;
            continue;
        }
        q = q->next;
        p = p->next;
    }
}

// Reversing linked list;
void LinkedList::reverse(){
    Node *p = head;
    Node *q = nullptr;
    Node *r = nullptr;

    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;
}

// concatinate two lists;
void LinkedList::concat(Node * list){
    Node *p = head;

    while(p->next){
        p = p->next;
    }

    p->next = list;
}

// merging two linked lists
void LinkedList::merge(Node *list){
    if(!head){
        head = list;
        return ;
    }

    if(!list) return;

    Node * third;
    Node * last;

    if(head->data < list->data){
        third = last = head;
        head = head->next;
    }else{
        third = last = list;
        list = list->next;
    }

    while(head && list){
        if(head->data < list->data){ 
            last->next = head;
            last = head;
            head = head->next;
        }
        else{ 
            last->next = list;
            last = list;
            list = list->next;
        }
    }

    if(!list){
        last->next = head;
    }else{
        last->next = list;
    }

    head = third;
}

int main(){
    LinkedList list ;
    int A[] = {2, 8, 10, 15};

    list.createFromArray(A, 4);

    // cout<<list.countR(0)<<endl;
    cout<<"count: "<<list.count()<<endl;

    cout<<"Sum: "<<list.sum()<<endl;

    cout<<"Max: "<<list.max()<<endl;

    cout<<"Min: "<<list.min()<<endl;

    cout<<"At: "<<list.search(8)<<endl;
    // cout<<"At: "<<list.searchH(7)<<endl;

    // list.insert(0, 2);
    // list.insertSorted(1);
    // list.insertSorted(8);
    // list.insertSorted(20);

    // cout<<"Deleted: "<<list.Delete(0)<<endl;
    // cout<<"Deleted: "<<list.Delete(0)<<endl;
    // cout<<"Deleted: "<<list.Delete(3)<<endl;
    // cout<<"Deleted: "<<list.Delete(6)<<endl;

    // cout<<"Sorted: "<<list.checkSorted()<<endl;

    // list.removeDuplicatesSorted();


    // list.display();
    // list.reverse();
    
    // LinkedList list2;
    // int A2[] = {92, 32, 54};
    // list2.createFromArray(A2, 3);
    // list.concat(list2.getHead());

    LinkedList list2;
    int A2[] = {4, 7, 12, 14};
    list2.createFromArray(A2, 4);
    list.merge(list2.getHead());

    list.display();    
    // list.displayR();
    // list.displayR();

    return 0;
}