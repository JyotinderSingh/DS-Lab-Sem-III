#include <iostream>
#include <stdio.h>
using namespace std;
class node
{
    char info;
    node *next;
public:
    node *insend(node *,char);
    node *rev(node *);
    void chkpalin();
};
node *node::insend(node *start,char a)
{
    node *cur=start;
    node *temp=new node;
    temp->info=a;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    while(cur->next!=NULL)
     cur=cur->next;
    cur->next=temp;
    return start;
}
void node::chkpalin()
{
    node *start=NULL;
    char str[100];int i,f=0;
    cout<<"Enter a string\n";
    gets(str);
    for(i=0;str[i]!='\0';i++)
        start=insend(start,str[i]);
    start=rev(start);
    node *cur=start;
    for(i=0;str[i]!=0;i++)
    {
        if(str[i]!=cur->info)
        {
            f=1;
            break;
        }
        cur=cur->next;
    }
    if(f==1)
        cout<<"Not Palindrome";
    else
        cout<<"Palindrome";
}
node *node::rev(node *start)
{
    node *cur=start,*nextnode;
    start=NULL;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=start;
        start=cur;
        cur=nextnode;
    }
    return start;
}
int main()
{
    node n;
    n.chkpalin();
}
