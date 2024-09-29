#include<iostream>
using namespace std;
int A(int n,int m)
{
  if(n==0)
  {
    cout<<'a'<<m; 
    return 1;
  }
  else{
    cout<<"a"<<m-n<<" + x(";
    return A(n-1,m);
  }
}

int main()
{
  int n,m;
  cout<<"enter the power of x;";
  cin>>n;
  m=n;
  A(n,m);
  for(int i=0; i<m;i++){
    cout<<")";
  }
return 0; 
}
