#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    int arr[n], output[n];
    cout<<"Enter Array Elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int range = *max_element(arr, arr+n);

    cout<<"range:"<<range<<"\n";

    // counting Sort.
    int count[range+1] = {};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<range+1;i++){
        count[i] = count[i]+count[i-1];
    }

    for(int i=0;i<range+1;i++)
        cout<<count[i]<<" ";
    cout<<"\n";

    for(int i=0;i<n;i++){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    cout<<"Sorted Array: ";

    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<"\n";
}

