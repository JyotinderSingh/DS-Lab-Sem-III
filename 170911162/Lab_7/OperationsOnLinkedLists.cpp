#include<iostream>
#include<stdlib.h>
using namespace std;

class node {
	int data;
	node *next;

	public:
	node* insertBefore(int ele, int search_element);
	node* insertAfter(int ele, int search_element);
	void deleteElement(int ele);
	void transverse();
	node* listReverse();
	node* deleteAlt();
	node* sortedInsert(int ele);
}*head=nullptr;

node* node::insertBefore(int ele, int search_element) {
	node* temp = head;

	node* ptr = new node;
	ptr->data = ele;
	ptr->next = nullptr;

	if(temp == nullptr) {
	    cout<<"\nList is empty --> Inserting as the head";
	    head = ptr;

	    transverse();

        return head;
	}

	else {
	    while(temp->next != nullptr) {
	        if(temp->next->data == search_element) {
	            ptr->next = temp->next;
	            temp->next = ptr;

	            transverse();

                return head;
	        }
	        temp = temp->next;
	    }

	    ptr->next = head;
	    head = ptr;

	    transverse();

        return head;
	}
}

node* node::insertAfter(int ele, int search_element) {
    node* temp = head;

    node* ptr = new node;
    ptr->data = ele;
    ptr->next = nullptr;

    if(head == nullptr) {
        cout<<"\nList is empty --> Inserting as the head";
        head = ptr;

        transverse();

        return head;
    } else {
        while(temp->next != nullptr) {
            if(temp->data == search_element) {
                ptr->next = temp->next;
                temp->next = ptr;

                transverse();

                return head;
            }
            temp = temp->next;
        }
        temp->next = ptr;

        transverse();

        return head;
    }

}

void node::deleteElement(int ele) {
    if(head == nullptr) {
        cout<<"\nList is empty - nothing to delete\n";
        return;
    }
    node* temp = head;

    while (temp->next!=nullptr) {
        if(temp->next->data == ele) {
            node* del = temp->next;
            temp->next = temp->next->next;
            free(del);
            transverse();

            return;
        }
        temp = temp->next;
    }
    cout<<"\nElement not found\n";

}

void node::transverse() {
    if(head == nullptr) {
        cout<<"\nList is empty\n";
        return;
    }
    node* temp = head;
    while(temp != nullptr) {
        cout<<" -> "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

node* node::listReverse() {
    node *current = head;
    node *prev = nullptr, *next = nullptr;


    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

node* node::deleteAlt()
{
    if (head == nullptr)
        return head;

     node *prev = head;
     node *node = head->next;

    while (prev != nullptr && node != nullptr)
    {
        prev->next = node->next;

        /* Free memory */
        free(node);

        /* Update prev and node */
        prev = prev->next;
        if (prev != nullptr)
            node = prev->next;
    }
    return head;
}

node* node::sortedInsert(int ele)
{
    node* new_node = new node;
    new_node->data = ele;
    new_node->next = nullptr;
    node* current;
    /* Special case for the head end */
    if (head == nullptr || (head)->data >= new_node->data)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = head;
        while (current->next!=nullptr &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
}

int main() {
	int ch, x, y;
	node ll;
	while(true) {
		cout<<"\n1. Insert before particular element"
		<<"\n2. Insert after particular element"
		<<"\n3. Transverse"
		<<"\n4. Delete an element"
		<<"\n5. Reverse the list"
		<<"\n6. Delete Alternate nodes"
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