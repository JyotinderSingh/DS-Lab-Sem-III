#include<iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

void printGivenLevel (node* root, int level);
int height(node *node);
node* newNode(int data);

void printLevelOrder(node* root) {
    int h = height(root);
    for(int i = 1; i <= h; ++i) {
        printGivenLevel(root, i);
    } 
}

void printGivenLevel(node* root, int level) {
    if(root == nullptr){
        return;
    }
    if (level == 1) {
        cout<<root->data<<" ";
    } 
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(node* root) {
    if(root == nullptr) {
        return 0;
    } else {
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if(lHeight > rHeight) {
            return lHeight+1;
        } else {
            return rHeight+1;
        }
    }
}

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}


int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Level Order traversal of binary tree is \n"); 
    printLevelOrder(root); 
  
    return 0; 
} 