#include<iostream>
using namespace std;

bool Interpolation_Search(int *arr, int low, int high, int item);

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


        if(Interpolation_Search(arr, 0, n-1, item))
            cout<<"Element Found\n";
        else
            cout<<"Element Not Found\n";
    }

}


// Iterative Method

/*
bool Interpolation_Search(int *arr, int low, int high, int item)
{
    while(low<=high && item >= arr[low] && item <= arr[high])
    {
        if(low == high)
        {
            if(arr[low]==item)
                return true;
            else
                return false;
        }
        int pos = low + (((double)(high-low)/(arr[high]-arr[low]))*(item-arr[low]));
        cout<<"Position:"<<pos<<"\n";
        if(arr[pos]==item)
            return true;
        else if(arr[pos]>item)
            high = pos-1;
        else
            low = pos + 1;
    }
    return false;
}

*/


// Recursive Method


bool Interpolation_Search(int *arr, int low, int high, int item)
{
    if(low<=high && item >= arr[low] && item <= arr[high])
    {
        if(low == high)
        {
            if(arr[low]==item)
                return true;
            return false;
        }
        int pos = (((double)(high-low)/(arr[high]-arr[low]))*(item-arr[low]));
        cout<<"Position:"<<pos<<"\n";
        if(arr[pos]==item)
            return true;
        else if (arr[pos]>item)
            return Interpolation_Search(arr, low, pos-1, item);
        else
            return Interpolation_Search(arr, pos+1, high, item);
    }
    return false;
}

