/*
We are given a matrix that contains different values in its each cell. Our aim is to find the minimal set of positions in the matrix such that entire matrix can be traversed starting from the positions in the set.
We can traverse the matrix under below conditions:

We can move only to those neighbors that contain value less than or to equal to the current cell’s value. A neighbor of cell is defined as the cell that shares a side with the given cell.
Examples:

Input : 1 2 3
        2 3 1
        1 1 1
Output : 1 1
         0 2
If we start from 1, 1 we can cover 6
vertices in the order (1, 1) -> (1, 0) -> (2, 0)
-> (2, 1) -> (2, 2) -> (1, 2). We cannot cover
the entire matrix with this vertex. Remaining
vertices can be covered (0, 2) -> (0, 1) -> (0, 0).

Input : 3 3
        1 1
Output : 0 1
If we start from 0, 1, we can traverse
the entire matrix from this single vertex
in this order (0, 0) -> (0, 1) -> (1, 1) -> (1, 0).
Traversing the matrix in this order
satisfies all the conditions stated above.
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(int row, int col, int num_vertex, vector<vector<int>> input , vector<vector<bool>>&visited)
{
    visited[row][col] = true;

    for(int i=row+1; i<num_vertex; i++)
        if(visited[i][col] == false)
            DFS(i, col, num_vertex, input, visited);

    for(int i=row-1; i>=0; i--)
        if(visited[i][col] == false)
            DFS(i, col, num_vertex, input, visited);

    for(int i=col+1; i<num_vertex; i++)
        if(visited[row][i] == false)
            DFS(row, i, num_vertex, input, visited);

    for(int i=col-1; i>=0; i--)
        if(visited[row][i] == false)
            DFS(row, i, num_vertex, input, visited);

    return;
}

int main()
{
    int num_vertex;

    vector<vector<int>>input(num_vertex, (vector<int>(num_vertex)));
    vector<vector<bool>>visited(num_vertex, (vector<bool>(num_vertex, false)));
    vector<pair<int, pair<int, int>>>p;

    cout<<"Enter Number of Verticies : ";
    cin>>num_vertex;
    cout<<" Enter Cell values : ";
    for(int i=0; i<num_vertex; i++)
        for(int j=0; j<num_vertex; j++)
            cin>>input[i][j];

    for(int i=0; i<num_vertex; i++)
        for(int j=0; j<num_vertex; j++)
            p.push_back(make_pair(input[i][j], make_pair(i, j)));

    sort(p.begin(), p.end());

    for(vector<pair<int, pair<int,int>>>:: iterator it = p.begin(); it!=p.end(); it++)
    {
        if(visited[((*it).second).first][((*it).second).second] == false)
        {
            cout<<((*it).second).first<<" "<<((*it).second).second<<" ";
            DFS(((*it).second).first, ((*it).second).second, num_vertex, input, visited);
        }
    }
    return 0;
}

