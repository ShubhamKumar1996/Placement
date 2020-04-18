#include<bits/stdc++.h>
using namespace std;
int main()
{
	int no_of_frames,no_of_ref_string,page_fault=0,hit=0,f,counter=-1;
	cout<<"Enter no of frames: \n";
	cin>>no_of_frames;
	cout<<"\n";

	cout<<"Enter no of Reference strings: \n";
	cin>>no_of_ref_string;
	cout<<"\n";

	int frames[no_of_frames]={-1},ref_string[no_of_ref_string];

	cout<<"Enter the Reference strings:\n";
	for(int i=0;i<no_of_ref_string;i++)
	cin>>ref_string[i];

	for(int i=0;i<no_of_ref_string;i++)
	{
		f=0;
		for(int j=0;j<no_of_frames;j++){
			if(frames[j]==ref_string[i])
		{
			f=1;
			hit++;
		   break;
		}
		}
		if(f==0)
		{
			page_fault++;
			counter=(counter+1)%no_of_frames;
			frames[counter]=ref_string[i];
		}

	}
	cout<<"No.of page fault is: "<<page_fault<<"\n";
	cout<<"No.of hits is: "<<hit<<"\n";
	return 0;
}
