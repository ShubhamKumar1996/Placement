// Multi Level Queue.

#include<bits/stdc++.h>
using namespace std;

class process
{
    public:
    int p_id, su_p, bt, wt, tat;
};

bool comp(process a, process b)
{
    if(a.su_p<b.su_p)
    {
        return true;
    }
    else if(a.su_p>b.su_p)
    {
        return false;
    }
    else
    {
        if(a.bt>b.bt)
            return true;
        else
            return false;
    }
}

int main()
{
    int n;
    cout<<"Enter Number of processes -- ";
    cin>>n;
    process pro[n];
    float avg_wt = 0, avg_tat = 0;
    for(int i=0;i<n;i++)
    {
        pro[i].p_id = i;
        cout<<"Enter the Burst Time of processes -- ";
        cin>>pro[i].bt;
        cout<<"System/User Process(0/1) ? -- ";
        cin>>pro[i].su_p;
    }
    sort(pro, pro+n, comp);
    pro[0].tat = pro[0].bt;
    pro[0].wt = 0;
    for(int i=1;i<n;i++)
    {
        pro[i].tat = pro[i-1].tat + pro[i].bt;
        pro[i].wt = pro[i-1].tat;
    }
    cout<<"Process\tSystem/User Process\tBurst Time\t Waiting Time\t Turnaround Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<pro[i].p_id<<"\t\t"<<pro[i].su_p<<"\t\t"<<pro[i].bt<<"\t\t"<<pro[i].wt<<"\t\t"<<pro[i].tat<<"\n";
        avg_wt += pro[i].wt;
        avg_tat += pro[i].tat;
    }
    cout<<"Average Waiting Time: "<<avg_wt/n<<"\n";
    cout<<"Average Turnaround Time: "<<avg_tat/n<<"\n";
}
