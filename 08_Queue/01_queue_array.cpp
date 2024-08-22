#include<iostream>
using namespace std;

class Queue{
    private:
        int f;
        int r;
        int size;
        int *Q;
    
    public:
        Queue(int sz){
            f = -1;
            r = -1;
            size = sz;
            Q = new int [size];
        }
        void enqueue(int x);
        int dequeue();
        ~Queue(){
            delete []Q;
        }
};

void Queue::enqueue(int x){
    if(r < size-1){
        Q[++r] = x;
        return;
    }
    cout<<"queue is full"<<endl;
}

int Queue::dequeue(){
    if(f == r){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    return Q[++f];
}

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}