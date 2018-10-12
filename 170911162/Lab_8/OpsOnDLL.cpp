//Incomplete - convert SLL based code to DLL

#include<stdlib.h>
#include<iostream>
#include<process.h>
using namespace std;

class dnode {
	int data;
	dnode *next;
    dnode *prev;

	public:
	dnode* insertBefore(int ele, int search_element);
	dnode* insertAfter(int ele, int search_element);
	void deleteElement(int ele);
	void transverse();
	dnode* listReverse();
	dnode* deleteAlt();
	dnode* sortedInsert(int ele);
}*head=NULL;

dnode* dnode::insertBefore(int ele, int search_element) {
	dnode* temp = head;

	dnode* ptr = new dnode;
	ptr->data = ele;
	ptr->next = NULL;
    ptr->prev = NULL;

	if(temp == NULL) {
	    cout<<"\nList is empty --> Inserting as the head";
	    head = ptr;

	    transverse();

        return head;
	}

	else {
	    while(temp->next != NULL) {
	        if(temp->next->data == search_element) {
	            ptr->next = temp->next;
	            temp->next = ptr;
                ptr->prev = temp;
                ptr->next->prev = ptr;

	            transverse();

                return head;
	        }
	        temp = temp->next;
	    }

	    ptr->next = head;
        head->prev = ptr;
	    head = ptr;

	    transverse();

        return head;
	}
}

dnode* dnode::insertAfter(int ele, int search_element) {
    dnode* temp = head;

    dnode* ptr = new dnode;
    ptr->data = ele;
    ptr->next = NULL;
    ptr->prev = NULL;

    if(head == NULL) {
        cout<<"\nList is empty --> Inserting as the head";
        head = ptr;

        transverse();

        return head;
    } else {
        while(temp->next != NULL) {
            if(temp->data == search_element) {
                ptr->next = temp->next;
                temp->next = ptr;
                ptr->prev = temp;
                ptr->next->prev = ptr;

                transverse();

                return head;
            }
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;

        transverse();

        return head;
    }

}

void dnode::deleteElement(int ele) {
    if(head == NULL) {
        cout<<"\nList is empty - nothing to delete\n";
        return;
    }
    dnode* temp = head->next;
    if(head->data == ele) {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        return;
    }
    while (temp->next != NULL) {
        if(temp->data == ele) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            transverse();

            return;
        }
        temp = temp->next;
    }
    if(temp->data == ele) {
        temp->prev->next = NULL;
        delete temp;
        return;
    }
    cout<<"\nElement not found\n";

}

void dnode::transverse() {
    if(head == NULL) {
        cout<<"\nList is empty\n";
        return;
    }
    dnode* temp = head;
    while(temp != NULL) {
        cout<<" -> "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

dnode* dnode::listReverse() {
    dnode *temp = NULL;   
    dnode *current = head; 
     /* swap next and prev for all nodes of  
       doubly linked list */
     while (current != NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     /* Before changing head, check for the cases like empty  
        list and list with only one node */
     if(temp != NULL ) 
        head = temp->prev; 
    return head;
}

dnode* dnode::deleteAlt()
{
    if (head == NULL){
        cout<<"List is empty\n";
        return head;
    }

    dnode *previous, *current, *next;    
    previous = head;
    current = head->next;
    while (previous !=NULL && current != NULL) 
    {
        previous->next = current->next; 
        next = current->next;
        delete current;
        if(next) 
        {
            next->prev = previous;
            current = next->next;
        }
        else 
        current = NULL;
        previous = next;
    }
    return head;
}

dnode* dnode::sortedInsert(int ele)
{
    dnode* new_dnode = new dnode;
    new_dnode->data = ele;
    new_dnode->next = NULL;
    dnode* current;
    /* Special case for the head end */
    if (head == NULL || (head)->data >= new_dnode->data)
    {
        new_dnode->next = head;
        head = new_dnode;
        head->prev = NULL;
        head->next->prev = head;
        return head;
    }
    else
    {
        /* Locate the dnode before the point of insertion */
        current = head;
        while (current->next!=NULL &&
               current->next->data < new_dnode->data)
        {
            current = current->next;
        }
        new_dnode->next = current->next;
        current->next = new_dnode;
        new_dnode->next->prev = new_dnode;
        new_dnode->prev = current;
    }
    return head;
}

int main() {
	int ch, x, y;
	dnode ll;
	while(true) {
		cout<<"\n1. Insert before particular element"
		<<"\n2. Insert after particular element"
		<<"\n3. Transverse"
		<<"\n4. Delete an element"
		<<"\n5. Reverse the list"
		<<"\n6. Delete Alternate dnodes"
		<<"\n7. Insert into sorted list"
		<<"\n8. EXIT\n\n";
		cin>>ch;

		switch(ch) {
			case 1:
			    cout<<"\nEnter value to be inserted: ";
			    cin>>x;
                cout<<"Enter value before which element needs to be inserted: ";
                cin>>y;
                ll.insertBefore(x,y);
                break;
			case 2:
                cout<<"\nEnter value to be inserted: ";
                cin>>x;
                cout<<"Enter value after which element needs to be inserted: ";
                cin>>y;
                ll.insertAfter(x,y);
                break;
			case 3:
                ll.transverse();
                break;
            case 4:
                cout<<"\nEnter element to be deleted: ";
                cin>>x;
                ll.deleteElement(x);
                break;
            case 5:
                ll.listReverse();
                ll.transverse();
                break;
            case 6:
                ll.deleteAlt();
                ll.transverse();
                break;
		    case 7:
		        cout<<"\nEnter the value to be inserted: ";
		        cin>>x;
		        ll.sortedInsert(x);
		        ll.transverse();
                break;
		    case 8:
		        exit(0);
            default:
                cout<<"\nEnter a valid choice\n";
		}
	}
}