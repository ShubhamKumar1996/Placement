#include<bits/stdc++.h>
using namespace std;

void DFSUntill(vector<int> *adlist, bool *visited, int src)
{
    cout<<src<<" ";
    visited[src] = true;
    for(vector<int>::iterator it = adlist[src].begin(); it!=adlist[src].end();it++)
        if(visited[*it] == 0)
            DFSUntill(adlist, visited, *it);
}


void DFS(vector<int> *adlist, int num_vertex)
{
    bool visited[num_vertex+1];
    memset(visited, false, sizeof(visited));
    visited[0] = true;

    cout<<"Enter Source Node: ";
    int src;
    cin>>src;
    cout<<"Depth First Search : ";
    //DFSUntill(adlist, visited, src); ------------------------Recursive Solution.

    //-----------------------------------------------------------Stack implementation
    stack<int>s;
    s.push(src);
    cout<<src<<" ";
    visited[src] = true;
    int temp;
    while(!s.empty())
    {
        int flag = 0;
        temp = s.top();
        for(vector<int>::iterator it = adlist[temp].begin(); it != adlist[temp].end(); it++)
        {
            if(visited[*it]==false)
            {
                flag = 1;
                s.push(*it);
                cout<< *it <<" ";
                visited[*it] = true;
                break;
            }
        }
        if(flag == 0)
            s.pop();
    }
}

int main()
{
    int num_vertex, num_edge;
    cout<<"Enter no. of vertex & edges : ";
    cin>>num_vertex>>num_edge;

    vector<int>adlist[num_vertex+1];

    cout<<"Enter Edges : ";
    for(int i=1;i<=num_edge;i++)
    {
        int x, y;
        cin>>x>>y;
        adlist[x].push_back(y);
        adlist[y].push_back(x);
    }

    DFS(adlist, num_vertex);

    return 0;
}
