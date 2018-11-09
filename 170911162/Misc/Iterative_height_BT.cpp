
/* Program to find height of the tree by Iterative Method */
#include <iostream> 
#include <queue> 
using namespace std; 
  
// A Binary Tree Node 
struct node 
{ 
    struct node *left; 
    int data; 
    struct node *right; 
}; 
  
// Iterative method to find height of Bianry Tree 
int treeHeight(node *root) 
{ 
    if(root == nullptr) {
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int height = 0;

    while(1) {
        int node_count = q.size();
        if(node_count == 0) {
            return height;
        }

        height++;

        while(node_count > 0) {
            node* node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            node_count--;
        }
    }
     
} 
  
// Utility function to create a new tree node 
node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Height of tree is " << treeHeight(root); 
    return 0; 
} 