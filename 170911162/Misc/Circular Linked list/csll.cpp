#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class cnode
{
    public:
    int info;
    cnode *next;
public:
    void displayf(cnode *);
    void displayl(cnode *);
    void displayh(cnode *);
    cnode *firstinsbeg(cnode *);
    cnode *firstinsend(cnode *);
    cnode *firstinsafter(cnode *);
    cnode *firstdelbeg(cnode *);
    cnode *firstdelend(cnode *);
    cnode *firstdelelem(cnode *);
    cnode *lastinsend(cnode *);
    cnode *headerinsbeg(cnode *);
    cnode *headerdelend(cnode *);

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
cnode *cnode::firstdelbeg(cnode *first)
{
    cnode *cur=first,*t=first;
    if(first==NULL)
    {
         cout<<"Deletion not possible";
         return first;
    }
    while(cur->next!=first)
        cur=cur->next;
    cur->next=NULL;
    cur->next=t->next;
    first=t->next;
    delete t;
    return first;
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
cnode *cnode::firstdelelem(cnode *first)
{
    int data;
    cnode *cur=first,*prev=first;
    cout<<"Enter the element you want to delete: ";
    cin>>data;
    if(first==NULL)
        return first;
    if(first->info==data)
    {
        delete first;
        return NULL;
    }
    while(cur->next!=first&&cur->info!=data)
        {
            prev=cur;
            cur=cur->next;
        }
    if(cur->next!=first)
    {
        prev->next=cur->next;
        delete cur;
        return first;
    }
    else if(cur->info!=data)
    {
        cout<<"Data not present";
        return first;
    }
    else if(cur->next==first)
    {
        delete cur;
        prev->next=first;
        return first;
    }

}
cnode *cnode::lastinsend(cnode *last)
{
    cnode *temp=new cnode;
    cnode *cur;
    cout<<"Enter the element: ";
    cin>>temp->info;
    if(last==NULL)
    {
        last=temp;
        last->next=last;
        return last;
    }
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}
cnode *cnode::headerinsbeg(cnode *header)
{
    cnode *temp=new cnode;
    cnode *cur=header->next;
    cout<<"Enter the element: ";
    cin>>temp->info;
    if(header->next==NULL)
    {
        header->next=temp;
        temp->next=header;
        return header;
    }
     temp->next=cur;
    header->next=temp;
    return header;
}
cnode *cnode::headerdelend(cnode *header)
{
    cnode *cur=header->next;
    while((cur->next)->next!=header)
    {
        cur=cur->next;
    }
    delete cur->next;
    cur->next=header;
    return header;
}
void cnode::displayh(cnode *header)
{
    cnode *cur=header->next;
    while(cur->next!=header)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
    cout<<cur->info;
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
void cnode::displayl(cnode *last)
{
    cnode *cur=last->next;
    while(cur!=last)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
    cout<<cur->info;
}
int main()
{
    cnode c,*first=NULL,*last=NULL;
    cnode *header=new cnode;
    header->next=NULL;
    int ch;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert first at beginning\n2.Display first\n3.Exit\n4.Insert first at end\n5.Insert first After an element\n6.Delete first at beginning: ";
       cout<<"\n7.Delete first from end\n8.Delete first particular\n9.Insert last at end\n10.Display last\n11.Insert header from beginning\n12.Display header\n13.Delete at end header given: ";
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
            case 6:first=c.firstdelbeg(first);
                   break;
            case 7:first=c.firstdelend(first);
                   break;
            case 8:first=c.firstdelelem(first);
                   break;
            case 9:last=c.lastinsend(last);
                   break;
            case 10:c.displayl(last);
                   break;
            case 11:header=c.headerinsbeg(header);
                    break;
            case 12:c.displayh(header);
                    break;
            case 13:header=c.headerdelend(header);
                    break;
        }
    }
    return 0;
}
