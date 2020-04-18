#include<bits/stdc++.h>
using namespace std;


void FloydWarshall(vector<vector<int>> &dist, int num_vertex)
{
    for(int k=1; k<=num_vertex; k++)
    {
        for(int i=1; i<=num_vertex; i++)
        {
            for(int j=1; j<=num_vertex; j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
}

void PrintMatrix(vector<vector<int>> &input, int num_vertex)
{
    for(int i=1;i<=num_vertex; i++)
    {
        for(int j=1;j<=num_vertex;j++)
        {
            if(input[i][j] == INT_MAX)
                cout<<"INF ";
            else
                cout<<input[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int num_vertex, num_edge;
    cout<<"Enter no. of vertex and edge : ";
    cin>>num_vertex>>num_edge;

    vector<vector<int>> input (num_vertex+1, (vector<int>(num_vertex+1, INT_MAX)));

    cout<<"Enter edges and weight : ";
    for(int i=1; i<=num_edge; i++)
    {
        int src, des, weight;
        cin>>src>>des>>weight;
        input[src][des] = weight;
    }

    for(int i=1; i<=num_vertex; i++)            // Daigonals 0
        for(int j=1; j<=num_vertex; j++)
            if(i==j)
                input[i][j] = 0;
    cout<<"Input Matrix\n";
    PrintMatrix(input, num_vertex);

    FloydWarshall(input, num_vertex);

    cout<<"Distance Matrix\n";

    PrintMatrix(input, num_vertex);
}
