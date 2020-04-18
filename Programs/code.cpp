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

//sorting the processes first according to arrival time then according to priority
bool SORT(process &p1,process &p2)
{
    if(p1.ari==p2.ari)
       return (p1.pri>=p2.pri);//higher no higher priority

    return (p1.ari<p2.ari);
}
int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    process p[n],t[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter arrival time and burst time ans priority of process no "<<i+1;
        cin>>p[i].ari>>p[i].bt>>p[i].pri;
        p[i].pno=i+1;
        t[i]=p[i];
    }

    sort(p,p+n,SORT);//sorting
    int time=p[0].ari;
    process temp=p[0];//The process with least arrival time is taken to be executed first in temp variable
    int index=0,j;
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].ari<=time)//those process will be checked which have arrival time less than our current time bcz only that are ready to be processed
            {
                if(p[i].pri>temp.pri && p[i].bt!=0)//if any process whose burst time is not completed has priority greater than th priority of current selected process then that will be stored in temp
                {
                    temp=p[i];
                    index=i;
                }
            }
        }
        time++;
        p[index].bt--;//reduce the burst time of process that is executing
        p[index].ct=time;//take its completion ti,me to be current time
        temp.pri=0;//if all the process have 0 burst time left then j will become n and in next if statement it will break from while loop

        for(j=0;j<n;j++)
          {
                if(p[j].bt!=0)//if all the process have 0 burst time left then j will become n and in next if statement it will break from while loop
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
