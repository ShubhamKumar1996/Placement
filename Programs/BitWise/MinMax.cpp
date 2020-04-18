#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 10, y = 20, r;
    r = x^((x^y) & -(x<y));     //max
    cout<<r<<" ";
    r = y^((x^y) & -(x<y));     // min
    cout<<r;
    return 0;
}
