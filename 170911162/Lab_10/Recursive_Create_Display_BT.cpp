#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left, *right;
};

typedef struct node* NODE;

// void inorder(NODE root){
// 	if(root == NULL){
// 		return;
// 	}
// 	inorder(root->left);
// 	printf("%d, ", root->data);
// 	inorder(root->right);
// }

void preorder(struct node* root){
	if(root == NULL){
		return;
	}
	preorder(root->left);
	preorder(root->right);
	printf("%d, ", root->data);
}

// void postorder(struct node* root){
// 	if(root == NULL){
// 		return;
// 	}
// 	printf("%d, ", root->data);
// 	preorder(root->left);
// 	preorder(root->right);
// }

// int search(NODE root, int x){
// 	if(root == NULL)
// 		return 0;	
// 	if(root -> data == x){
// 		return 1;
// 	}
// 	int l = search(root->left,x);
// 	int r = search(root->right,x);
// 	return l||r;
// }

NODE create_bintree(NODE root, int x){
	root -> data = x;
	int y;
	printf("Enter the value for left child of %d:", root->data);
	scanf("%d", &y);
	if(y!=-1){
		root -> left = (NODE) malloc(sizeof(struct node));
		root -> left = create_bintree(root -> left , y);
	}
	printf("Enter the value for right child of %d:", root->data);
	scanf("%d", &y);
	if(y!=-1){
		root -> right = (NODE) malloc(sizeof(struct node));
		root -> right = create_bintree(root -> right, y);
	}
	return root;
}

int main(){
	NODE a1 = (NODE)malloc(sizeof(struct node));
	a1 = create_bintree(a1,0);
	printf("Preorder:");
	preorder(a1);
	// printf("\nPostorder:");
	// postorder(a1);
	// printf("\nInorder:");
	// inorder(a1);
	// if(search(a1,30) == 1)
	// 	printf("\nFound");
}