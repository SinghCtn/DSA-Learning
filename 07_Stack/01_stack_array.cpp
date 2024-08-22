#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *A;
    
    public:
        Stack(int sz){
            size = sz;
            A = new int [sz];
            top = -1;
        }
        bool isEmpty();
        bool isFull();
        void push(int x);   
        int pop();
        int peek(int index);
        int stackTop();
        ~Stack(){
            delete []A;
        }
};

bool Stack::isFull(){
    return top == size - 1;
}

bool Stack::isEmpty(){
    return top == -1;
}

void Stack::push(int x){
    if(isFull()){
        cout << "Stack overflow. Cannot push " << x << endl;
        return;
    }

    A[++top] = x;
}

int Stack::pop(){
    if(isEmpty()){
        cout << "Stack underflow. Cannot pop." << endl;
        return -1;
    } 

    return A[top--];
}

int Stack::peek(int position){
    int index = top - position + 1;
    if(index >= 0 && index <= top ){
        return A[index];
    }

    cout<<"index out of bounds! Can't peek!!";
    return -1;
}

int Stack::stackTop(){
    if(isEmpty()) return -1;

    return A[top];
}

int main(){
    Stack s(5);
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    cout<<s.pop()<<endl;
    s.push(10);
    s.push(12);
    s.push(90);
    s.push(190);
    s.push(290);
    s.push(320);
    cout<<s.isFull()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.peek(10)<<endl;
    cout<<s.peek(5)<<endl;
    cout<<s.peek(3)<<endl;
    cout<<s.peek(1)<<endl;

    cout<<s.stackTop()<<endl;



    return 0;
}