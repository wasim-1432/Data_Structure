#include<iostream>
using namespace std;
#define OVERFLOW 1
#define UNDERFLOW 2
class Queue
{
    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    public:
        Queue(int);
        bool is_Full();
        bool is_Empty();
        void Insert(int);
        int View_Rear();
        int View_Front();
        void Delete_Element();
        ~Queue();
        int Count();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[capacity];
}
bool Queue::is_Full()
{
    return (front==0 && rear==capacity-1||rear+1==front);
}
bool Queue::is_Empty()
{
    return front==-1;
}
void Queue::Insert(int data)
{
    if(is_Full())
    {
        throw OVERFLOW;
    }
    if(is_Empty())
    {
        front=0;
        rear=0;
        ptr[rear]=data;
    }
    if(rear==capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
int Queue::View_Rear()
{
    if(is_Empty())
    {
        throw UNDERFLOW;
    }
    return ptr[rear];
}
int Queue::View_Front()
{
    if(is_Empty())
    {
        throw UNDERFLOW;
    }
    return ptr[front];
}
void Queue::Delete_Element()
{
    if(is_Empty())
    {
        throw UNDERFLOW;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
}
Queue::~Queue()
{
    delete []ptr;
}
int Queue::Count()
{
    int c=0;
    if(front==0)
    {
        return c;
    }
    for(int i=0;i!=rear;)
    {
        c++;
        if(i==capacity-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
    }
    c++;
    return c;
}