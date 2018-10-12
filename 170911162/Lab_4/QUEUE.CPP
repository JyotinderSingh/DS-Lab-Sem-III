#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<limits.h>
#include<process.h>

#define MAX 20

class Queue {
	int data[MAX];
	int front, rear;
	public:
	Queue() {
		front = rear = -1;
	}
	void enqueue(int ele);
	int dequeue();
	void display();
};

void Queue :: enqueue (int ele) {
	if(rear == MAX-1) {
		cout<<"\nOVERFLOW\n";
		return;
	}
	data[++rear] = ele;
}

int Queue :: dequeue() {
	if(front == rear) {
		cout<<"\nUNDERFLOW\n";
		return -999;
	}
	return data[++front];

}

void Queue :: display() {
	cout<<endl;
	for(int i = front+1; i<=rear; ++i) {
		cout<<data[i]<" ";
	}
	cout<<endl;
}

void main() {
	Queue q;
	do
	{
	clrscr();
	int x, k;
	cout<<"\nChoose an option:\n"
	<<"1. Enqueue\n"
	<<"2. Dequeue\n"
	<<"3. Display\n"
	<<"4. EXIT\n\t-> ";
	cin>>k;
	switch(k) {
		case 1:
			cout<<"\nEnter element: ";
			cin>>x;
			q.enqueue(x);
			break;
		case 2:
			int c = q.dequeue();
			if(c == -999) {
				break;
			}
			cout<<endl<<c<<" was deleted.";
			getch();
			break;
		case 3:
			q.display();
			getch();
			break;
		case 4:
			exit(0);
		default:
			cout<<"\nEnter a valid option.\n";
			getch();
	}
	}while(1);
}