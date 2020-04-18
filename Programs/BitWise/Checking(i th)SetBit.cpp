#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t; cin>>t; while(t--)
    {

        int n,i; cin>>n>>i;
        if(n & (1<<(i-1)))
            cout<<"High\n";
        else
            cout<<"Low\n";

    }

    return 0;
}
