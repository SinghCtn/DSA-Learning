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

// class Queue{
//     private: 
//         QNode *f;
//         QNode *r;
//     public:
//         Queue(){
//             f = r = nullptr;
//         }

//         void enqueue(Node *x){
//             QNode *t = new QNode;
//             if(!t) return;
//             t->add = x;
//             t->next = nullptr;

//             if(!r){
//                 f = r = t;
//                 return;
//             }

//             r->next = t;
//             r = t;
//         }

//         Node * dequeue(){
//             if(!f) return nullptr;

//             Node *x = f->add;
//             QNode *p = f;

//             if(f == r){
//                 f = r = nullptr;
//             }else{
//                 f = f->next;
//             }
//             delete p;
//             return x;
//         }

//         bool isEmpty(){
//             return f == nullptr;
//         }

// };

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

        
        QNode * getTop(){
            return top;
        }

        ~Stack() {
        while (top) {
            QNode *temp = top;
            top = top->next;
            delete temp;
        }
    }

};

class BST{
    private:
        Node *root;

    public:
        BST(){ root = nullptr; }
        Node *getroot(){
            return root;
        }
        void insert(int key);
        Node * RInsert(Node *p, int key);
        void inorder(Node *p);
        Node * search(int key);
        Node * RSearch(Node *p, int key);
        Node * Delete(Node *p, int key);
        void createPre(int pre[], int n);
};

void BST::insert(int key){
    Node *t = root;
    Node *r;

    while(t){
        if(t->data == key) return;
        r = t;
        t = t->data > key ? t->left : t->right;
    }

    t = new Node;
    t->data = key;
    t->left = t->right = nullptr;
    if(!root){
        root = t;
        return;
    }
    if(r->data > key){
        r->left = t;
    }else {
        r->right = t;

    }
}

Node * BST::RInsert(Node *p, int key){
    if(!p){
        Node *t = new Node;
        t->data = key;
        t->left = t->right = nullptr;
        return t;
    }

    if(key < p->data){
        p->left = RInsert(p->left, key);
    } else if(key > p->data){
        p->right = RInsert(p->right, key);
    }

    return p;
}

void BST::inorder(Node *p){
    if(!p) return;

    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}

Node * BST::search(int key){
    Node * t = root;

    while(t){
        if(t->data == key){
            return t;
        }

        t = t->data > key ? t->left : t->right;
    }

    return nullptr;
}

Node * BST::RSearch(Node *p, int key){
    if(!p) return nullptr;

    if(p->data == key) return p;

    return RSearch( p->data > key ? p->left : p->right, key );
}

int height (Node *p){
    if(!p) return -1;

    int x = height(p->left);
    int y = height(p->right);

    return (x > y ? x : y) + 1;
}

Node* InSuc(Node *p) {
    while (p && p->left) p = p->left;
    return p;
}

Node* InPre(Node *p) {
    while (p && p->right) p = p->right;
    return p;
}

Node * BST::Delete(Node *p,int key){
    if(!p) return nullptr;

    if(!p->left && !p->right){
        if(p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if(p->data > key){
        p->left = Delete(p->left, key);
    } else if(p->data < key){
        p->right = Delete(p->right, key);
    } else{
        Node * q;
        if(height(p->left) > height(p->right)){
            q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        } else{
            q = InSuc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}   

void BST::createPre(int pre[], int n){
    if(n == 0) return;
    Stack st;
    root = new Node;
    root->data = pre[0];
    root->left = root->right = nullptr;

    Node *p = root, *t;
    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = pre[i];
        t->left = t->right = nullptr;
        if(pre[i] < p->data){
            p->left = t;
            st.push(p);
            p = t;
        } else if(pre[i] > p->data){
            while (!st.isEmpty() && st.getTop()->add->data < pre[i]) {
                p = st.pop();
            }
            p->right = t;
            p = t;
        }
    }
    
}


int main(){
    BST t;
    t.insert(30);
    t.insert(15);
    t.insert(10);
    t.insert(50);
    t.insert(60);
    t.insert(60);
    t.insert(40);
    t.insert(48);
    t.insert(20);
    t.RInsert(t.getroot(), 55);
    t.RInsert(t.getroot(), 67);
    t.RInsert(t.getroot(), 17);
    t.RInsert(t.getroot(), 17);
    t.RInsert(t.getroot(), 25);
    t.Delete(t.getroot(), 10);
    t.Delete(t.getroot(), 30);
    cout<<"Root element: "<<t.getroot()->data<<endl;



    cout<<"Inorder: ";
    t.inorder(t.getroot());
    cout<<endl;

    Node* x = t.search(10);
    if (x) {
        cout << x->data << " is at: " << x << endl;
    } else {
        cout << "Node with key 10 not found." << endl;
    }

    x = t.RSearch(t.getroot(), 10);
    if (x) {
        cout << x->data << " is at: " << x << endl;
    } else {
        cout << "Node with key 10 not found." << endl;
    }

    BST tree;
    int A[] = {30, 20, 10, 15, 25, 40, 50, 45};
    tree.createPre(A, 8);
    cout<<"Inorder: ";
    tree.inorder(tree.getroot());
    cout<<endl;

    return 0;
}