#include<iostream>
using namespace std;

bool Binary_Search(int *arr, int start, int end, int item);

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

        if(Binary_Search(arr, 0, n-1, item))
            cout<<"Element Found\n";
        else
            cout<<"Element Not Found\n";
    }
}


// Iterative Method

/*

bool Binary_Search(int *arr, int low, int high, int item)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==item)
            return true;
        else if(arr[mid]>item)
            high = mid-1;
        else
            low = mid + 1;
    }
    return false;
}

*/

// Recursive Method

bool Binary_Search(int *arr, int low, int high, int item)
{
    if(low>high)
        return false;
    int mid = (low+high)/2;
    if(arr[mid]==item)
        return true;
    else if(arr[mid]>item)
        return Binary_Search(arr, low, mid-1, item);
    else
        return Binary_Search(arr, mid+1, high, item);
}

