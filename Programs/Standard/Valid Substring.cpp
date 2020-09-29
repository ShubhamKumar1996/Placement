/*
                Valid Substring

Given a string S consisting only of opening and closing
 parenthesis 'ie '('  and ')', find out the length of
 the longest valid substring.

    Input
4
(()(
()()((
((()()())))
()(())(

    Output
2
4
10
6

Link:- https://practice.geeksforgeeks.org/problems/valid-substring/0

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t; cin>>t; while(t--)
    {
        string s; cin>>s;
        int n = s.size(), opening_count = 0;
        stack<int>stk;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){
                stk.push(i);
                opening_count++;
            }
            else if(opening_count>0 && s[i]==')'){
                stk.pop();
                opening_count--;
            }
            else
                stk.push(i);
        }
        int max = 0, next = n-1;
        while(!stk.empty()){
            if(max<next-stk.top())
                max = next - stk.top();
            next =  stk.top()-1;
            stk.pop();
        }
        if(max<next+1)
            max = next+1;
        cout<<max<<"\n";

    }

	return 0;
}


