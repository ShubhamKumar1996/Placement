#include<bits/stdc++.h>
using namespace std;
class process {
public:
    int pno,ari,bt,ct,tat,wt,rt,ent;
    process()
    {

        pno=ari=bt=ct=tat=wt=rt=-1;
    }
};
bool SOR(process &p1,process &p2)
{

    return p1.ari<=p2.ari;
}
int main()
{

    int n;
    cout<<"enter no of process";
    cin>>n;
    process p[n],t[n];int i,j,k,tq;
    cout<<"enter time quanta ";
    cin>>tq;
    for(i=0;i<n;i++)
    {
        cout<<"enter arrival burst ";
        cin>>p[i].ari>>p[i].bt;
        p[i].pno=i+1;
        p[i].ent=i+1;
        t[i]=p[i];
    }
    sort(p,p+n,SOR);
    for(int i=0;i<n;i++)
        p[i].pno=i+1;



    queue<process>rq;
    //nt time=0;
    int time=p[0].ari;
    rq.push(p[0]);
    int lastProcess=0;
    while(!rq.empty())
    {
        process temp;
        temp=rq.front();
        rq.pop();
        if(temp.bt<=tq)
        {
            time+=temp.bt;
            p[temp.pno-1].bt=0;
            p[temp.pno-1].ct=time;
        }
        else
        {
            time+=tq;
            p[temp.pno-1].bt-=tq;
        }
        for(i=lastProcess;i<n;i++)
        {
            if(p[i].ari<=time && p[i].bt!=0)
            {
                rq.push(p[i]);
                lastProcess= p[i].pno;

            }
            else
                break;
        }
        if(p[temp.pno-1].bt!=0)
            rq.push(p[temp.pno-1]);
    }
    for(i=0;i<n;i++)
    {
        p[i].pno=p[i].ent;
        cout<<p[i].pno<<" "<<p[i].ct<<endl;
    }
}
