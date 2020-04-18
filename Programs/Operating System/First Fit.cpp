#include<bits/stdc++.h>
using namespace std;

void Solve(int *block, int *process, int num_of_block, int num_of_process)
{
    cout<<"Process No.\tProcess Size\tBlock No.\tBlock Size\tFragment\n";
    for(int i=0;i<num_of_process;i++)
    {
        bool flag = false;
        cout<<i+1<<"\t\t"<<process[i]<<"\t\t";
        for(int j=0;j<num_of_block;j++)
        {
            if(block[j]>=process[i] && block[j]!=-1)
            {
                cout<<j+1<<"\t\t"<<block[j]<<"\t\t"<<block[j]-process[i]<<"\n";

                block[j]=-1;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout<<"Memory Not Allocated\n";
    }
}

int main()
{
    int num_of_block, num_of_process;
    cout<<"Enter the number of blocks:";
    cin>>num_of_block;
    cout<<"Enter the number of process:";
    cin>>num_of_process;

    int block[num_of_block], process[num_of_process];

    cout<<"Enter the size of each block:-\n";
    for(int i=0;i<num_of_block;i++)
    {
        cout<<"Block "<<i+1<<":";
        cin>>block[i];
    }

    cout<<"Enter the size of each process:-\n";
    for(int i=0;i<num_of_process;i++)
    {
        cout<<"process "<<i+1<<":";
        cin>>process[i];
    }

    Solve(block, process, num_of_block, num_of_process);

    return 0;
}

