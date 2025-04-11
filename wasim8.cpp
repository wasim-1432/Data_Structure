#include<iostream>
using namespace std;
#define OverFlow 1
#define UnderFlow 2
class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack(int);
        void Push(int);
        void Show_Stack();
        bool Is_Full();
        bool Is_Empty();
        int Peek();
        int Pop();
        ~Stack();
        void Reverse_Stack();
};
Stack::Stack(int size)
{
    capacity=size;
    top=-1;
    ptr=new int[capacity];
}
void Stack::Push(int data)
{
    if(Is_Full())
    {
        throw OverFlow;
    }
    else
    {
        top++;
        ptr[top]=data;
    }
}
void Stack::Show_Stack()
{
    int i=0;
    while(i<=top)
    {
        cout<<ptr[i]<<" ";
        i++;
    }
    cout<<endl;
}
bool Stack::Is_Full()
{
    return capacity-1==top;
}
bool Stack::Is_Empty()
{
    return top==-1;
}
int Stack::Peek()
{
    if(Is_Empty())
    {
        throw UnderFlow;
    }
    else
    {
        return ptr[top];
    }
}
int Stack::Pop()
{
    if(Is_Empty())
    {
        throw UnderFlow;
    }
    else
    {
        int temp=ptr[top];
        top--;
        return ptr[top];
    }
}
Stack::~Stack()
{
    if(ptr!=nullptr)
    {
        delete []ptr;
    }
}
int main()
{
    Stack s1(6);
    s1.Push(2);
    s1.Push(3);
    s1.Push(55);
    s1.Push(56);
    s1.Push(57);
    s1.Push(5);
    //s1.Push(88);
    //s1.Peek();
    s1.Pop();
    s1.Show_Stack();
    cout<<endl;
    return 0;
}