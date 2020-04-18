//--------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int mutex=1,db=1,rc=0;
int main()
{
	int n;
	void reader();
	void writer();
	int wait(int);
	int signal(int);
	cout<<"1.Reader\n 2.Writer\n 3.Exit\n";
	while(1)
	{
		cout<<"Enter your choice\n";
		cin>>n;
		switch(n)
		{
			case 1:if(mutex==1 && db==1)
			        reader();
			        else
			        cout<<"Cant Read\n";

			break;

			case 2:rc=rc-1;
				if(rc==0){
				db=signal(db);
				if(mutex==1 && db==1)
					writer();
				}
				   else
					cout<<"Cant Write\n";

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

	void reader()
	{
	mutex=wait(mutex);
	rc=rc+1;
	if(rc==1)
	db=wait(db);
	cout<<"Reading Performed\n";
	mutex=signal(mutex);
	//cout<<"Reading Performed\n";
	//mutex=wait(mutex);
/*	rc=rc-1;
	if(rc==0)
	db=signal(db);
	//mutex=signal(mutex);*/

	}

	void writer()
	{
		db=wait(db);
		cout<<"Writing performed\n";
		db=signal(db);
	}
