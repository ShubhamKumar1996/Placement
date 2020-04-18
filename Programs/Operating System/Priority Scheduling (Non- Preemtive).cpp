#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
        *a = *b;
        *b = temp;
}

void Completion_Time(int mat[][7], int num_of_pro)
{
    mat[0][4] = mat[0][1]+mat[0][2];
    mat[0][5] = mat[0][4]-mat[0][1];
    mat[0][6] = mat[0][5]-mat[0][2];

    for(int i=1;i<num_of_pro;i++)
    {
        int temp = mat[i-1][4];
        int low = mat[i][3];
        int index = i;
        for(int j=i+1;j<num_of_pro;j++)
        {
            if(mat[j][3]>mat[j+1][3])
            {
                low = mat[j+1][3];
                index = j;
            }
        }

        mat[index][4] = temp+mat[index][2];
        mat[index][5] = mat[index][4]-mat[index][1];
        mat[index][6] = mat[index][5]-mat[index][2];

        for(int k=0;k<7;k++)
        {
            swap(mat[index][k], mat[i][k]);
        }
    }
}

void Arrange_Arrival(int mat[][7], int num_of_pro)
{
    for(int i=0;i<num_of_pro;i++)
    {
        for(int j=0;j<num_of_pro;j++)
        {
            if(mat[j][1]>mat[j+1][1])
            {
                for(int k=0;k<7;k++)
                {
                    swap(mat[j][k], mat[j+1][k]);
                }
            }
        }
    }
}


int main()
{
    int num_of_pro;
    cout<<"Number of Process: ";
    cin>>num_of_pro;

    int mat[num_of_pro][7];
    memset(mat, 0, sizeof(mat));

    for(int i=0;i<num_of_pro;i++)
    {
        cout<<"Process Id:";
        cin>>mat[i][0];
        cout<<"Arrival Time:";
        cin>>mat[i][1];
        cout<<"Burst Time:";
        cin>>mat[i][2];
        cout<<"Priority Level:";
        cin>>mat[i][3];
    }

    Arrange_Arrival(mat, num_of_pro);
    Completion_Time(mat, num_of_pro);
    cout<<"Process Id\tArrival Time\tBurst Time\tpriority level\tCompletion Time\tTurn Around Time\tWaiting Time\n";

    for(int i=0;i<num_of_pro;i++)
        cout<<"\t"<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][3]<<"\t\t"<<mat[i][4]<<"\t\t"<<mat[i][5]<<"\t\t"<<mat[i][6]<<"\n";
    return 0;
}
