#include<bits/stdc++.h>
using namespace std;

int CutRod(int *price, int n, int size)
{
    if(size>n)
        return 0;

    int curr_price = price[size]*(n/size) + price[n%size];
    int max_untill = CutRod(price, n, size+1);
    return max(curr_price, max_untill);
}

int main()
{
    int n;
    cin>>n;
    int *price = new int[n+1];
    for(int i=1;i<=n;i++)
        cin>>price[i];
    price[0] = 0;
    cout<<CutRod(price, n, 1);
    return 0;
}
