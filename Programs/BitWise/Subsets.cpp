#include<bits/stdc++.h>
using namespace std;

void Combination(vector<string>&result, string s)
{
    string temp;
    int n = s.size();
    int total_subsets = 1<<n;
    for(int i=0;i<total_subsets;i++)
    {
        temp = "";
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
                temp += s[j];
        }
        result.push_back(temp);
    }
}

int main()
{
    string s;
    cout<<"Enter String :";
    cin>>s;
    vector<string>result;
    Combination(result, s);
    int size = result.size();
    for(int i=0;i<size;i++)
        cout<<result[i]<<" ";
    return 0;
}
