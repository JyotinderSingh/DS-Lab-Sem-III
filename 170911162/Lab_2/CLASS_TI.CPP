#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class time{
		int hr, min, sec
	public:
		void getdata()
		{
			cout<<"ENTER TIME DATA";
			cout<<"\nEnter Hour: ";
			cin>>hr;
			if(hr<0)
			{
				cout<<"Invalid Input. Enter again: ";
				cin>>hr;
			}
			cout<<"Enter Minute: ";
			cin>>min;
			if(min>=60 || min<0)
			{
				cout<<"Invalid Input. Enter again: ";
				cin>>min;
			}
			cout<<"Enter Second: ";
			cin>>sec;
			if(sec>=60 || sec<0)
			{
				cout<<"Invalid Input. Enter again: ";
				cin>>sec;
			}
		}
		void showdata()
		{
			cout<<"\nHour:- "<<hr;
			cout<<"\nMinute:- "<<min;
			cout<<"\nSecond:- "<<sec;
		}
		time add(time t1, time t2);
		time diff(time t1, time t2);

};
time time :: add(time t1, time t2)
{
	time t3;
	t3.hr = t1.hr+t2.hr + (t1.min + t2.min)/60;
	t3.min = (t1.min+t2.min)%60 + (t1.sec + t2.sec)/60;
	t3.sec = (t1.sec+t2.sec)%60;
	return t3;
}
time time :: diff(time t1, time t2)
{       time t3;
	if(t1.hr>t2.hr)
	{
		t3.hr = t1.hr-t2.hr;
		t3.min = t1.min-t2.min;
		t3.sec = t1.sec-t2.sec;
		if(t3.min<0)
		{
			t3.hr--;
			t3.min*=-1;
		}
		if(t3.sec<0)
		{
			t3.min--;
			t3.sec*=-1;
		}
	}
	if(t2.hr>t1.hr)
	{
		t3.hr = t2.hr-t1.hr;
		t3.min = t2.min-t1.min;
		t3.sec = t2.sec-t1.sec;
		if(t3.min<0)
		{
			t3.hr--;
			t3.min*=-1;
		}
		if(t3.sec<0)
		{
			t3.min--;
			t3.sec*=-1;
		}
	}
	return t3;
}
void main()
{
clrscr();
time t1,t2;
t1.getdata();
t2.getdata();
time addt = add(t1,t2);
cout<<"ADDED TIME\n";
addt.showdata();
time difft = diff(t1,t2);
cout<<"\nTIME DIFFERENCE\n";
difft.showdata();
getch();
}