#include <iostream>
#include <cstring>
using namespace std;

class node {
    int info;
    node *lchild, *rchild;
public:
    node* createBT(node* root);
    void display(node* root, int level);
};

node* node::createBT(node *root) {
    node *prev, *cur;
    node *temp = new node;
    char d[10];
    int i;
    cout<<"\nEnter element: ";
    cin>>temp->info;
    temp->lchild = nullptr;
    temp->rchild = nullptr;

    if (root == nullptr) {
        return temp;
    }

    cout<<"\nDirection: ";
    cin>>d;
    prev = nullptr;
    cur = root;

    for(i = 0; i < strlen(d); ++i) {
        if(cur == nullptr) {
            break;
        }
        prev = cur;
        if (d[i] == 'L') {
            cur = cur->lchild;
        } else {
            cur = cur->rchild;
        }
    }

    if(cur != nullptr || i != strlen(d)) {
        cout<<"\nImpossible!";
        delete  temp;
        return root;
    }

    if (d[i-1] == 'L') {
        prev->lchild = temp;
    } else {
        prev->rchild = temp;
    }

    return root;
}

void node::display(node *root, int level) {
    int i;

    if (root == nullptr) {
        return;
    }

    display(root->rchild, level + 1);

    for(i = 0; i < level; ++i) {
        cout<<"     ";
    }
    cout<<root->info<<endl;
    display(root->lchild, level + 1);
}

int main() {

    node *root = nullptr, BT;
    root = BT.createBT(root);
    root = BT.createBT(root);
    root = BT.createBT(root);
    root = BT.createBT(root);
    root = BT.createBT(root);
    BT.display(root, 1);

    return 0;
}