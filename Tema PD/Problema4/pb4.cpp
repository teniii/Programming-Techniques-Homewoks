#include <iostream>

using namespace std;

int v[100],nr;

void dei3(int n, int inc, int sf)
{
    int mij=inc/2+sf/2;
    if(n==1) nr=v[inc];
    if(v[mij]>v[mij-1] && v[mij]<v[mij+1])
        dei3(n/2,mij,sf);
    else if(v[mij]<v[mij-1] && v[mij]>v[mij+1])
        dei3(n/2,inc,mij);
    else nr=v[mij];

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    dei3(n,0,n-1);
    cout<<nr;
    return 0;
}
