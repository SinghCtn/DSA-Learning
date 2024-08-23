#include <iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
};

struct QNode{
    Node *add;
    QNode *next;
};

class Queue{
    private: 
        QNode *f;
        QNode *r;
    public:
        Queue(){
            f = r = nullptr;
        }

        void enqueue(Node *x){
            QNode *t = new QNode;
            if(!t) return;
            t->add = x;
            t->next = nullptr;

            if(!r){
                f = r = t;
                return;
            }

            r->next = t;
            r = t;
        }

        Node * dequeue(){
            if(!f) return nullptr;

            Node *x = f->add;
            QNode *p = f;

            if(f == r){
                f = r = nullptr;
            }else{
                f = f->next;
            }
            delete p;
            return x;
        }

        bool isEmpty(){
            return f == nullptr;
        }

};

class Stack{
    private: 
        QNode *top;

    public:
        Stack() {top = nullptr;}

        void push (Node *x){
            QNode *t = new QNode;
            if(!t) return;
            t->add = x;
            t->next = top;
            top = t;
        }

        Node * pop(){
            if(!top) return nullptr;
            Node *p = top->add;
            QNode *t = top;
            top = top->next;
            delete t;
            return p;
        }

        bool isEmpty() const {
            return top == nullptr;
        }

        ~Stack() {
        while (top) {
            QNode *temp = top;
            top = top->next;
            delete temp;
        }
    }

};

class Tree{
    private:
        Node *root;

    public:
        Tree(){root = nullptr;}

        Node *getRoot();
        void create();
        void preorder(Node *p);
        void inorder(Node *p);
        void postorder(Node *p);
        void levelorder();
        int height(Node *p);
        void IPreorder(Node *t);
        void IInorder(Node *t);
        int count(Node *t);

        ~Tree(){

        }
};

Node * Tree::getRoot(){
    return root;
}

void Tree::create(){
    cout<<"Enter the root value: ";
    root = new Node;
    cin>>root->data;
    cout<<endl;
    root->left = root->right = nullptr; 
    Queue Q;
    Q.enqueue(root);  
    Node *p, *t;
    int x;
    while(!Q.isEmpty()){
        p = Q.dequeue();
        cout<<"Enter the value for "<<p->data<<" Left Child: ";
        cin>>x;
        cout<<endl;
        if( x != -1){
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            Q.enqueue(t);
        }
        cout<<"Enter the value for "<<p->data<<" Right Child: ";
        cin>>x;
        cout<<endl;
        if( x != -1){
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            Q.enqueue(t);
        }
        
    }        
}

void Tree::preorder(Node *p){
    if(!p) {
        return;
    }
    
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}

void Tree::inorder(Node *p){
    if(!p) return;

    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}

void Tree::postorder(Node *p){
    if(!p) return;

    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
}

void Tree::levelorder(){
    if(!root){
        cout<<"Tree is empty"<<endl;
        return;
    }
    Queue Q;
    Q.enqueue(root);
    Node *p;
    while(!Q.isEmpty()){
        p = Q.dequeue();
        cout<<p->data<<" ";
        if(p->left) Q.enqueue(p->left);
        if(p->right) Q.enqueue(p->right);
    }
    cout<<endl;
}

int Tree::height(Node *p){
    // int x = 0, y = 0;
    // if(!p) return 0;

    // x = height(p->left);
    // y = height(p->right);

    // if(x > y) return x+1;
    // return y+1;

    if (!p) return -1;  // Base case: the height of an empty tree is 0

    int leftHeight = height(p->left);   // Recursively find the height of the left subtree
    int rightHeight = height(p->right); // Recursively find the height of the right subtree

    return max(leftHeight, rightHeight) + 1;  // The height is the maximum of the two subtrees' heights plus one for the current node
}

void Tree::IPreorder(Node *t){
    Stack S;
    while(!S.isEmpty() || t){
        if(t){
            cout<<t->data<<" ";
            S.push(t);
            t = t->left;
        }else{
            t = S.pop();
            t = t->right;
        }
    }

}

void Tree::IInorder(Node *t){
    Stack S;

    while(!S.isEmpty() || t){
        if(t){
            S.push(t);
            t = t->left;
        }
        else{
            t = S.pop();
            cout<<t->data<<" ";
            t = t->right;
        }
    }
}

int Tree::count(Node *t){
    if(!t) return 0;

    int x = count(t->left);
    int y = count(t->right);
    return x + y + 1;
}

int main(){
    Tree t;
    t.create();
    cout<<"Iterative Preorder: ";
    t.IPreorder(t.getRoot());
    cout<<endl<<"Preorder: ";
    t.preorder(t.getRoot());
    cout<<endl<<"Iterative Inorder: ";
    t.IInorder(t.getRoot());
    cout<<endl<<"Inorder: ";
    t.inorder(t.getRoot());
    cout<<endl<<"Postorder: ";
    t.postorder(t.getRoot());
    cout<<endl<<"Levelorder: ";
    t.levelorder();
    cout<<endl<<"Height: "<<t.height(t.getRoot())<<endl;
    cout<<t.count(t.getRoot());



    return 0;
}