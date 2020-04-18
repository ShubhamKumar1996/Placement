#include<bits/stdc++.h>
#include<vector>
using namespace std;

void BFS(vector<int> *adlist , int num_vertex)
{
    int src;
    cout<<"Enter Source Node: ";
    cin>>src;

    cout<<"BFS Traversal : ";

    bool visited[num_vertex+1];
    for(int i=1;i<=num_vertex;i++)
    {
        visited[i] = false;
    }
    visited[src] = visited[0] = true;

    queue<int>q;
    q.push(src);
    int temp;
    while(!q.empty())
    {
        temp = q.front();
        cout<<temp<<" ";
        q.pop();

        for(vector<int>::iterator itr = adlist[temp].begin(); itr != adlist[temp].end(); itr++)
        {
            if(visited[*itr] == false)
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
}


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
    BFS(adlist, num_vertex);

    // Print BFS.
    /*int src;
    cout<<"Enter Source Node: ";
    cin>>src;

    cout<<"BFS Traversal : ";

    bool visited[num_vertex+1];
    for(int i=1;i<=num_vertex;i++)
    {
        visited[i] = false;
    }
    visited[src] = visited[0] = true;

    queue<int>q;
    q.push(src);
    int temp;
    while(!q.empty())
    {
        temp = q.front();
        cout<<temp<<" ";
        q.pop();

        for(vector<int>::iterator itr = adlist[temp].begin(); itr != adlist[temp].end(); itr++)
        {
            if(visited[*itr] == false)
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
    */
    return 0;
}
