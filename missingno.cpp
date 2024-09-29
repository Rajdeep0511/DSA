#include<iostream>
using namespace std;
int missingno(int arr[] ,int size)
{
    int start ,end;
    cout<<"enter the starting number";
    cin>>start;
    cout<<"enter the ending number";
    cin>>end;
    int xor1=0, xor2=0;
    for(int i=0;i<size;i++)
    {
        xor1 ^= arr[i];
    }
    for(int i=start;i<=end;i++)
    {
        xor2 ^=i;
    }
    return xor1^xor2;

}
int main()
{
    int size;
    cout<<"enter the size of an array";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int miss;
    miss=missingno(arr,size);
    cout<<"Missing number is "<<miss;
    return 0;
    
}
