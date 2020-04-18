
#include<bits/stdc++.h>
using namespace std;
struct process{
    int arr;
    int id;
    int br;
    int pr;
 };
struct cmp{
bool operator()(process const&a,process const&b)
{
    return b.pr>a.pr;
}
};
bool compare( process a, process b)
{
    if(b.arr>a.arr)
    {
        int temp=b.arr;
        b.arr=a.arr;
        a.arr=temp;
    }
    return a.arr>b.arr;
}
int main()
{
    int n;
    cout<<"Enter Number of process";
    cin>>n;
    process AB[n];
    for(int i=0;i<n;i++)
    {cin>>AB[i].arr>>AB[i].br>>AB[i].pr;
    AB[i].id=i;
    }
    sort(AB,AB+n,compare);
    int comp=AB[0].arr;
    priority_queue<process,vector<process >,cmp>p;
    p.push(AB[0]);
    cout<<"Process Id "<<"Arrival Time "<<" Brust Time "<<"Completion Time "<<"Turn Around Time "<<"Waiting Time "<<"\n";
    int j=1;
    while(!p.empty() || j<n)
    {
         process temp=p.top();
         p.pop();
         temp.br=temp.br-1;
         comp++;
         if(temp.br==0)
         {
        int pid=temp.id;
        int arrival=temp.arr;
        int brust=AB[pid].br;
        //comp=comp+brust;
        int turn=comp-arrival;
        int waiting=turn-brust;
        cout<<pid<<"\t\t"<<arrival<<"\t\t"<<brust<<"\t\t"<<comp<<"\t\t"<<turn<<"\t\t"<<waiting<<"\n";
         }
         else
         p.push(temp);
        while(j<n && comp>=AB[j].arr)
        {
          p.push(AB[j]);
          j++;
        }
        if(j<n-1 && p.empty())
        {p.push(AB[j]);
         j++;
        }
    }
}
