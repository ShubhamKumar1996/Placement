#include<bits/stdc++.h>
using namespace std;

struct process
{
	int pid, at, bt, ct, tat, wt;
};

bool SORT(process a, process b)
{
    return (a.at<b.at);
}

void Completion_time(process* p, int num_of_process, int tq);
void TAT_WT(process *p, int num_of_process);
void Display(process *p, int num_of_process);


int main()
{

	int num_of_pro, tq;
	cout<<"Enter number of process:";
	cin>>num_of_pro;

	cout<<"Enter Time Quantum";
	cin>>tq;

	process p[num_of_pro];
    int copy_bt[num_of_pro];
	for(int i=0;i<num_of_pro;i++)
	{
		cout<<"Arrival Time:";
		cin>>p[i].at;
		cout<<"Burst Time:";
		cin>>p[i].bt;

	}

	Arrange_arrival(p, num_of_pro);
	for(int i=0;i<num_of_pro;i++)
        copy_bt[i] = p[i].bt;
	Completion_time(p, num_of_pro, tq);
	for(int i=0;i<num_of_pro;i++)
        p[i].bt=copy_bt[i];
	TAT_WT(p, num_of_pro);
	Display(p, num_of_pro);
	return 0;
}

void Arrange_arrival(process *p, int num_of_pro)
{
	sort(p, p+num_of_pro, SORT);
	for(int i=0;i<num_of_pro;i++)
		p[i].pid = i;
}

void Completion_time(process* p, int num_of_pro, int tq)
{
	queue<process>ready_queue;
	ready_queue.push(p[0]);
	int current_time = p[0].at;
	int lastprocess = 0;

	while(!ready_queue.empty())
	{
		process temp = ready_queue.front();
		ready_queue.pop();
		if(temp.bt<=tq)
		{
			current_time += temp.bt;
			p[temp.pid].bt = 0;
			p[temp.pid].ct = current_time;
		}
		else
		{
			p[temp.pid].bt -= tq;
			current_time += tq;
		}
		for(int i=lastprocess+1;i<num_of_pro;i++)
		{
			if(p[i].at<=current_time && p[i].bt != 0)
			{
				ready_queue.push(p[i]);
				lastprocess = i;
			}
			else
                break;
		}

		if(p[temp.pid].bt != 0)
		{
			ready_queue.push(p[temp.pid]);
		}
	}
}

void TAT_WT(process *p, int num_of_pro)
{
	for(int i=0;i<num_of_pro;i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
}

void Display(process *p, int num_of_pro)
{
	cout<<"\tpid\t\tat\t\tbt\t\tct\t\ttat\t\twt<<\n";
	for(int i=0;i<num_of_pro;i++)
	{
		cout<<"\t"<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt<<"\n";
	}
}



