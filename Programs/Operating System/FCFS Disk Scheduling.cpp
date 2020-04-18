//FCFS Disk Scheduling.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int lower, upper, n, head;
    cout<<"Enter Lower & upper Limit & head\n";
    cin>>lower>>upper>>head;
    cout<<"Enter number of element\n";
    cin>>n;
    float seek = 0;
    vector<int>v;
    cout<<"Tracks\t Difference btw tracks\t\n";
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        v.push_back(x);
        seek += abs(head-x);
        head = x;
    }
    cout<<"Sequence is:\n";
    for(int i=0;i<n;i++)
        cout<<v[i]<<"\n";

    cout<<"Total Seek time:"<<seek<<"\n";


}
