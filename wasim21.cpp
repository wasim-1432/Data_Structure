#include<iostream>
using namespace std;
#define OVERFLOW 1;
#define INVALID_INDEX 2
class Array
{
    private:
        int capacity;
        int *ptr;
        int lastIndex;
    public:
        Array(int size)
        {
            capacity=size;
            lastIndex=-1;
            ptr=new int[capacity];
        }
        bool is_Empty();
        void Append(int);
        bool is_Full();
        void Insert(int index,int data);
        void ShowData();
        void Edit(int index,int data);
        void Delete_Elements(int);
        void Get(int);
        int Count_Elments();
        ~Array();
        int Find(int);
        Array& operator=(Array&);
        Array(Array &);
};
Array& Array::operator=(Array &arr)
{
    if(ptr==nullptr)
    {
        delete []ptr;
    }
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    for(int i=0;i<=lastIndex;i++)
    {
        ptr[i]=arr.ptr[i];
    }
    return *this;
}
bool Array::is_Empty()
{
    return lastIndex==-1;
}
bool Array::is_Full()
{
    return lastIndex==capacity-1;
}
void Array::Append(int data)
{
    if(is_Full())
    {
        throw OVERFLOW;
    }
    lastIndex++;
    ptr[lastIndex]=data;
}
void Array::ShowData()
{
    for(int i=0;i<=lastIndex;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
void Array::Insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALID_INDEX;
    }
    if(is_Full())
    {
        throw OVERFLOW;
    }
    lastIndex++;
    int i;
    for(i=lastIndex;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    }
    ptr[index]=data;
}
void Array::Edit(int index,int data)
{
    if(index<0 || index>lastIndex)
    {
        throw INVALID_INDEX;
    }
    ptr[index]=data;
}
void Array::Delete_Elements(int index)
{
    if(index<0 || index>lastIndex)
    {
        throw INVALID_INDEX;
    }
    int i;
    for(i=index;i<lastIndex;i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
}
void Array::Get(int index)
{
    if(index<0 || index>lastIndex)
    {
        throw INVALID_INDEX;
    }
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(i==index)
        {
            cout<<"Required Answer is="<<ptr[i]<<endl;
        }
    }
}
int Array::Count_Elments()
{
    cout<<lastIndex+1<<endl;;
}
Array::~Array()
{
    delete []ptr;
}
int Array::Find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(ptr[i]==data)
        {
            return i;
        }
    }
    return -1;
}
Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
    {
        ptr[i]=arr.ptr[i];
    }
}
int main()
{
    Array arr(5);
    arr.Append(2);
    arr.Append(2);
    arr.Append(3);
    arr.Insert(1,1);
    arr.Append(4);
    //arr.Insert(2,88);
    //arr.Append(6);
    arr.Delete_Elements(2);
    arr.Edit(1,33);
    arr.Get(3);
    arr.Count_Elments();
    Array second_arr=arr;
    second_arr.ShowData();
    cout<<endl;
    return 0;
}