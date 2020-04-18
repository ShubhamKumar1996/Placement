#include<bits/stdc++.h>
using namespace std;

int countOne(int n)
{
    int count = 0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{

    int t; cin>>t; while(t--)
    {

        int n; cin>>n;
        cout<<countOne(n)<<"\n";
    }

    return 0;
}
