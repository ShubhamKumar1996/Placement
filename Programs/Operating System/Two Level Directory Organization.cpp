#include<bits/stdc++.h>
using namespace std;

int Menu()
{
    cout<<"1.Create Directory\t 2.Create File\t 3.Delete File\t 4.Search File\t 5.Display Files\t 6.Exit\n";
    int choice;
    cout<<"Enter your choice -- ";
    cin>>choice;
    return choice;
}

int main()
{

    string x, dir;
    int flag = 0, choice;
    map<string, int>hash;
    vector<vector<string>>v(100);

    while(1)
    {
        choice = Menu();
        switch(choice)
        {
    case 1:
        {
            cout<<"Enter name of directory -- ";
            cin>>x;
            if(hash[x]!=0)
            {
                cout<<"Directory Already Exist\n";
            }
            else
            {
                hash[x] = hash.size()-1;
                cout<<"Directory Created\n";
            }
            break;
        }


        case 2:
            {
                cout<<"Enter name of directory -- ";
                cin>>dir;
                if(hash.find(dir)==hash.end())
                {
                    cout<<"Directory "<<dir<<" Not exists\n";
                    break;
                }
                int index = hash[dir];
                cout<<"Enter name of file -- ";
                cin>>x;
                if(find(v[index].begin(), v[index].end(), x)!=v[index].end())
                {
                    cout<<"File Already Exists\n";
                    break;
                }
                v[index].push_back(x);
                cout<<"File "<<x<<" is created\n";
                break;
            }
        case 3:
            {
                cout<<"Enter name of directory -- ";
                cin>>dir;
                if(hash[dir]!=0)
                {
                    cout<<"Directory "<<dir<<" Not exists";
                    break;
                }
                int index = hash[dir];
                cout<<"Enter name of file -- ";
                cin>>x;
                auto itr = find(v[index].begin(), v[index].end(), x);
                if(itr==v[index].end())
                {
                    cout<<"File Doesn't Exists\n";
                    break;
                }
                cout<<"File "<<x<<" Deleted\n";
                v[index].erase(itr);
                break;
            }
        case 4:
        {
            cout<<"Enter name of directory -- ";
            cin>>dir;
            if(hash.find(dir)==hash.end())
            {
               cout<<"Directory "<<dir<<" Don't exists\n";
               break;
            }
            int index = hash[dir];
            cout<<"Enter File Name -- ";
            cin>>x;
            if(find(v[index].begin(), v[index].end(), x)!=v[index].end())
                cout<<"File "<<x<<" Found\n";
            else
                cout<<"File "<<x<<" Not Found\n";
            break;
        }
        case 5:
            {
                cout<<"Directories\t Files\n";
                for(auto it = hash.begin();it != hash.end(); it++)
                {
                    cout<<it->first<<"\t\t";
                    int index = it->second;
                    for(int i=0;i<v[index].size();i++)
                    {
                        cout<<v[index][i]<<" ";
                    }
                    cout<<"\n";
                }
                break;
            }
        default:{
            cout<<"Exit\n";
            flag = 1;
            break;
        }
        }
        if(flag == 1)
            break;
    }
}
