#include<iostream>
using namespace std;
#define UNDERFLOW 1
struct Node
{
    int item;
    Node *next;
};
class Queue
{
    private:
        Node *front;
        Node *rear;
    public:
        Queue();
        void Insert(int);
        bool Is_Empty();
        int View_Rear();
        int View_Front();
        void Delete_Element();
        ~Queue();
        int Count();
};
Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
}
void Queue::Insert(int data)
{
    Node *n=new Node;
    n->item=data;
    if(Is_Empty())
    {
        front=rear=n;
        n->next=nullptr;
    }
    else
    {
        n->next=nullptr;
        rear->next=n;
        rear=n;
    }
}
bool Queue::Is_Empty()
{
    return (front==nullptr && rear==nullptr);
}
int Queue::View_Rear()
{
    if(rear==nullptr)
    {
        throw UNDERFLOW;
    }
    return rear->item;
}
int Queue::View_Front()
{
    if(rear==nullptr)
    {
        throw UNDERFLOW;
    }
    return rear->item;
}
void Queue::Delete_Element()
{
    if(rear==nullptr)
    {
        throw UNDERFLOW;
    }
    if(rear==front)
    {
        Node *temp;
        temp=rear;
        rear=nullptr;
        front=nullptr;
        delete temp;
    }
    Node* temp;
    temp=front;
    front=front->next;
    delete temp;
}
Queue::~Queue()
{
    while(front!=nullptr)
    {
        Delete_Element();
    }
}
int Queue::Count()
{
    if(front==nullptr)
        return 0;
    int count=0;
    Node *temp;
    temp=front;
    while(temp!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int main()
{
    Queue q1;
    q1.Insert(1);
    q1.Insert(2);
    q1.Insert(33);
    q1.Count();
    //q1.Delete_Element();
    //q1.View_Front();
    //q1.View_Rear();
    cout<<endl;
    return 0;
}