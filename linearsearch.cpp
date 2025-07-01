#include<iostream>
using namespace std;
int linear(int a[],int k)
{
    for(int i=0;i<10;i++)
    {
        if(a[i]==k)
        return i;
    }
    return -1;
}
int main()
{
  int a[10],k;
  cout<<"enter array:"<<endl;
  for(int i=0;i<10;i++){
  cin>>a[10];
  }
 cout<<"enter element to be searched:"<<endl;
 cin>>k;
 int r;
 r=linear(a,k);
 if(r!=-1)
 {
    cout<<"element present at"<<r;
 }
 else{
    cout<<"element not present";
 }
 return 0;
}
