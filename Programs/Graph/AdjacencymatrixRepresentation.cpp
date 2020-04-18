#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int num_vertex, num_edge;
    cout<<"Enter number of vertex and edge: ";
    cin>>num_vertex>>num_edge;
    vector<int>adlist[num_vertex+1];
    cout<<"Enter edges: ";
    for(int i=1;i<=num_edge;i++)
    {
        int x, y;
        cin>>x>>y;
        adlist[x].push_back(y);
        adlist[y].push_back(x);
    }

    for(int i=1;i<=num_vertex;i++)
    {
        cout<<"Adjacency List of "<<i<<" : ";
        for(vector<int>:: iterator itr=adlist[i].begin(); itr!=adlist[i].end(); itr++)
        {
            cout<<"->"<<*itr<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
