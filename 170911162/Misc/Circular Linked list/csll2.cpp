#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class cnode
{
    int info;
    cnode *next;
public:
    void displayf(cnode *);
     cnode *firstinsbeg(cnode *);
    cnode *firstinsend(cnode *);
    cnode *firstinsafter(cnode *);
    cnode *firstdelend(cnode *);
};
cnode *cnode::firstinsbeg(cnode *first)
{
    cnode *temp=new cnode;
    cnode *cur=first;
    cout<<"Enter the element: ";
    cin>>temp->info;
    if(first==NULL)
    {
        first=temp;
        temp->next=first;
        return first;
    }
    if(first->next==first)
    {
        temp->next=first;
        first->next=temp;
        first=temp;
    }
    else
    {
        while(cur->next!=first)
            cur=cur->next;
        temp->next=first;
        first=temp;
        cur->next=first;
        return first;
    }
}
cnode *cnode::firstinsend(cnode *first)
{
    cnode *temp=new cnode;
    cnode *cur=first;
    cout<<"Enter the element: ";
    cin>>temp->info;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        temp->next=first;
        return first;
    }
    while(cur->next!=first)
        cur=cur->next;
    temp->next=first;
    cur->next=temp;
    return first;

}
cnode *cnode::firstinsafter(cnode *first)
{
     int data;
    cnode *temp=new cnode;
    cnode *cur=first;
    cout<<"Enter the element after which you want to insert: ";
    cin>>data;
    cout<<"Enter the element: ";
    cin>>temp->info;
    temp->next=NULL;
    if(first==NULL)
        return first;
    while(cur->next!=first&&(cur->next)->info!=data)
       cur=cur->next;
    if(cur->next!=first)
    {
        cur=cur->next;
        temp->next=cur->next;
        cur->next=temp;
        return first;
    }
    else
    {
        cout<<"Data not present";
        return first;
    }
}
void cnode::displayf(cnode *first)
{
    cnode *cur=first;
    //cout<<first->info<<"\t";
    while(cur->next!=first)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
       cout<<cur->info;
}
cnode *cnode::firstdelend(cnode *first)
{
    cnode *cur=first;
    if(first==NULL)
    {
        cout<<"Deletion not possible";
         return first;
    }
    while((cur->next)->next!=first)
        cur=cur->next;
    delete cur->next;
    cur->next=first;
    return first;
}
int main()
{
    cnode c,*first=NULL,*last=NULL;
    cnode *header=new cnode;
    cnode *h=header;
    int ch;
    for(;;)
    {
        cout<<"\n1.Insert at beg\n2.Display\n3.Exit\n4.Indert end\n5.Insert after\n6.Delete: ";
        cin>>ch;
        switch(ch)
        {
            case 1:first=c.firstinsbeg(first);
                    break;
            case 2:c.displayf(first);
                   break;
            case 3:exit(0);
                   break;
            case 4:first=c.firstinsend(first);
                   break;
            case 5:first=c.firstinsafter(first);
                   break;
            case 6:first=c.firstdelend(first);
                   break;

        }
    }
    return 0;
}
