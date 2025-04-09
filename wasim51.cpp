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
        node* Search(int);
        void Insert_Specifiend_Index(node*,int);
        void Delete_First_Node();
        void Delete_Last_Node();
        void Delete_Specific_Node(node *);
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
node* DLL::Search(int data)
{
    node *temp;
    temp=start;
    while(temp!=nullptr)
    {
        if(temp->item==data)
        {
            return temp;
            break;
        }
        temp=temp->next;
    }
    if(temp->next==nullptr)
    {
        return nullptr;
    }
}
void DLL::Insert_Specifiend_Index(node *s,int data)
{
    node *n=new node;
    n->item=data;
    if(s->next==nullptr)
    {
        s->next=n;
        n->prev=s;
        n->next=nullptr;
    }
    else
    {
        n->next=s->next;
        n->prev=s;
        s->next->prev=n;
        s->next=n;
    }
}
void DLL::Delete_First_Node()
{
    if(start)
    {
        node *temp;
        temp=start;
        if(temp->next!=nullptr)
        {
            start=start->next;
            start->prev=nullptr;
            delete temp;
        }
        else
        {
            start=nullptr;
        }
    }
}
void DLL::Delete_Last_Node()
{
    node *temp;
    temp=start;
    if(start)
    {
        if(temp->next==nullptr)
        {
            start=nullptr;
        }
        else
        {
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=nullptr;
        }
    }
}
void DLL::Delete_Specific_Node(node *)
{
    if(start)
    {
        node *temp;
        temp=temp->next;
        if(start->next==nullptr)
        {
            Delete_First_Node();
        }
        else if(temp->next->next==nullptr)
        {
            temp->next=nullptr;
        }
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
    /*node *temp=d1.Search(66);
    if(temp!=nullptr)
    {
        d1.Delete_Specific_Node(temp);
    }*/
    d1.Delete_First_Node();
    d1.Delete_Last_Node();
    d1.ShowData();
    cout<<endl;
    return 0;
}