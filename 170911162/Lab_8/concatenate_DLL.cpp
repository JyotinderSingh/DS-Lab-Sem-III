#include<iostream>
using namespace std;

class dnode {
    int data;
    dnode *next;
    dnode *prev;

    public:

    dnode* insert_end(dnode* start, int ele) {
        dnode *cur = start;
        dnode* temp = new dnode;
        temp->data = ele;
        temp->next = nullptr;
        temp->prev = nullptr;
        if(cur == nullptr) {
            start = temp;
            return start;
        }
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
        return start;
    }

    dnode* concat (dnode* start1, dnode* start2) {
        dnode* curr = start1;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = start2;
        return start1;      
    }

    void transverse (dnode* start) {
        dnode* temp = start;
        cout<<endl;
        while(temp != NULL) {
            cout<<" -> "<<temp->data;
            temp = temp->next;
        }
    }
};

int main(){
    dnode* start1 = NULL, *start2 = NULL, ll;
    start1 = ll.insert_end(start1, 12);
    start1 = ll.insert_end(start1, 45);
    start1 = ll.insert_end(start1, 54);
    ll.transverse(start1);
    start2 = ll.insert_end(start2, 657);
    start2 = ll.insert_end(start2, 543);
    start2 = ll.insert_end(start2, 432);
    ll.transverse(start2);
    start1 = ll.concat(start1, start2);
    ll.transverse(start1);
}