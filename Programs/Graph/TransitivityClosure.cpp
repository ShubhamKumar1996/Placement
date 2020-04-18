#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> TransitiveClosure(vector<vector<bool>>reach, int num_vertex)
{
    for(int k=1; k<=num_vertex; k++)
    {
        for(int i=1; i<=num_vertex; i++)
        {
            for(int j=1; j<=num_vertex; j++)
            {
                if(reach[i][j] == 0)
                    reach[i][j] = reach[i][k] && reach[k][j];
            }
        }
    }
    return reach;
}

void PrintMatrix(vector<vector<bool>>mat, int num_vertex)
{
    for(int i=1; i<=num_vertex; i++)
    {
        for(int j=1; j<=num_vertex; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    int num_vertex, num_edge;
    cout<<"Enter number of vertex and edge : ";
    cin>>num_vertex>>num_edge;

    vector<vector<bool>>input(num_vertex+1,(vector<bool>(num_vertex+1)));

    for(int i=1;i<=num_vertex;i++)
        for(int j=1;j<=num_vertex;j++)
            if(i==j)
                input[i][j] = true;
            else
                input[i][j] = false;

    cout<<"Enter Edges : ";
    for(int i=1; i<=num_edge; i++)
    {
        int src, des;
        cin>>src>>des;
        input[src][des] = true;
    }

    PrintMatrix(input, num_vertex);
    cout<<"Transitive Closure : \n";
    input = TransitiveClosure(input, num_vertex);
    PrintMatrix(input, num_vertex);

}
