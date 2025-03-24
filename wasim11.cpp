#include<iostream>
using namespace std;
class Array
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int size)
        {
            capacity=size;
            lastIndex=-1;
            ptr=new int[capacity];
        }
        bool is_Empty()
        {
            if(lastIndex==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void Append(int data)
        {
            lastIndex++;
            ptr[lastIndex]=data;
        }
        void Insert_New_Elements(int index,int data)
        {
            if(index<0 || index>capacity)
            {
                cout<<"Invalid Index"<<endl;
            }
            if(lastIndex+1==index)
            {
                lastIndex++;
                ptr[lastIndex]=data;
            }
            else
            {

                ptr[index]=data;
            }
        }
        void Edit_Element(int index,int data)
        {
            if(index<0 || index>lastIndex)
            {
                cout<<"Invalid Index"<<endl;
            }
            else
            {
                ptr[index]=data;
            }
        }
        void Delete_Element(int index)
        {
            if(index<0 || lastIndex<index)
            {
                cout<<"Invalid Input"<<endl;
            }
            else if(index>=0)
            {
                int i=0;
                for(i=index;i<=lastIndex;i++)
                {
                    ptr[i]=ptr[i+1];
                }
                lastIndex--;
            }
        }
        bool is_Full()
        {
            if(capacity==lastIndex-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void Get_Element(int index)
        {
            if(index<0 || index>lastIndex)
            {
                cout<<"Invalid Input"<<endl;
            }
            else
            {
                cout<<"Required data is="<<ptr[index]<<endl;
            }
        }
        void Count_Elements_Present_In_The_Array()
        {
            cout<<"Total elements in the array="<<lastIndex+1<<endl;
        }
        ~Array()
        {
            delete []ptr;
        }
        int Find_An_Element(int data)
        {
            int index;
            for(index=0;index<=lastIndex;index++)
            {
                if(ptr[index]==data)
                {
                    return index;
                }
                else
                {
                    return -1;
                }
            }
        }
        void ShowData()
        {
            int i;
            for(i=0;i<=lastIndex;i++)
            {
                cout<<ptr[i]<<" ";
            }
        }
};
int main()
{
    Array a1(5);
    a1.Append(3);
    a1.Append(45);
    a1.Insert_New_Elements(2,44);
    a1.Edit_Element(0,33);
    a1.Delete_Element(2);
    a1.Get_Element(1);
    a1.Count_Elements_Present_In_The_Array();
    //a1.is_Empty();
    a1.ShowData();
    cout<<endl;
    return 0;
}