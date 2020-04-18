#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 4;
    bool result = x && !(x&(x-1));
    if(result)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
