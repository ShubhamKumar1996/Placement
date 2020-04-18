#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process
{
  public:
        int pno,ari,bt,ct,tat,wt,pri;
         process()
         {
             pno=ari=bt=tat=wt=ct=pri=0;
         }
};

bool SORT(process &p1,process &p2)
{
    return (p1.pri<p2.pri);
}
int main()
{
    int n;
    cout<<"\n Enter number of process : ";
    cin>>n;
    process p[n],t[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter arrival time and burst time ans priority of process no "<<i+1;
        cin>>p[i].ari>>p[i].bt>>p[i].pri;
        p[i].pno=i+1;
        t[i]=p[i];
    }
    int time=p[0].ari;
    process temp=p[0];
    int index=0,j;
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].ari<=time)
            {
                if(p[i].pri>temp.pri && p[i].bt!=0)
                {
                    temp=p[i];
                    index=i;
                }
            }
        }
        time++;
        p[index].bt--;
        p[index].ct=time;
        temp.pri=0;
        for(j=0;j<n;j++)
          {
                if(p[j].bt!=0)
                 break;
          }
        if(j==n)
            break;
    }
    int avgwt=0,avgtat=0;
    for(int i=0;i<n;i++)
    {
        p[i].bt=t[i].bt;
        p[i].tat=p[i].ct-p[i].ari;
        p[i].wt=p[i].tat-p[i].bt;
        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }

    cout<<"\n Pno\tct\ttat\twt"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].pno<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }
    cout<<"\n avg waiting time = "<<(double)avgwt/n<<endl;
    cout<<"\n avg tat = "<<(double)avgtat/n<<endl;
    return 0;

}
