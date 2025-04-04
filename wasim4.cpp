#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node *next;
};
class SLL
{
    private:
        Node *start;
    public:
        SLL()
        {
            start=nullptr;
        }
        void Insert_At_Beginning(int data);
        void Insert_At_End(int);
        void ShowData();
        Node* Search(int);
        void Insert_After(Node *,int);
        void Delete_At_Start();
        void Delete_At_Last();
        void Delete_Specific(int);
        ~SLL();
};
SLL::~SLL()
{
    while(start)
    {
        Delete_At_Start();
    }
}
void SLL::Delete_Specific(int data)
{
    Node *temp1,*temp2;
    temp2=Search(data);
    temp1=start;
    if(start)
    {
        if(temp2)
        {
            if(temp1==temp2)
            {
                Delete_At_Start();
            }
            else
            {
                while(temp1->next!=temp2)
                {
                    temp1=temp1->next;
                }
                temp1->next=temp2->next;
                free(temp2);
            }
        }
    }
}
void SLL::Delete_At_Last()
{
    if(start)
    {
        Node *temp;
        temp=start;
        if(temp->next==nullptr)
        {
            delete temp->next;
            start=nullptr;
        }
        else
        {
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            delete temp->next->next;
            temp->next=nullptr;
            //delete temp;
        }
    }
}
void SLL::Delete_At_Start()
{
    Node *temp;
    if(start)
    {
        temp=start;
        start=start->next;
        delete temp;
    }
}
void SLL::Insert_After(Node *s,int data)
{
    if(s!=nullptr)
    {
        Node *n =new Node;
        n->item=data;
        n->next=s->next;
        s->next=n;
    }
}
Node* SLL::Search(int data)
{
    Node *temp;
    temp=start;
    while(temp!=nullptr)
    {
        if(temp->item==data)
        {
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
void SLL::Insert_At_End(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=nullptr;
    Node *temp;
    if(start==nullptr)
    {
        start=n;
    }
    else
    {
        temp=start;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
void SLL::Insert_At_Beginning(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::ShowData()
{
    Node *temp;
    temp=start;
    while(temp!=nullptr)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
int main()
{
    SLL s1;
    s1.Insert_At_Beginning(1);
    s1.Insert_At_Beginning(2);
    s1.Insert_At_Beginning(3);
    s1.Insert_At_End(4);
    Node *temp=s1.Search(2);
    if(temp!=nullptr)
    {
        s1.Insert_After(temp,44);
    }
    //s1.Search(2);
    //s1.Delete_At_Start();
    //s1.Delete_At_Last();
    //s1.Delete_At_Last();
    //s1.Delete_At_Last();
    //s1.Delete_At_Last();
    s1.Delete_Specific(44);
    s1.ShowData();
    cout<<endl;
    return 0;
}