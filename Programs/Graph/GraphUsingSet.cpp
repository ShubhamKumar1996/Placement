#include<bits/stdc++.h>
#include<unordered_set>
#include<vector>
using namespace std;

int main()
{
    int num_vertex, num_edge;
    cout<<"Enter number of vertex and edge: ";
    cin>>num_vertex>>num_edge;
    set<int>adlist[num_vertex+1];           // Unordered set can also be used for efficient query processing and insertion.
    cout<<"Enter edges: ";
    for(int i=1;i<=num_edge;i++)
    {
        int x, y;
        cin>>x>>y;
        adlist[x].insert(y);
        adlist[y].insert(x);
    }

    for(int i=1;i<=num_vertex;i++)
    {
        cout<<"Adjacency List of "<<i<<" : ";
        for(set<int>:: iterator itr=adlist[i].begin(); itr!=adlist[i].end(); itr++)
        {
            cout<<"->"<<*itr<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
