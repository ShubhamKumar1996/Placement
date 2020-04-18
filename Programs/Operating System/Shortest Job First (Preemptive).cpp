#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
            *a = *b;
            *b = temp;
}

void Arrange_Arrival(int mat[][6], int num_of_pro)
{
    for(int i=0;i<num_of_pro;i++)
    {
        for(int j=0;j<num_of_pro;j++)
        {
            if(mat[j][1]>mat[j+1][1])
            {
                for(int k=0;k<6;k++)
                {
                    swap(mat[j][k], mat[j+1][k]);
                }
            }
        }
    }
}

void Completion_Time(int mat[][6], int num_of_pro)
{
    int bt[num_of_pro];
    for(int i=0;i<num_of_pro;i++)
        bt[i] = mat[i][2];

    int complete = 0, current_time = 0, minimum = INT_MAX, shortest_index = 0;
    bool check = false;

    while(complete!=num_of_pro)
    {
        for(int i=0;i<num_of_pro;i++)
        {
            if((mat[i][1]<=current_time) && (bt[i]<minimum) && (bt[i]>0))
            {
                minimum = bt[i];
                shortest_index = i;
                check = true;
            }
        }

        current_time++;
        if(check==false)
            continue;

        bt[shortest_index]--;
        minimum = bt[shortest_index];

        if(bt[shortest_index]==0)
        {
            minimum = INT_MAX;
            complete++;
            check = false;
            mat[shortest_index][3] = current_time;
        }
    }
}

void TAT_WT(int mat[][6], int num_of_pro)
{
    float avg_tat = 0, avg_wt = 0;
    for(int i=0;i<num_of_pro;i++)
    {
        mat[i][4] = mat[i][3]-mat[i][1];
        mat[i][5] = mat[i][4]-mat[i][2];
        avg_tat += mat[i][4];
        avg_wt += mat[i][5];
    }

    cout<<"Average_TAT:"<<avg_tat/num_of_pro<<"\nAverage_wT:"<<avg_wt/num_of_pro<<"\n";
}


int main()
{
    int num_of_pro;
    cout<<"Enter Number Of Processes: ";
    cin>>num_of_pro;

    int mat[num_of_pro][6];
    memset(mat, 0, sizeof(mat));

    for(int i=0;i<num_of_pro;i++)
    {
        cout<<"Process Id:";
        cin>>mat[i][0];
        cout<<"Arrival Time:";
        cin>>mat[i][1];
        cout<<"Burst Time:";
        cin>>mat[i][2];
    }

    Arrange_Arrival(mat, num_of_pro);
    Completion_Time(mat, num_of_pro);

    TAT_WT(mat, num_of_pro);

    cout<<"Process Id\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for(int i=0;i<num_of_pro;i++)
    {
        cout<<"\t"<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][3]<<"\t\t"<<mat[i][4]<<"\t\t"<<mat[i][5]<<"\n";
    }
    return 0;
}
