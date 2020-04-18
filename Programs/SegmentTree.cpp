#include <bits/stdc++.h>
using namespace std;

void Print_Segment_Tree(int *segment_tree, int size)
{
    for(int i=0;i<size;i++)
	    cout<<segment_tree[i]<<" ";
}


void Update(int *a, int start, int end, int *segment_tree, int curr_index, int diff, int index)
{
    if(index<start || index>end)
        return;

    segment_tree[curr_index]+=diff;
    if(start!=end)
    {
        int mid = (start+end)/2;
        Update(a, start, mid, segment_tree, 2*curr_index+1, diff, index);
        Update(a, mid+1, end, segment_tree, 2*curr_index+2, diff, index);

    }
}

int GetSum(int *segment_tree, int start, int end, int q_start, int q_end, int curr_index )
{
    if(q_start > end || q_end < start)
        return 0;
    if(q_start<=start && q_end>=end)
        return segment_tree[curr_index];

    int mid = (start+end)/2;
    return ( GetSum(segment_tree, start, mid, q_start, q_end, 2*curr_index + 1) +
             GetSum(segment_tree, mid+1, end, q_start, q_end, 2*curr_index + 2) );
}

int ConstructUntill(int *a, int start, int end, int *segment_tree, int curr_index)
{
    if(start == end)
    {
        segment_tree[curr_index] = a[start];
        return segment_tree[curr_index];
    }

    else
    {
        int mid = (start+end)/2;
        segment_tree[curr_index] = ConstructUntill(a, start, mid, segment_tree, 2*curr_index+1)+
                                ConstructUntill(a, mid+1, end, segment_tree, 2*curr_index+2);
        return segment_tree[curr_index];
    }
}

void SumQuery(int *a, int n, int *segment_tree, int size)
{
    int l,r,index, value;
    cout<<"Enter query (1-5):";
    cin>>l>>r;
    cout<<GetSum(segment_tree, 0, n-1, l, r, 0)<<"\n";

    cout<<"Enter Index and Value:";
    cin>>index>>value;
    int diff = value - a[index];
    cout<<"previous Sum:"<<segment_tree[0]<<"\n";
    Update(a, 0, n-1, segment_tree, 0, diff, index);
    cout<<"New Sum:"<<segment_tree[0]<<"\n";

}

int FindSize(int *a, int n)
{
    int height_st = ( int )( ceil( log2(n) ) );     // ceil = smallest greater element.
    int max_size = 2*(int)( pow(2, height_st) ) - 1;
    return max_size;
}

int main() {
    int n = 6;
	int a[n] = {1,3,5,7,9,11};

	int size = FindSize(a, n);

	int *segment_tree = new int[size];

	ConstructUntill(a, 0, 5, segment_tree, 0);

	SumQuery(a, n, segment_tree, size);

	Print_Segment_Tree(segment_tree, size);

	return 0;
}
