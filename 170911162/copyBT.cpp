node* copyBT(node* root) {
    if(!root){
        return nullptr;
    }
    node *temp = new node;
    temp->data = root->data;
    temp->left = copyBT(root->left);
    temp->right = copyBT(root->right);
    return temp;

}