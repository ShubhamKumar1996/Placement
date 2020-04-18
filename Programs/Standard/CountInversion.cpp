#include<bits/stdc++.h>
#define ll unsigned long int
using namespace std;

ll Merge(ll *v, ll *temp, ll start, ll end)
{
    ll count = 0;
    ll mid = (start+end)/2;
    ll i = start, j = mid+1, k = start;

    while((i<=mid) && (j<=end))
    {
        if(v[i]<=v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            count = count + (mid+1-i);
            temp[k++] = v[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++] = v[i++];
    }

    while(j<=end)
    {
        temp[k++] = v[j++];
    }

    for(i=start; i<=end; i++)
    {
        v[i] = temp[i];
    }

    return count;
}

ll MergeSort(ll *v, ll *temp, ll start, ll end)
{
    ll count = 0;

    if(start<end)
    {
        ll mid = (start+end)/2;

        count = MergeSort(v, temp, start, mid);
        count += MergeSort(v, temp, mid+1, end);

        count += Merge(v, temp, start, end);

    }

    return count;

}

int main()
{
    int t; cin>>t; while(t--)
    {
        ll n; cin>>n;

        cout<<"n:"<<n<<"\n";

        ll a[n], temp[n];

        for(ll i=0;i<n;i++)
            cin>>a[i];

        cout<<"Array\n";
        for(ll i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";

        ll ans = MergeSort(a, temp , 0, n-1);

        cout<<ans<<"\n";

    }
}
