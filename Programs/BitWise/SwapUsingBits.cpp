#include<bits/stdc++.h>
using namespace std;

void swapy(int x, int y)
{
    x ^= y;
    y ^= x;
    x ^= y;
}

int main()
{
    int x = 5, y=6;
    cout<<x<<" "<<y<<"\n";
    swapy(x,y);
    cout<<y<<" "<<x<<"\n";
    return 0;
}
