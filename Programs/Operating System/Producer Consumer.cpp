//---------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int mutex=1,full=0,empty=3,x=0;

int main()
{
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	cout<<"1.Producer\n 2.Consumer\n 3.Exit\n";
	while(1)
	{
		cout<<"Enter your choice\n";
		cin>>n;
		switch(n)
		{
			case 1:if(mutex==1 && empty!=0)
				producer();
				else
				cout<<"Buffer is full\n";
				break;

			case 2:if(mutex==1 && full!=0)
				consumer();
				else
				cout<<"Buffer is empty\n";
				break;

			case 3:exit(0);
		}
	}
	return 0;
}
	int wait(int s)
	{
		return (--s);
	}
	int signal(int s)
	{
		return (++s);
	}

	void producer()
	{
		mutex=wait(mutex);
		empty=wait(empty);
		full=signal(full);
		x=x+1;
		cout<<"Produce Item"<<x<<endl;
		mutex=signal(mutex);
	}

	void consumer()
	{
		mutex=wait(mutex);
		empty=signal(empty);
		full=wait(full);
		cout<<"Consumed Item "<<x<<endl;
		x--;
		mutex=signal(mutex);
	}
