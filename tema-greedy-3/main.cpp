#include <iostream>
#include <algorithm>

using namespace std;
struct scriit
{
    int inc,sf;
};

int comp(struct scriit a, struct scriit b)
{
    if(a.inc>b.inc)
        return 1;
    return 0;
}

int main()
{
    int n,max=-1,aux,contor=1;
    cin>>n;
    struct scriit v[n];
    for(int i=0;i<n;i++)
        cin>>v[i].inc>>v[i].sf;
    sort(v,v+n,comp);
    aux=v[0].sf;
    for(int i=1;i<n;i++)
    {
        if(v[i].inc>aux)
        {
            //if max + sch aux+contor
        }
    }
    return 0;
}
