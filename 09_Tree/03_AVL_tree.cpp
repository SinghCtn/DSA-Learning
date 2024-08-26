#include<iostream>
using namespace std;

struct Node{
    Node *lchild;
    int data ;
    int height;
    Node *rchild;
};

class AVL{
    private:
        Node *root;

    public:
        AVL(){
            root = nullptr;
        }

        Node * RInsert(Node *p, int key);
        Node *LLRotation(Node *p);
        Node *LRRotation(Node *p);
        Node *RRRotation(Node *p);
        Node *RLRotation(Node *p);
        void creatingAVL(int A[], int n);
        Node * getroot(){
            return root;
        }
};

int NodeHeight(Node *p){
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return (hl > hr ? hl + 1 : hr + 1);
}

int BalanceFactor(Node *p){
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

Node * AVL::LLRotation(Node *p){
    Node *q = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    if(root == p){
        root = q;
    }
    return q;
}

Node * AVL::LRRotation(Node *p){
    Node *q = p->lchild->rchild;

    p->lchild->rchild = q->lchild;
    q->lchild = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);
    q->lchild->height = NodeHeight(p->lchild);

    if(root == p){
        root = q;
    }
    return q;
}

Node * AVL::RRRotation(Node *p){
    Node *q = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    if(root == p){
        root = q;
    }
    return q;
}

Node * AVL::RLRotation(Node *p){
    Node *q = p->rchild->lchild;

    p->rchild->lchild = q->rchild;
    q->rchild = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);
    q->rchild->height = NodeHeight(p->rchild);

    if(root == p){
        root = q;
    }
    return q;
}

Node * AVL::RInsert(Node *p, int key){
    if(!p){
        Node *t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        t->height = 1;
        if (!root){
            root = t;
        }
        return t;
    }

    if(p->data > key){
        p->lchild = RInsert(p->lchild, key);
    } else if(p->data < key){
        p->rchild = RInsert(p->rchild, key);
    }
    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1){
        return LLRotation(p);
    } else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }

    return p;
}

void AVL::creatingAVL(int A[], int n){
    root = new Node;
    root->data = A[0];
    root->lchild = root->rchild = nullptr;
    Node *p = root;
    Node *temp;
    for(int i = 1; i < n; i++){
        
    }
}



int main(){
    AVL tree;
    tree.RInsert(tree.getroot(), 10);
    tree.RInsert(tree.getroot(), 20);
    tree.RInsert(tree.getroot(), 30);

    cout<<tree.getroot()->data<<endl;
    cout<<tree.getroot()->lchild->data<<endl;
    cout<<tree.getroot()->rchild->data<<endl;


    return 0;
}
