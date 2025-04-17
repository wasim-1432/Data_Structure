#include<iostream>
using namespace std;
#define UNDERFLOW 1
struct Node
{
    int item;
    Node *prev;
    Node *next;
};
class Deque
{
    private:
        Node *front;
        Node *rear;
    public:
        Deque();
        void Insert_At_Front(int);
        int Get_Front();
        int Get_Rear();
        void Insert_At_Rear(int);
        void Delete_Front();
        void Delete_Rear();
        ~Deque();
        bool Is_Empty();
};
Deque::Deque()
{
    front=nullptr;
    rear=nullptr;
}
void Deque::Insert_At_Front(int data)
{
    Node *n=new Node;
    n->item=data;
    if(front==nullptr)
    {
        n->prev=n;
        n->next=nullptr;
        front=n;
        rear=n;
    }
    else
    {
        n->next=front;
        front->prev=n;
        n->prev=rear;
        front=n;
    }
}
int Deque::Get_Front()
{
    if(front==nullptr)
    {
        throw UNDERFLOW;
    }
    return front->item;
}
int Deque::Get_Rear()
{
    if(rear==nullptr)
    {
        throw UNDERFLOW;
    }
    return rear->item;
}
void Deque::Insert_At_Rear(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=nullptr;
    if(rear==nullptr)
    {
        n->prev=n;
        front=n;
        rear=n;
    }
    else
    {
        rear->next=n;
        n->prev=rear;
        rear=n;
        front->prev=n;
    }
}
void Deque::Delete_Front()
{
    if(front==nullptr)
        throw UNDERFLOW;
    if(rear==front)
    {
        Node *temp;
        temp=front;
        front=nullptr;
        rear=nullptr;
        delete temp;
    }
    else if(front->next==rear)
    {
        Node *temp;
        temp=front;
        front=front->next;
        front->prev=rear;
        delete temp;
    }
    else
    {
        Node *temp;
        temp=front;
        front=front->next;
        front->next->prev=rear;
        delete temp;
    }
}
void Deque::Delete_Rear()
{
    if(rear==nullptr)
        throw UNDERFLOW;
    else if(rear==front)
    {
        delete front;
        front=nullptr;
        rear=nullptr;
    }
    else
    {
        Node *temp=rear;
        front->prev=rear->prev;
        rear=rear->prev;
        front->prev->next=nullptr;
        delete temp;
    }
}
Deque::~Deque()
{
    while(front!=nullptr)
    {
        Delete_Front();
    }
}
bool Deque::Is_Empty()
{
    return front==nullptr;
}
int main()
{
    Deque q1;
    //q1.Insert_At_Front(2);
    q1.Insert_At_Front(22);
    //q1.Insert_At_Front(33);
    //q1.Insert_At_Rear(1);
    //q1.Insert_At_Rear(2);
    //q1.Insert_At_Rear(33);
    //q1.Delete_Front();
    q1.Delete_Rear();
    q1.Get_Front();
    q1.Get_Rear();
    cout<<endl;
    return 0;
}