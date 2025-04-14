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
        void Insert(int);
        bool Is_Full();
        void Delete_Queue();
        bool Is_Empty();
        void View_Rear();
        void View_Front();
        ~Queue();
        int Total_Elements();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[capacity];
}
void Queue::Insert(int data)
{
    if(Is_Full())
    {
        throw OVERFLOW;
    }
    if(Is_Empty())
    {
        front=0;
        rear=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1)
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
bool Queue::Is_Full()
{
    return (capacity-1==rear && front==0 || rear+1==front);
}
void Queue::Delete_Queue()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    ptr[front]=ptr[front+1];
    rear--;
    if(rear==-1)
    {
        front--;
    }
}
bool Queue::Is_Empty()
{
    return front==-1;
}
void Queue::View_Rear()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<ptr[rear]<<endl;
}
void Queue::View_Front()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    cout<<ptr[front]<<endl;
}
Queue::~Queue()
{
    delete []ptr;
}
int Queue::Total_Elements()
{
    return rear+1;
}
int main()
{
    Queue q1(5);
    q1.Insert(1);
    q1.Insert(2);
    q1.Insert(3);
    q1.Insert(4);
    q1.Insert(5);
    //q1.Insert(6);
    q1.Delete_Queue();
    q1.Insert(88);
    //q1.Show_Queue();
    //q1.View_Rear();
    q1.Total_Elements();
    cout<<endl;
    return 0;
}