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
    vector<int>v(1);
    v[0] = head;
    int temp = head, seek=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; v.push_back(x);
    }

    sort(v.begin(), v.end());

    cout<<"Left:"<<head-lower+upper-lower+upper-*upper_bound(v.begin(), v.end(), head)<<"\n";
    cout<<"Right:"<<upper-head+upper-lower+*(lower_bound(v.begin(), v.end(), head)-1)-0<<"\n";

}
