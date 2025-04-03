#include<iostream>
using namespace std;
#define OVERFLOW 1
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
            ptr=new int[capacity];
            lastIndex=-1;
        }
        bool is_Empty();
        void Append(int);
        bool is_Full();
        void Insert(int,int);
        void Edit(int,int);
        void Delete_Data(int);
        int Get(int);
        int Count_Elements();
        ~Array();
        int Found_Element(int data);
        void ShowData();
};
bool Array::is_Empty()
{
    return lastIndex==-1;
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
bool Array::is_Full()
{
    return lastIndex==capacity-1;
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
    for(int i=lastIndex;i>=index;i--)
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
void Array::Delete_Data(int index)
{
    if(index<0 || index>lastIndex)
    {
        throw OVERFLOW;
    }
    for(int i=index;i<lastIndex;i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
}
int Array::Get(int index)
{
    if(index<0 || index>lastIndex)
    {
        throw INVALID_INDEX;
    }
    return ptr[index];
}
int Array::Count_Elements()
{
    return lastIndex+1;
}
Array::~Array()
{
    delete []ptr;
}
void Array::ShowData()
{
    for(int i=0;i<=lastIndex;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
int Array::Found_Element(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(ptr[i]==data)
        {
            return i;
        }
    }
    if(ptr[i]!=data)
    {
        return -1;
    }

}
int main()
{
    Array arr(4);
    arr.Append(1);
    arr.Append(2);
    arr.Append(3);
    //arr.Append(4);
    arr.Insert(1,5);
    //arr.Append(6);
    arr.Edit(3,6);
    arr.Delete_Data(1);
    arr.Found_Element(6);
    arr.ShowData();
    cout<<endl;
    return 0;
}