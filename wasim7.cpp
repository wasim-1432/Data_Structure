#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node *prev;
    Node *next;
};
class CDLL
{
    private:
        Node *start;
    public:
        CDLL();
        void Insert_At_First(int);
        void Insert_At_Last(int);
        Node* Search(int);
        void Insert_After(Node*,int);
        void Delete_First();
        void Delete_Last();
        void Show_List();
};
CDLL::CDLL()
{
    start=nullptr;
}
void CDLL::Insert_At_First(int data)
{
    Node *n=new Node;
    n->item=data;
    if(start)
    {
        Node *last;
        last=start->prev;
        n->next=start;
        n->prev=last;
        last->next=n;
        start->prev=n;
        start=n;
    }
    else
    {
        start=n;
        n->next=n;
        n->prev=n;
    }
}
void CDLL::Insert_At_Last(int data)
{
    Node *n=new Node;
    n->item=data;
    if(start)
    {
        Node *last=start->prev;
        n->prev=last;
        n->next=start;
        last->next=n;
    }
    else
    {
        start=n;
        n->next=n;
        n->prev=n;
    }
}
Node* CDLL::Search(int data)
{
    if(start)
    {
        Node *temp;
        temp=start;
        while(temp->next!=start)
        {
            if(temp->item==data)
            {
                break;
            }
            temp=temp->next;
        }
        if(temp->item==data)
        {
            return temp;
        }
    }
    return nullptr;
}
void CDLL::Insert_After(Node *s,int data)
{
    if(start)
    {
        Node *n=new Node;
        n->item=data;
        Node *last=start->prev;
        if(s!=last)
        {
            n->prev=s;
            n->next=s->next;
            s->next=n;
        }
        else
        {
            n->prev=last;
            n->next=start;
            last->next=n;
        }
    }
}
void CDLL::Delete_First()
{
    if (start)
    {
        if (start->next == start) // Only one node in the list
        {
            delete start;
            start = nullptr;
        }
        else
        {
            Node* temp = start;
            start->prev->next = start->next;
            start->next->prev = start->prev;
            start=start->next;
            delete temp;
        }
    }
}
void CDLL::Delete_Last()
{
    if(start)
    {
        Node *temp=start;
        if(temp->next==start)
        {
            delete start;
            start=nullptr;
        }
        else
        {
            while(temp->next!=start->prev)
            {
                temp=temp->next;
            }
            if(temp->next==start->prev)
            {
                delete start->prev;
                start->prev=temp;
                temp->next=start;
            }
        }
    }
}
void CDLL::Show_List()
{
    Node *temp;
    temp=start;
    while(temp->next!=start)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    cout<<temp->item<<endl;
}
int main()
{
    CDLL c1;
    c1.Insert_At_First(2);
    //c1.Insert_At_First(255);
    //c1.Insert_At_First(3);
    //c1.Insert_At_First(66);
    /*Node *temp=c1.Search(2);
    if(temp!=nullptr)
    {
        c1.Insert_After(temp,34);
    }*/
    //c1.Delete_First();
    //c1.Insert_At_Last(77);
    c1.Delete_Last();
    c1.Show_List();
    cout<<endl;
    return 0;
}