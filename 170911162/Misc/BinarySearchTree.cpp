#include<iostream>
using namespace std;

class node {
    int key;
    node *left, *right;
public:
    node* newNode(int item);
    void inorder(node*);
    node* insert(node* node, int key);
    node* search(node*, int);
    node* deleteNode(node*, int);
    node* minValueNode(node*);
};

node* node::newNode(int item) {
    node* temp = new node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

void node::inorder(node*root) {
    if(root != nullptr) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

node* node::insert(node* node, int key){
    if (node == nullptr) {
        return newNode(key);
    }

    if(key<node->key) {
        node->left = insert(node->left, key);
    }
    
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

node* node::search(node* root, int key) {
    if(root == nullptr || root->key == key){ 
        return root;
    }

    if(root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

node* node::minValueNode(node* root) {
    node* current = root;
    while(current->left != nullptr) {
        current = current->left;
    }
    return current;
}

node* node::deleteNode(node* root, int key) {
    if(root == nullptr) {
        return root;
    }

    if(key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }

    else {
        // node with only one child or no child
        if(root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    node bst;
    node* root = NULL;
    root = bst.insert(root, 50);
    root = bst.insert(root, 30);
    root = bst.insert(root, 20);
    root = bst.insert(root, 40);
    root = bst.insert(root, 70);
    root = bst.insert(root, 60);
    root = bst.insert(root, 80);

    cout<<endl;
    bst.inorder(root);
    cout<<endl;
    cout<< bst.search(root, 30);
    cout<<endl;
    root = bst.deleteNode(root, 20);
    bst.inorder(root);
    return 0;
}