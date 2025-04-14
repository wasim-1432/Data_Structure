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
        void Show_Queue();
        void Delete_Queue();
        bool Is_Empty();
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
    if(rear==-1 && front==-1)
    {
        rear++;
        ptr[rear]=data;
        front++;
        ptr[front]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
bool Queue::Is_Full()
{
    return rear==capacity-1;
}
void Queue::Show_Queue()
{
    if(front==rear)
    {
        cout<<"Rear="<<ptr[rear]<<" Front="<<ptr[--front];
    }
    else
    {
        cout<<"Rear="<<ptr[rear]<<" Front="<<ptr[front];
    }
}
void Queue::Delete_Queue()
{
    if(Is_Empty())
    {
        throw UNDERFLOW;
    }
    int i;
    for(i=front;i<rear;i++)
    {
        ptr[i]=ptr[i+1];
    }
    rear--;
}
bool Queue::Is_Empty()
{
    return rear==front==-1;
}
int main()
{
    Queue q1(5);
    q1.Insert(1);
    /*q1.Insert(2);
    q1.Insert(3);
    q1.Insert(4);*/
    q1.Insert(5);
    q1.Delete_Queue();
    q1.Show_Queue();
    cout<<endl;
    return 0;
}