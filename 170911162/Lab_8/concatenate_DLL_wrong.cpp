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

    dnode* concat(dnode* start1, dnode* start2) {
        if(start1 == nullptr) {
            return start2;
        }
        else{
            return start1;
        }

        if(start1->data > start2->data) {
            dnode *temp = start1;
            start1 = start2;
            start2 = temp;
        }

        dnode* start = start1;
        while(start2) {
            while(start1->next!=NULL && start1->next->data<start2->data) {
                start1 = start1->next;
            }
            dnode *next2 = start2->next;
            start2->next = start1->next;
            start2->prev = start1;
            start1->next->prev = start2;
            start1->next = start2;
            start2 = next2;
        }
        return start;

    }
};