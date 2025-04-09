#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
    private:
        node *start;
    public:
        DLL();
        void Insert_At_Beginning(int);
        void ShowData();
        void Insert_At_End(int);
        void Search(int);
};
DLL::DLL()
{
    start=nullptr;
}
void DLL::Insert_At_Beginning(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=nullptr;
    if(start==nullptr)
    {
        n->next=nullptr;
        start=n;
    }
    else
    {
        n->next=start;
        start->prev=n;
        start=n;
    }
}
void DLL::ShowData()
{
    node *temp;
    temp=start;
    while(temp!=nullptr)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
void DLL::Insert_At_End(int data)
{
    node *n=new node;
    n->item=data;
    n->next=nullptr;
    node *temp;
    temp=start;
    if(start)
    {
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
    else
    {
        Insert_At_Beginning(data);
    }
}
void DLL::Search(int data)
{
    node *temp;
    temp=start;
    if(start)
    {
        while(temp->next!=nullptr)
        {
            if(temp->next->item==data)
            {
                cout<<temp->next->item<<endl;
                break;
            }
            temp=temp->next;
        }
        if(temp->next==nullptr)
        {
            cout<<"Not found"<<endl;
        }
    }
    else
    {
        cout<<"Not Found";
    }
}
int main()
{
    DLL d1;
    d1.Insert_At_Beginning(2);
    d1.Insert_At_Beginning(3);
    d1.Insert_At_Beginning(66);
    d1.Insert_At_End(33);
    d1.Insert_At_End(36);
    d1.Search(66);
    d1.ShowData();
    cout<<endl;
    return 0;
}