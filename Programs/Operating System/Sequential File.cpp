#include<iostream>
#include<string.h>
using namespace std;
struct file
{
    string name;
    int sb,nob;
};
int main()
{
    file fi[10];
    int n,flag=0;
    cout<<"enter no of files\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"file name "<<i+1<<'\n';
        cin>>fi[i].name;
        cout<<"file starting block\n";
        cin>>fi[i].sb;
        cout<<"file no of blocks\n";
        cin>>fi[i].nob;
    }
    string s;
    cout<<"enter the file you want to search\n";
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s==fi[i].name)
        {
            flag=1;
            cout<<fi[i].name<<'\t'<<fi[i].sb<<'\t'<<fi[i].nob<<'\t';
            for(int j=0;j<fi[i].nob;j++)
                cout<<fi[i].sb + j<<" ";
        }

    }
     if(flag==0)
            cout<<"file not found\n";
    return 0;

}
