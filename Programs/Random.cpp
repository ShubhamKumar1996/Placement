#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int i,k;
    cin>>str>>k;
    int len=str.size();

    for(i=0;i<len;i++)
    {
        if(isupper(str[i]))
        {
            if(str[i]+k>'Z')
                str[i] = 'A'+k-('Z'+ 1 - str[i]);
            else
                str[i]+=k;
            cout<<str[i]<<"\n";
        }
        else if(islower(str[i]))
        {
            if(str[i]+k>'z')
                str[i] = 'a'+k-('z'+ 1 - str[i]);
            else
                str[i]+=k;
        }
        else if(isdigit(str[i]))
        {
            if(str[i]+k>'9')
                str[i] = '0'+k-('9'+ 1 - str[i]);
            else
                str[i]+=k;
        }
    }
   cout<<str<<"\n";
}
