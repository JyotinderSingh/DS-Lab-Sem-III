//Operations on Circular Doubly Linked List

#include<stdlib.h>
#include<iostream>
// #include<process.h>
using namespace std;

class dnode {
	int data;
	dnode *next;
    dnode *prev;

	public:
    void insertEnd(int value);
    void insertBegin(int value);
	void insertAfter(int ele, int search_element);
	void deleteElement(int ele);
	void transverse();
}*head=NULL;

void dnode::insertEnd(int value) 
{ 
    // If the list is empty, create a single node 
    // circular and doubly list 
    if (head == NULL) 
    { 
        dnode* new_node = new dnode; 
        new_node->data = value; 
        new_node->next = new_node->prev = new_node; 
        head = new_node; 
        return; 
    } 
  
    // If list is not empty 
  
    /* Find last node */
    dnode *last = (head)->prev; 
  
    // Create dnode dynamically 
    dnode* new_node = new dnode; 
    new_node->data = value; 
  
    // Start is going to be next of new_node 
    new_node->next = head; 
  
    // Make new node previous of start 
    (head)->prev = new_node; 
  
    // Make last preivous of new node 
    new_node->prev = last; 
  
    // Make new node next of old last 
    last->next = new_node; 
} 

void dnode::insertBegin(int value) 
{ 
    // Pointer points to last Node 
    dnode *last = (head)->prev; 
  
    dnode* new_node = new dnode; 
    new_node->data = value;   // Inserting the data 
  
    // setting up previous and next of new node 
    new_node->next = head; 
    new_node->prev = last; 
  
    // Update next and previous pointers of start 
    // and last. 
    last->next = (head)->prev = new_node; 
  
    // Update start pointer 
    head = new_node; 
} 

void dnode::insertAfter(int value1, int value2) 
{ 
    dnode* new_node = new dnode; 
    new_node->data = value1; // Inserting the data 
  
    // Find node having value2 and next node of it 
    dnode *temp = head; 
    while (temp->data != value2) 
        temp = temp->next; 
    dnode *next = temp->next; 
  
    // insert new_node between temp and next. 
    temp->next = new_node; 
    new_node->prev = temp; 
    new_node->next = next; 
    next->prev = new_node; 
} 

void dnode::deleteElement(int key) {
    // If list is empty 
    if (head == NULL) 
        return; 
  
    // Find the required node 
    // Declare two pointers and initialize them 
    dnode *curr = head, *prev_1 = NULL; 
    while (curr -> data != key) 
    { 
        // If node is not present in the list 
        if (curr->next == head) 
        { 
            printf("\nList doesn't have node with value = %d", key); 
            return; 
        } 
  
        prev_1 = curr; 
        curr = curr -> next; 
    } 
  
    // Check if node is the only node in list 
    if (curr -> next == head && prev_1 == NULL) 
    { 
        (head) = NULL; 
        free(curr); 
        return; 
    } 
  
    // If list has more than one node, 
    // check if it is the first node 
    if (curr == head) 
    { 
        // Move prev_1 to last node 
        prev_1 = (head) -> prev; 
  
        // Move start ahead 
        head = (head) -> next; 
  
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = head; 
        (head) -> prev = prev_1; 
        free(curr); 
    } 
  
    // check if it is the last node 
    else if (curr->next == head) 
    { 
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = head; 
        (head) -> prev = prev_1; 
        free(curr); 
    } 
    else
    { 
        // create new pointer, points to next of curr node 
        dnode *temp = curr -> next; 
  
        // Adjust the pointers of prev_1 and temp node 
        prev_1 -> next = temp; 
        temp -> prev = prev_1; 
        free(curr); 
    } 

}

void dnode::transverse() {
    if(head == NULL) {
        cout<<"\nList is empty\n";
        return;
    }
    dnode* temp = head;
    while(temp->next != head) {
        cout<<" -> "<<temp->data;
        temp = temp->next;
    }
    cout<<" -> "<<temp->data;
    cout<<endl;
}

int main() {
	int ch, x, y;
	dnode ll;
	while(true) {
		cout<<"\n1. Insert element in beginning"
        <<"\n2. Insert element in the end"
        <<"\n3. Insert element after particular element"
		<<"\n4. Transverse"
		<<"\n5. Delete an element"
		<<"\n6. EXIT\n\n";
		cin>>ch;

		switch(ch) {
			case 1:
			    cout<<"\nEnter value to be inserted: ";
			    cin>>x;
                ll.insertBegin(x);
                break;
			case 2:
                cout<<"\nEnter value to be inserted: ";
                cin>>x;
                ll.insertEnd(x);
                break;
            case 3:
                cout<<"Enter value to be inserted: ";
                cin>>x;
                cout<<"Enter element after which value is to be inserted: ";
                cin>>y;
                ll.insertAfter(x,y);
			case 4:
                ll.transverse();
                break;
            case 5:
                cout<<"\nEnter element to be deleted: ";
                cin>>x;
                ll.deleteElement(x);
                break;
		    case 6:
		        exit(0);
            default:
                cout<<"\nEnter a valid choice\n";
		}
	}
}