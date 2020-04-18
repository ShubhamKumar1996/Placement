#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
private:
    vector<int>A;
    int Parent(int i){ return (i-1)/2;}
    int Left(int i){ return (2*i+1); }
    int Right(int i) { return (2*i+2); }
    void heapify_down(int i){
        int smallest = i, left=Left(i), right = Right(i);
        if(left<A.size() && A[left]<A[smallest])
            smallest = left;
        if(right<A.size() && A[right]<A[smallest])
            smallest = right;
        if(smallest!=i){
            swap(A[smallest], A[i]);
            heapify_down(smallest);
        }
    }
    void heapify_up(int i){
        int parent = Parent(i);
        if(i!=0 && A[parent]>A[i]){
            swap(A[parent], A[i]);
            heapify_up(parent);
        }
    }
public:
    unsigned int size(){ return A.size(); }
    bool empty() { return (A.size()==0);}
    void push(int key){
        A.push_back(key);
        int index = A.size()-1;
        heapify_up(index);
    }
    void pop(){
        if(size()==0){
            cout<<"UnderFlow Error\n";
            return;
        }
        A[0]=A.back();
        A.pop_back();
        heapify_down(0);
    }
    int top(){
        if(size()==0){
            cout<<"Out of Index\n";
            return INT_MIN;
        }
        return A[0];
    }
};

int main(){
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
