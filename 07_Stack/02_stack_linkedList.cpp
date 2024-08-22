#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
    private:
        Node *top;
    
    public:
        Stack(){
            top = nullptr;
        }

        bool isEmpty();
        bool isFull();
        void push(int x);
        int pop();
        int peek(int position);
        int topElement();
};

bool Stack::isEmpty(){
    return top == nullptr;
}

bool Stack::isFull(){
    Node *temp = new Node;
    return temp == nullptr;
}

void Stack::push(int x){
    if(isFull()) {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

int Stack::pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }

    int x = top->data;
    Node *t = top;
    top = top->next;
    delete t;
    return x;
}

int Stack::peek(int position){
    if(position < 1) {
        cout<<"index out of bounds"<<endl;
        return -1;
    }
    Node *p = top;

    for (int i = 1; p != nullptr && i < position; i++) {
        p = p->next;
    }

    if (p != nullptr) {
        return p->data;
    } else {
        cout << "Position out of bounds" << endl;
        return -1;
    }
}

int Stack::topElement(){
    if(isEmpty()) return -1;

    return top->data;
}


int main(){
    Stack s;
    cout<<"is empty: "<<s.isEmpty()<<endl;
    cout<<"is full: "<<s.isFull()<<endl;
    cout<<"pop: "<<s.pop()<<endl;
    s.push(1);
    s.push(23);
    s.push(43);
    s.push(69);
    s.push(102);
    cout<<"pop: "<<s.pop()<<endl;
    cout<<"peek: "<<s.peek(0)<<endl;
    cout<<"peek: "<<s.peek(4)<<endl;
    cout<<"peek: "<<s.peek(1)<<endl;
    cout<<"peek: "<<s.peek(5)<<endl;
    cout<<"top: "<<s.topElement()<<endl;


    return 0;
}