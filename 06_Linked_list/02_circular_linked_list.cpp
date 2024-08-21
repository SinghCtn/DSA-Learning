#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class CLinkedList{
    private:
        Node *head;
    
    public:
        CLinkedList(){
            head = nullptr;
        }

        Node * getHead();
        void createFromArray(int A[], int n);
        void display();
        void Rdisplay(Node *list);
        void insert(int index, int x);
        int Delete(int index);
};
Node * CLinkedList::getHead(){
    return head;
}

void CLinkedList::createFromArray(int A[], int n){
    if(n <= 0) return;

    Node *last;
    head = new Node;
    head->data = A[0];
    head->next = last = head;

    
    for(int i = 1; i < n; i++){
        Node *t = new Node;
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void CLinkedList::display(){
    Node * p = head;

    do{
        cout<<p->data<<" -> ";
        p = p->next;
    }while(p != head);

    cout<<"HEAD"<<endl;
}

void CLinkedList::Rdisplay(Node *list){
    static int flag = 0;

    if(list != head || !flag){
        flag = 1;
        cout<<list->data<<" -> ";
        Rdisplay(list->next);
    }else{
        cout<<"HEAD"<<endl;
    }

    flag = 0;
}

void CLinkedList::insert(int index, int x){
    Node * temp = new Node;
    temp->data  = x;
    temp->next = nullptr;
    
    if(!head){
        if (index != 0) {
            cout << "Index out of bounds !!" << endl;
            delete temp;
            return;
        }
        head = temp;
        head->next = head;
        return;
    }

    Node *p = head;

    if(index == 0){
        while(p->next != head){
            p = p->next;
        }

        temp->next = head;
        p->next = temp;
        head = temp;
        return;
    }
    
    for(int i = 1; i < index; i++){
        p = p->next;
        
        if(p->next == head){
            if(i + 1 != index){
                cout<<"Index out of bounds !!"<<endl;
                delete temp;
                return;
            }
            break;
        }
    }

    temp->next = p->next;
    p->next = temp;

}

int CLinkedList::Delete(int index){
    if(!head || index < 0) {
        cout<<"index out of bounds!!"<<endl;
        return -1;
    }

    int x = 0;

    Node* p = head;

    if(index == 0){
        x = head->data;

        if( head->next == head){
            head = nullptr;
            delete p;
            return x;
        }
        
        while(p->next != head){
            p = p->next;
        }
        p->next = head->next;
        p = head;
        head = head->next;
        delete p;
        return x;
    }


    for(int i = 0; i < index-1; i++){
        p = p->next; 
        if(p->next == head){
            cout<<"index out of bounds!!"<<endl;
            return -1;
        }
    }
    Node *q = p->next;
    x = q->data;
    p->next = q->next;
    delete q;
    return x;
}

int main(){

    CLinkedList list;
    int A[] = {1, 4, 6, 34, 69, 92};
    list.createFromArray(A, 6);

    list.insert(3, 10);
    list.display();
    list.insert(0, 100);
    list.display();
    list.insert(8, 169);
    list.display();
    list.insert(10, 200);
    list.display();

    list.Delete(0);
    list.display();
    list.Delete(3);
    list.display();
    list.Delete(6);
    list.display();
    list.Delete(6);


    // list.Rdisplay(list.getHead());
    list.display();



    return 0;
}
