#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    
    public:
        Queue(){
            front = rear = nullptr;
        }

        void enqueue(int x){
            Node *temp = new Node;

            if(!temp){return;};
            temp->data = x;
            temp->next = nullptr;
            if(!front){
                front = rear = temp;
                return;
            }

            rear->next = temp;
            rear = temp;
        }

        int dequeue(){
            if(!front){return -1;}
            int x = front->data;
            Node *p = front;
            if(front == rear){
                front = rear = nullptr;
            }else{
                front = front->next;                
            }
            delete p;
            return x;
        }

        int isEmpty(){
            return !front;
        }
};

void BFS(int G[][7], int start, int n){
    int i = start;
    Queue q;
    int visited[7] = {0};

    cout<<i<<" ";
    visited[i] = 1;
    q.enqueue(i);

    while(!q.isEmpty()){
        i = q.dequeue();
        for(int j = 1; j < 7; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                cout<<j<<" ";
                visited[j] = 1;
                q.enqueue(j);
            }
        }

    }
    cout<<endl;

}



int main(){
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    BFS(G, 4, 7);
    return 0;
}