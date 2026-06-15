#include<iostream>
using namespace std;

typedef unsigned char UINT8;
typedef unsigned short int UINT16;
typedef unsigned int UINT32;
#define SIZE 7
class array_Overload{

    public:
        int array[7];
        array_Overload()
        {
            cout<<"Default Constructor is called!"<<endl;
            for (UINT8 index=0;index<SIZE;index++)
            {
                array[index]=0;
            }
            
        }
       array_Overload(int a)
        {
            cout<<"Parameterized Constructor is called!"<<endl;
            for (UINT8 index=0;index<SIZE;index++)
            {
                array[index]=a*(index+1);
            }
        }
        array_Overload operator+(const array_Overload &other) const
        {

            array_Overload result=new array_Overload;

            for (UINT8 index=0;index<SIZE;index++)
            {
               // 'this' object represents the left side, 'other' represents the right side
               result[index]=this->array[index] + other.array[index];

            }

            return result;
        }


};

int main()
{
    array_Overload A1(1);
    array_Overload A2(3);

    for (UINT8 index=0;index<SIZE;index++)
    {
        cout<<A1.array[index]<<endl;
        cout<<A2.array[index]<<endl;

    }
    cout<< "Addition of two array:"<<endl;
    array_Overload result= A1+A2;

    for (UINT8 index=0;index<SIZE;index++)
    {

        cout<<result[index]<<endl;
    }
    delete result;
    result=NULL;

}