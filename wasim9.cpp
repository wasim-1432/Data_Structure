#include<iostream>
#define EMPTY_STACK 1
using namespace std;
struct Node
{
    int item;
    Node *next;
};
class Stack
{
    private:
        Node *top;
    public:
        Stack();
        void Push(int);
        void Show_Stack();
        int Peek();
        void Pop();
        ~Stack();
};
Stack::Stack()
{
    top=nullptr;
}
void Stack::Push(int data)
{
    Node *n=new Node;
    n->item=data;
    if(top)
    {
        n->next=top;
        top=n;
    }
    else
    {
        n->next=nullptr;
        top=n;
    }
}
void Stack::Show_Stack()
{
    Node *temp=top;
    while(temp!=nullptr)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
int Stack::Peek()
{
    if(top!=nullptr)
    {
        return top->item; 
    }
    else
    {
        throw EMPTY_STACK;
    }
}
void Stack::Pop()
{
    if(top)
    {
        int data=top->item;
        Node *t;
        t=top;
        top=top->next;
        delete t;
    }
    else
    {
        throw EMPTY_STACK;
    }
}
Stack::~Stack()
{
    if(top!=nullptr)
    {
        delete []top;
    }
}
int main()
{
    Stack s1;
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(33);
    //s1.Push(6);
    //s1.Peek();
    s1.Pop();
    s1.Show_Stack();
    cout<<endl;
    return 0;
}