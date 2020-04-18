#include<bits/stdc++.h>
using namespace std;

class file_class
{
public:
    string name;
    int start_block, no_of_block;
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
        cin>>file[i].name>>file[i].start_block>>file[i].no_of_block;
    }
    cout<<"Search File Name:";
    cin>>x;
    for(int i=0;i<no_of_file;i++)
    {
        if(x==file[i].name)
        {
            cout<<"File Name:"<<file[i].name<<"\n";
            cout<<"Start Block:"<<file[i].start_block<<"\n";
            cout<<"No. of Blocks:"<<file[i].no_of_block<<"\n";
            cout<<"Blocks Occupied:";
            for(int j=file[i].start_block;j<file[i].start_block+file[i].no_of_block;j++)
            {
                cout<<j<<" ";
            }
            break;
        }
    }
    return 0;
}
