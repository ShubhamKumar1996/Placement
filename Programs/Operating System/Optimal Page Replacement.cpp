#include<bits/stdc++.h>
using namespace std;
int main()
{
	int no_of_frames,no_of_ref_string,page_fault=0,hit=0,f,counter;
	int i,j,k,p,q,m,temp=0,flag,indicator,a;

	cout<<"Enter no of frames: \n";
	cin>>no_of_frames;
	cout<<"\n";

	cout<<"Enter no of Reference strings: \n";
	cin>>no_of_ref_string;
	cout<<"\n";

	int frames[no_of_frames],ref_string[no_of_ref_string],index[no_of_frames];

	cout<<"Enter the Reference strings:\n";
	for(i=0;i<no_of_ref_string;i++)
	cin>>ref_string[i];

	for(int i=0;i<no_of_frames;i++)
	frames[i]=-1;

	for(int i=0;i<no_of_frames;i++)
	index[i]=-1;

	for(i=0;i<no_of_ref_string;i++)
		{
			f=0;
			for(j=0;j<no_of_frames;j++)
			{
				if(frames[j]==ref_string[i])
				{
					hit=hit+1;
					f=1;
					break;
				}
			}
			if(f==0)
			{
			page_fault=page_fault+1;
			frames[temp]=ref_string[i];
			temp++;
			}
			if(temp==no_of_frames)
			break;

		}

		for(k=i+1;k<no_of_ref_string;k++)
		{
			counter=0;
			flag=0;
			indicator=0;
			for(m=0;m<no_of_frames;m++)
			{
				if(frames[m]==ref_string[k])
				{
					hit=hit+1;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				page_fault=page_fault+1;
				for(j=k+1;j<no_of_ref_string;j++)
				{
					for(a=0;a<no_of_frames;a++)
					{
						if(frames[a]==ref_string[j])
						{
							if(index[a]==-1){
							index[a]=0;
							counter=counter+1;
								}
						}

					if(counter==no_of_frames)
						{
						frames[a]=ref_string[k];
						indicator=1;
						break;
						}
					}
					if(indicator==1)
					break;
				}
				if(counter!=no_of_frames)
				{
					for(int p=0;p<no_of_frames;p++)
					{
						if(index[p]!=0)
						{
							frames[p]=ref_string[k];
							break;
						}
					}
				}
				for(int a=0;a<no_of_frames;a++)
			index[a]=-1;
			}
		}

		cout<<"No.of Hit is: "<<hit<<"\n";
	cout<<"No.of Page fault is: "<<page_fault<<"\n";
	return 0;
}
