#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
    private:
        Node *f;
        Node *r;
    
    public:
        Queue(){
            f = r = nullptr;
        }
        void enqueue(int x);
        int dequeue();
};

void Queue::enqueue(int x){
    Node *t = new Node;
    if(!t) {
        cout<<"Queue is full"<<endl;
        return;
    }

    t->data = x;
    t->next = nullptr;

    if(!r){
        f = r = t;
        return;
    }

    r->next = t;
    r = t;
}

int Queue::dequeue(){
    if(!f){
        cout<<"Queue is empty!!"<<endl;
        return -1;
    }
    int x;
    x = f->data;
    Node *p = f;

    if(f == r){
        f = r = nullptr;
        delete p;
        
    }else{
        f = f->next;
        delete p;
    }

    return x;
}

int main(){
    Queue q;
    cout<<q.dequeue()<<endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}