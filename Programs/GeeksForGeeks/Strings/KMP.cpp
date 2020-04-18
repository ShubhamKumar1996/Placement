#include<bits/stdc++.h>
using namespace std;

vector<int> LPS(string pat){
    vector<int>lps(pat.size(), 0);
    int i=0, j=1;
    while(j<pat.size()){
        if(pat[i]==pat[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i-1>=0)
                i = lps[i-1];
            else{
                lps[j] = 0;
                i=0;
                j++;
            }
        }
    }
    return lps;
}

bool KMP(string s, string pat, vector<int>&lps){
    int i=0, j=0;
    while(i<s.size()){
        if(s[i]==pat[j]){
            i++;
            j++;
            if(j==pat.size())
                return true;
        }
        else{
            if(j-1>=0){
                j = lps[j-1];
            }
            else{
                j = 0;
                i++;
            }
        }
    }
    return false;
}

int main(){

    string s, pat ; cin>>s>>pat;

    vector<int>lps = LPS(pat);

    if(KMP(s, pat, lps))
        cout<<"True";
    else
        cout<<"False";
}
