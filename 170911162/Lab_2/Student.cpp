#include<iostream>
#include<conio.h>
#include<stdio.h>

class Student
{
	char name[100];
	int rollno;
	char grade;

public:

	void read(Student a[],int n);
	void display(Student a[],int n);
	void arrsort(Student a[],int n);
};

void Student::read(Student a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Enter name, roll number and grade respectively:\n";
		cin>>a[i].name;
		cin>>a[i].rollno;
		cin>>a[i].grade;
	}
}

void Student::arrsort(Student a[],int n)
{
	Student temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j].rollno>a[j+1].rollno)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void Student::display(Student a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Name: "<<a[i].name<<endl;;
		cout<<"Rollno: "<<a[i].rollno<<endl;
		cout<<"Grade: "<<a[i].grade<<endl;
		cout<<endl;
	}
}

void main()
{
	int n;
	Student a[100];
	cout<<"Enter the number of students\n";
	cin>>n;
	cout<<"Enter info for all students\n";
	Student().read(a,n);
	Student().arrsort(a,n);
	cout<<"Sorted students are:\n";
	Student().display(a,n);
	getch();
}