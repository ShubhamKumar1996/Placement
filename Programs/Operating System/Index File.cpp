#include<bits/stdc++.h>
using namespace std;

class file_class
{
public:
    string name;
    int no_of_block;
    int head[20];
};


int main()
{
    string x;
    int no_of_file;
    cout<<"Enter no. of files\n";
    cin>>no_of_file;
    file_class file[no_of_file];
    for(int i=0;i<no_of_file;i++)
    {
        cin>>file[i].name>>file[i].no_of_block;
        for(int j=0;j<file[i].no_of_block;j++)
        {
            cin>>file[i].head[j];
        }
    }
    cout<<"Search File Name:";
    cin>>x;
    for(int i=0;i<no_of_file;i++)
    {
        if(x==file[i].name)
        {
            cout<<"File Name:"<<file[i].name<<"\n";
            cout<<"No Of Block:"<<file[i].no_of_block<<"\n";
            cout<<"Blocks Occupied:";
            for(int j=0;j<file[i].no_of_block;j++)
            {
                cout<<file[i].head[j]<<" ";
            }
            break;
        }
    }
    return 0;
}
