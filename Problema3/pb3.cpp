#include <iostream>

using namespace std;

int v[100];
void dei2(int n, int inc, int sf)
{
    if(n==1)
    {
        cout<<v[inc]<<" ";
        return;
    }
    if(n%2==1)
    {
        dei2(n/2,inc,inc/2+sf/2-1);
        dei2(n/2,inc/2+sf/2+1,sf);
    }
    else
    {
        for(int i=inc;i<=sf;i++)
            cout<<v[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    dei2(n,0,n-1);
    return 0;
}
