#include<iostream>
#include<cmath>
using namespace std;

bool Jump_Search(int *arr, int n, int item);
bool Search(int *arr, int n, int prev, int step, int index, int item);      // Helper


int main()
{
    int n;
    cout<<"Enter size:";
    cin>>n;

    int arr[n];
    cout<<"Enter element:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int item, t;
    cout<<"Enter TestCases:";
    cin>>t;
    while(t--)
    {
        cout<<"Enter Element To Be Searched:";
        cin>>item;

        if(Jump_Search(arr, n, item))
            cout<<"Element Found\n";
        else
            cout<<"Element Not Found\n";
    }
}


// Iterative Method

/*

bool Jump_Search(int *arr, int n, int item)
{
    int step = sqrt(n);         // Ideal Jump will be of sqrt(n);

    int prev = 0;
    int index = step;
    while(arr[index]<=item)
    {
        prev = index;
        index = index + step;
    }

    for(int i=prev;i<=index;i++)
    {
        if(arr[i]==item)
            return true;
    }
    return false;

}

*/


// Recursive Method



bool Jump_Search(int *arr, int n, int item)
{
    int prev = 0, step = sqrt(n);
    int index = step;

    return Search(arr, n, prev, step, index, item);

}

bool Search(int *arr, int n, int prev, int step, int index, int item)
{
    if(arr[index]>=item)
    {
        for(int i=prev;i<=index;i++)
            if(arr[i]==item)
                return true;
        return false;
    }
    else
    {
        return Search(arr, n, index, step, index+step, item);
    }
}




