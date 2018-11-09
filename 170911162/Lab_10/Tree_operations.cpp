#include<iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;

public:
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void printPostOrder(node* node) {
    if(node == nullptr) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<<node->data<<" ";
}

void printInOrder(node* node) {
    if(node == nullptr) {
        return;
    }

    printInOrder(node->left);
    cout<<node->data<<" ";
    printInOrder(node->right);
}

void printPreOrder(node* node) {
    if(node == nullptr) {
        return;
    }

    cout<<node->data<<" ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

bool printAncestors(node* root, int target) {
    if (root == nullptr)
        return false;
    if (root->data == target)
        return true;

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        cout << root->data << " ";
        return true;
    }
    return false;
}

int maxDepth(node *node) {
    if (node == nullptr)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if(lDepth > rDepth)
            return (lDepth+1);
        else
            return (rDepth+1);
    }
}

void display(node* root, int level) {
    int i;

    if(root == nullptr) {
        return;
    }

    display(root->right, level+1);
    for(i = 0; i < level; ++i) {
            cout<<"     ";
    }
    cout<<root->data<<endl;
    display(root->left, level + 1);
}

void getParent(node* root, int value)
{
	int found = 0;
	if(root->left == NULL || root->right == NULL){
		return;
	}

	if(root->right)
	{
		if(root->right->data == value){
			printf("Parent is %d\n", root->data);
			found = 1;
		}
	}
	if(root->left)
	{
		if(root->left->data == value){
			printf("Parent is %d\n", root->data);
			found = 1;
		}
	}
	if(found) {
		return;
	}
		getParent(root->left, value);
		getParent(root->right, value);
}

int getLeafCount(node* node) 
{ 
  if(node == NULL)        
    return 0; 
  if(node->left == NULL && node->right==NULL)       
    return 1;             
  else 
    return getLeafCount(node->left)+ 
           getLeafCount(node->right);       
} 

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<getLeafCount(root)<<endl;
    cout<<printAncestors(root, 6)<<endl;
    printPreOrder(root);
    cout<<endl;
    printInOrder(root);
    cout<<endl;
    printPostOrder(root);
    cout<<endl;
    cout<<maxDepth(root);
    cout<<endl;
}