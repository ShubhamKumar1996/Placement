#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num_vertex, num_edge;
    cout<<"Enter number of vertex and edge : ";
    cin>>num_vertex>>num_edge;
    vector<pair<int,int>> adlist[num_vertex+1];

    cout<<"Enter edges (source destination) : ";
    for(int i=1; i<=num_edge; i++)
    {
        int src, des, weight;
        cin>>src>>des>>weight;
        adlist[src].push_back(make_pair(des,weight));
    }

    cout<<" Adjacency List : \n";
    for(int i=1; i<=num_vertex; i++)
    {
        cout<<i<<" : ";
        for(vector<pair<int,int>>::iterator itr = adlist[i].begin(); itr != adlist[i].end(); itr++)
        {
            cout<<" -> "<< itr->first<<" : "<< itr->second ;
        }
        cout<<"\n";
    }
}
