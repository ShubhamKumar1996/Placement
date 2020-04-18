#include<iostream>
using namespace std;

bool Exponential_Search(int *arr, int n, int item);

int main()
{
    int n;
    cout<<"Enter size:";
    cin>>n;

    int arr[n];
    cout<<"Enter element:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int item;
    int t;
    cout<<"Enter Test cases:";
    cin>>t;
    while(t--)
    {
        cout<<"Enter Element To Be Searched:";
        cin>>item;


        if(Exponential_Search(arr, n, item))
            cout<<"Element Found\n";
        else
            cout<<"Element Not Found\n";
    }
}


// Iterative Method



bool Exponential_Search(int *arr, int n, int item)
{
    if(arr[0]>item || arr[n-1]<item)
        return false;

    int index = 1;
    while(index <= n && arr[index-1]<item)
    {
        index = index * 2;
    }
    for(int i=index/2-1;i<min(index, n);i++)
        if(arr[i]==item)
            return true;
    return false;
}




// Recursive Method
/*
bool Linear_Search(int *arr, int n, int item)
{
    if(n==0)
        return false;

    if(arr[n-1]==item)
        return true;
    return Linear_Search(arr, n-1, item);
}
*/
