#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class file_class
{
public:
    string name;
    int no_of_block;
    Node *head;
};

Node* Linked_List(int no_of_block)
{
    Node *start=NULL, *temp=NULL;
    for(int i=0;i<no_of_block;i++)
    {
        Node *ptr = new Node;
        cin>>ptr->data;
        ptr->next = NULL;
        if(start == NULL)
        {
            start = ptr;
            temp = ptr;
        }
        else
        {
            temp->next = ptr;
            temp = temp->next;
        }
    }
    return start;
}

int main()
{
    string x;
    int no_of_file;
    cout<<"Enter no. of files\n";
    cin>>no_of_file;
    file_class file[no_of_file];
    for(int i=0;i<no_of_file;i++)
    {
        cin>>file[i].name>>file[i].no_of_block;
        file[i].head = Linked_List(file[i].no_of_block);
    }
    cout<<"Search File Name:";
    cin>>x;
    for(int i=0;i<no_of_file;i++)
    {
        if(x==file[i].name)
        {
            cout<<"File Name:"<<file[i].name<<"\n";
            cout<<"Start Block:"<<file[i].no_of_block<<"\n";
            cout<<"Blocks Occupied:";
            Node *temp = file[i].head;
            while(temp)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            break;
        }
    }
    return 0;
}
