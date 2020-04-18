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
    int temp, low, index;
    mat[0][3] = mat[0][1]+mat[0][2];    // First completion time = arrival + burst;
    mat[0][4] = mat[0][3]-mat[0][1];    // Turn Around Time = burst - arrival
    mat[0][5] = mat[0][4]-mat[0][2];    // Waiting Time = Turn Around Time - Burst Time.

    for(int i=1;i<num_of_pro;i++)
    {
        temp = mat[i-1][3];
        int low = mat[i][2];
        index = i;
        for(int j=i+1;j<num_of_pro;j++)
        {
            if(low>mat[j][2])
            {
                low = mat[j][2];
                index = j;
            }
        }

        mat[index][3] = temp + mat[index][2];
        mat[index][4] = mat[index][3] - mat[index][1];
        mat[index][5] = mat[index][4] - mat[index][2];

        for(int k=0;k<6;k++)
        {
            swap(mat[i][k], mat[index][k]);
        }
    }
}

int main()
{
    int num_of_pro;

    cout<<"Enter number of processes: ";
    cin>>num_of_pro;

    int mat[num_of_pro][6];
    memset(mat, 0, sizeof(mat));

    for(int i=0;i<num_of_pro;i++)
    {
        cout<<"Process ID: ";
        cin>>mat[i][0];
        cout<<"Arrival Time: ";
        cin>>mat[i][1];
        cout<<"Burst Time: ";
        cin>>mat[i][2];
    }

    // input Section is Completed here;
    // Now we Start processing.

    // Arranging according to arrival time to get first job.
    Arrange_Arrival(mat, num_of_pro);

    // Arrange and Calculating completion time, waiting time, turn around time;
    Completion_Time(mat, num_of_pro);

    // Printing Required.

    cout<<"Process Id\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n";
    for(int i=0;i<num_of_pro;i++)
    {
        cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][3]<<"\t\t\t"<<mat[i][4]<<"\t\t\t"<<mat[i][5]<<"\n";
    }
}
