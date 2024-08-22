#include<iostream>
using namespace std;

class CQueue{
    private: 
        int size;
        int *Q;
        int f;
        int r;

    public:
        CQueue(int sz){
            size = sz;
            Q = new int [sz];
            f = 0;
            r = 0;
        }
        void enqueue(int x);
        int dequeue();
        ~CQueue(){
            delete []Q;
        }
};

void CQueue::enqueue(int x){
    if((r+1)%size == f){
        cout<<"Queue is full"<<endl;
        return;
    }
    
    r = (r + 1)%size;
    Q[r] = x;
}

int CQueue::dequeue(){
    if(f == r){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    
    f = (f + 1)%size;
    int x = Q[f];

    return x;
}

int main(){

    CQueue q(5);
    cout<<q.dequeue()<<endl;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout<<"done enqueue"<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(7);
    cout<<q.dequeue()<<endl;
    

    return 0;
}