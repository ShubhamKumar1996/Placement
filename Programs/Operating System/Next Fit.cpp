#include<bits/stdc++.h>
using namespace std;
int main()
{
	int no_of_partitions,no_of_process,i,f,j,index=-1;
	cout<<"Enter the number of partitions: ";
	cin>>no_of_partitions;

	cout<<"Enter the number of processes: ";
	cin>>no_of_process;

	int partition[no_of_partitions],process[no_of_process];
	for(i=0;i<no_of_partitions;i++)
	{
		cout<<"Enter the size of partition "<<i<<": ";
		cin>>partition[i];
	}

	for(i=0;i<no_of_process;i++)
	{
		cout<<"Enter the size of process "<<i<<": ";
		cin>>process[i];
	}

	for(i=0;i<no_of_process;i++)
	{
		f=0;
		for(j=index+1;j<no_of_partitions;j++)
	  {
	  	if(partition[j]>=process[i])
	  	{
	  		f=1;
	  		partition[j]=partition[j]-process[i];
	  		index=j;
	  		break;
		  }
	}
	if(f==0)
	process[i]=-1;

	}
	for(int i=0;i<no_of_partitions;i++)
	cout<<partition[i]<<" ";

		for(int i=0;i<no_of_process;i++)
	{
		if(process[i]==-1)
		cout<<"InSufficient memoryspace for the process size index "<<i<<"\n";
	}
	return 0;
}
