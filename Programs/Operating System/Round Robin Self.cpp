#include<bits/stdc++.h>
using namespace std;

struct process
{
    int process_id, arrival_time, burst_time, completion_time, turn_around_time, waiting_time;
};

bool comp(process a, process b)
{
    return(a.arrival_time<=b.arrival_time);
}

void Display(process *p, int num_of_pro)
{
     cout<<"process_id\tarrival_time\tburst_time\tcompletion_time\tturn_around_time\twaiting_time\n";
    for(int i=0;i<num_of_pro;i++)
    {
        cout<<"\t"<<p[i].process_id<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t"<<p[i].turn_around_time<<"\t\t"<<p[i].waiting_time<<"\n";
    }
}


void TAT_WT(process *p, int num_of_pro, int *copy_bt)
{
    for(int i=0;i<num_of_pro;i++)
    {
        p[i].burst_time = copy_bt[i];
        p[i].turn_around_time = p[i].completion_time-p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time-p[i].burst_time;
    }
}

int main()
{
    int num_of_pro, time_quantum;
    cout<<"Number Of Process:";
    cin>>num_of_pro;
    cout<<"Time Quantum:";
    cin>>time_quantum;

    process p[num_of_pro];

    for(int i=0;i<num_of_pro;i++)
    {
        p[i].process_id=i;
        cout<<"Arrival Time:";
        cin>>p[i].arrival_time;
        cout<<"Burst Time:";
        cin>>p[i].burst_time;
    }

    sort(p, p+num_of_pro, comp);

    int copy_bt[num_of_pro];

    for(int i=0;i<num_of_pro;i++)
    {
        p[i].process_id = i;
        copy_bt[i] = p[i].burst_time;
    }

    queue<process>ready_queue;
    int current_time = p[0].arrival_time;
    ready_queue.push(p[0]);
    int last_process = 0;
    while(!ready_queue.empty())
    {
        process temp = ready_queue.front();
        ready_queue.pop();

        if(temp.burst_time <= time_quantum)
        {
            current_time += temp.burst_time;
            p[temp.process_id].burst_time = 0;
            p[temp.process_id].completion_time = current_time;
        }
        else
        {
            p[temp.process_id].burst_time -= time_quantum;
            current_time += time_quantum;
        }
        for(int i = last_process+1;i<num_of_pro;i++)
        {
            if(p[i].arrival_time<=current_time && p[i].burst_time!=0)
            {
                ready_queue.push(p[i]);
                last_process = p[i].process_id;
            }
            else
                break;
        }

        if(p[temp.process_id].burst_time != 0)
            ready_queue.push(p[temp.process_id]);

    }
    TAT_WT(p, num_of_pro, copy_bt);
    Display(p, num_of_pro);
    return 0;
}
