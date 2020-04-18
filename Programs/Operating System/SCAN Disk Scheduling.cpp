#include<bits/stdc++.h>
using namespace std;

int main()
{
    int head, n, lower, upper;
    cout<<"lower & upper:";
    cin>>lower>>upper;
    cout<<"head:";
    cin>>head;
    cout<<"no. of element:";
    cin>>n;
    vector<int>v(2);
    v[0] = head, v[1] = 0;
    int temp = head, seek=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout<<"Left:"<<(head-lower+v.back())<<"\n";
    cout<<"right:"<<(upper-head+upper-v[1])<<"\n";
}
