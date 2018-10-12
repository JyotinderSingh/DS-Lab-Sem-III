#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX 50

class cQueue {
    int rear, Front, arr[MAX];
public:
    cQueue () {
        Front = rear = -1;
    }
    bool isFull () {
        if (Front == 0 && rear == MAX-1) {
            return true;
        }
        if (Front == rear+1) {
            return true;
        }
        return false;
    }
    bool isEmpty () {
        if (Front == -1)
            return true;
        else
            return false;
    }

    void enQueue (int ele);
    int deQueue ();
    void display ();
};

void cQueue :: enQueue (int ele) {
    if (isFull()) {
        cout<<"\nOverflow\n";
        return;
    }
    else {
        if (Front==-1)  Front=0;
        rear = (rear+1)%MAX;
        arr[rear] = ele;
    }
}

int cQueue :: deQueue () {
    int ele;
    if (isEmpty()) {
        return -9999;
    }
    else {
        ele = arr[Front];
        if (Front == rear) {
            Front = rear = -1;
        }
        else {
            Front = (Front+1)%MAX;
        }
        return ele;
    }
}

void cQueue :: display () {
    int i;
    if (isEmpty()) {
        cout<<"\nStack is empty\n";
    }
    else {
        cout<<"Front -> "<<Front;
        cout<<endl<<"Items ->\n";
        for (i = Front; i != rear; i = (i+1)%MAX) {
            cout<<"\t"<<arr[i]<<endl;
        }
        cout<<"\t"<<arr[i];
        cout<<"\nRear  ->"<<rear<<endl;
    }
}

int main() {
    int k, x;
    cQueue cq;
    while (true) {
        cout<<"\n\nChoose an option:\n"
            <<"1. enQueue\n"
            <<"2. deQueue\n"
            <<"3. Display\n"
            <<"4. Exit\n";
        cin>>k;

        switch (k) {
        case 1:
            cout<<"\nEnter the element: ";
            cin>>x;
            cq.enQueue(x);
            break;
        case 2:
            x = cq.deQueue();
            if (x==-9999) {
                cout<<"\nUnderflow\n";
                break;
            }
            cout<<endl<<x<<" was removed\n";
            break;
        case 3:
            cq.display();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nEnter a valid choice (1/2/3/4)\n";
            break;
        }
    }
}
