#include<iostream>
using namespace std;
int main()
{
    int v=0;
    int u,drop=0;
    cout<<"Enter initial velocity:"<<endl;
    cin>>u;
    while(u>v)
    {
        u=u/2;
        drop++;
    }
    cout<<"no of drops="<<drop;
    return 0;
}
