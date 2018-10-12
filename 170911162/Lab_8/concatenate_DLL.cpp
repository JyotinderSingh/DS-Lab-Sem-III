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
        
    }
};