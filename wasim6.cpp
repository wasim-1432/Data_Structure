#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node *next;
};
class CLL
{
    private:
        Node *last;
    public:
        CLL()
        {
            last=nullptr;
        }
        void Insert_At_Beginning(int);
        void Insert_At_Last(int);
        Node* Search(int);
        void Insert_After_Specified_Node(Node*,int);
        void Delete_First();
        void Delete_Last_Node();
        void Show_Linked_List();
};
void CLL::Insert_At_Beginning(int data)
{
    Node *n=new Node;
    n->item=data;
    if(last==nullptr)
    {
        last=n;
        n->next=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CLL::Insert_At_Last(int data)
{
    Node *n=new Node;
    n->item=data;
    if(last==nullptr)
    {
        Insert_At_Beginning(data);
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
Node* CLL::Search(int data)
{
    Node *temp;
    if(last)
    {
        temp=last;
        while(temp->item!=data)
        {
            temp=temp->next;
        }
        if(temp->item==data)
        {
            return temp;
        }
    }
    return nullptr;
}
void CLL::Insert_After_Specified_Node(Node* s,int data)
{
    Node *n=new Node;
    n->item=data;
    if(last!=s)
    {
        n->next=s->next;
        s->next=n;
    }
    else if(last==s)
    {
        Insert_At_Last(data);
    }
}
void CLL::Delete_First()
{
    if(last)
    {
        if(last->next==last)
        {
            delete last;
            last=nullptr;
        }
        else
        {
            Node *t=last->next;
            last->next=t->next;
            delete t;
        }
    }
}
void CLL::Delete_Last_Node()
{
    if(last)
    {
        if(last->next==last)
        {
            Delete_First();
        }
        else
        {
            Node *temp;
            temp=last;
            while(temp->next!=last)
            {
                temp=temp->next;
            }
            temp->next=last->next;
            delete last;
            last=temp;
        }
    }
}
void CLL::Show_Linked_List()
{
    Node *temp;
    temp=last->next;
    while(temp!=last)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    cout<<last->item<<endl;
}
int main()
{
    CLL c1;
    c1.Insert_At_Beginning(3);
    c1.Insert_At_Beginning(6);
    c1.Insert_At_Beginning(77);
    c1.Insert_At_Beginning(76);
    c1.Insert_At_Last(5);
    Node *temp=c1.Search(77);
    if(temp!=nullptr)
    {
        c1.Insert_After_Specified_Node(temp,33);
    }
    //c1.Delete_First();
    c1.Delete_Last_Node();
    c1.Delete_Last_Node();
    c1.Show_Linked_List();
    cout<<endl;
    return 0;
}