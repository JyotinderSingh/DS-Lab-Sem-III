Node*  BST::searchforparentnode(Node* pRoot, int value)
{
   if(pRoot->pleft == NULL && pRoot->pright == NULL)
    return NULL;

   //Added check 
   if(pRoot->pleft && pRoot->pleft->value == value)
    return pRoot;

   //Added check
   if(pRoot->pright && pRoot->pright->value == value)
    return pRoot;

   //Check also needed here
   if(pRoot->pleft && pRoot->value > value)
    return searchforparentnode(pRoot->pleft,value);

   //Check also needed here
   if(pRoot->pright && pRoot->value < value)
    return searchforparentnode(pRoot->pright,value);

}