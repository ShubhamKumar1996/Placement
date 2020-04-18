#include<bits/stdc++.h>
using namespace std;

int Menu()
{
    cout<<"1.Create File\t 2.Delete File\t 3.Search File\t 4.Display Files\t 5.Exit\n";
    int choice;
    cout<<"Enter your choice -- ";
    cin>>choice;
    return choice;
}

int main()
{

    string dir, x;
    int flag = 0, choice;
    vector<string>v;
    cout<<"Enter name of directory -- ";
    cin>>dir;

    while(1)
    {
        choice = Menu();
        switch(choice)
        {
        case 1:
            cout<<"Enter name of file -- ";
            cin>>x;
            v.push_back(x);
            break;
        case 2:{
            cout<<"Enter name of file -- ";
            cin>>x;
            auto itr = find(v.begin(), v.end(), x);
            if(itr!=v.end())
            {
                cout<<"File "<<x<<" is deleted";
                v.erase(itr);
            }
            else
                cout<<"File doesn't exit\n";
            break;
        }
        case 3:{
            cout<<"Enter File Name -- ";
            cin>>x;
            if(find(v.begin(), v.end(), x)!=v.end())
                cout<<"File "<<x<<" Found\n";
            else
                cout<<"File "<<x<<" Not Found\n";
            break;
        }
        case 4:{
            cout<<"The Files are:";
            for(auto itr = v.begin(); itr!=v.end(); itr++)
            {
                cout<<*itr<<" ";
            }
            cout<<"\n";
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
