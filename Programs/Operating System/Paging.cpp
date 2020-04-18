#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mem_size, page_size, frame[10][20];
    cout<<"Enter memory size: ";
    cin>>mem_size;
    cout<<"Enter page size: ";
    cin>>page_size;

    int no_of_pages = mem_size/page_size;
    cout<<"Pages in the memory are: "<<no_of_pages<<"\n";

    int temp = no_of_pages, no_of_process, no_of_pages_per_process, pro_no, pg_no, off;
    cout<<"Enter no. of process: ";
    cin>>no_of_process;
    for(int i=1;i<=no_of_process;i++)
    {
        cout<<"Enter no. of pages required for process:";
        cin>>no_of_pages_per_process;
        if(no_of_pages<no_of_pages_per_process)
        {
            cout<<"Memory Full\n";
            break;
        }
        no_of_pages -= no_of_pages_per_process;
        cout<<"Enter PageTable:";
        for(int j=0;j<no_of_pages_per_process;j++)      // j=0 ka dhyan rkhio
        {
            cin>>frame[i][j];
        }
    }
    cout<<"Conversion from Physical Address to logical address\n";
    cout<<"Enter process no, page no & offset:";
    cin>>pro_no>>pg_no>>off;
    if(pro_no>no_of_process || pg_no>temp || off>page_size)
    {
        cout<<"Invalid Input";

    }
    else
    {
        cout<<"Physical Address: "<<frame[pro_no][pg_no]*page_size+off<<"\n";
    }

}
