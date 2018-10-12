//Multiple Stacks
#include <iostream.h>
#include <limits.h>

#define MAX 50

class mStack {
	int a[MAX], bottom[25], top[25], maxsize, n;

public:
	void createStack( int n);
	void push(int n);
	int pop();
	void display();
};

void mStack ::createStack(int n) {
	this->n = n;
	for (int i = 0; i <n ; ++i) {
			top[i] = bottom[i] = ((MAX/n)*i)-1;
		}
}

void mStack ::push(int ele) {
	cout<<endl<<"Available stacks:\n";
	int i;
	for (i = 0; i < n ; ++i) {
		cout<<i+1<<" ";
	}
	cout<<"\nEnter the stack you want to enter the element into: ";
	cin>>i;

	if (top[i-1] == bottom[i]) {
		cout<<"\nSTACK OVERFLOW\n";
		return;
	}

	a[++top[i-1]] = ele;
}

int mStack ::pop() {
	cout<<endl<<"Available stacks:\n";
	int i;
	for (i = 0; i < n ; ++i) {
		cout<<i+1<<" ";
	}
	cout<<"\nEnter the stack you want to pop the element from: ";
	cin>>i;
	if (top[i-1] == bottom[i-1]) {
		cout<<"\nSTACK UNDERFLOW\n";
		return INT_MIN;
	}
	else {
		return a[top[i-1]--];
	}
}

void mStack ::display() {
	for(int i = 0; i < n; ++i) {
		if(top[i] != bottom[i]) {
			cout<<"\nStack "<<i+1<<": ";
			for(int j = bottom[i]+1; j <= top[i]; ++j) {
				cout<<a[j]<<" ";
			}
		}
	}
}

int main()
{

	mStack ms;
	int n, c;
	cout<<"Enter the number of Stacks: ";
	cin>>n;
	int ch;
	ms.createStack(n);
	for (; ;) {
		cout<<"\n1. Push\n2. Pop\n3.Display\n4. EXIT\n";
		cin>>ch;
		switch(ch) {
			case 1:
				int ele;
				cout<<"Enter Element: ";
				cin>> ele;
				ms.push(ele);
				break;
			case 2:
				c = ms.pop();
				if(c==INT_MIN) {
					break;
				}
				else {
					cout<<endl<<c<<" was popped\n";
				}
				break;
			case 3:
				ms.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nINVALID CHOICEE\n";
				break;
		}
	}
}