#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num_of_process, num_of_resource;

    cout<<"Enter Number of processes:";
    cin>>num_of_process;
    cout<<"Enter Number of resources:";
    cin>>num_of_resource;

    int allocation[num_of_process][num_of_resource], max[num_of_process][num_of_resource],
    need[num_of_process][num_of_resource];
    int available[num_of_resource];
    bool sequence[num_of_process];
    int flag;
    memset(sequence, false, sizeof(sequence));

    // Process Details

    for(int i=0;i<num_of_process;i++)
    {
        cout<<"Enter details for P"<<i+1<<"\n";
        for(int j=0;j<num_of_resource;j++)
            cin>>allocation[i][j];
        for(int j=0;j<num_of_resource;j++)
        {
            cin>>max[i][j];
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    cout<<"Enter Available Resource:";
    for(int j=0;j<num_of_resource;j++)
    {
        cin>>available[j];
    }

    // LOGIC

    for(int i=0;i<num_of_process;i++)
    {
        for(int j=0;j<num_of_process;j++)
        {
            if(sequence[j]==true)
                continue;
            flag = 0;
            for(int k=0;k<num_of_resource;k++)
            {
                if(need[j][k]>available[k])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                cout<<"\nj="<<j<<"\n";
                sequence[j] = true;
                cout<<"available:\n";
                for(int k=0;k<num_of_resource;k++)
                {
                    available[k] += allocation[j][k];
                    cout<<available[k]<<" ";
                }

            }
        }
        if(flag == 1)
        {
            cout<<"System is Unsafe\n";
            break;
        }
    }

    return 0;

}
