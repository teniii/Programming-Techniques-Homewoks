#include <iostream>
#include <algorithm>

using namespace std;

struct interval
{
    int inc,sf;
};


int comp(struct interval a, struct interval b)
{
    if(a.inc<b.inc)
        return 1;
    if(a.inc==b.inc && a.sf>b.sf)
        return 1;
    return 0;
}

int main()
{
    int n,ct=0;
    cin>>n;
    struct interval v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i].inc>>v[i].sf;
    }
    sort(v,v+n,comp);
    struct interval c=v[0];
    for(int i=0;i<n;i++)
    {
        if(c.inc<v[i].inc && c.sf>v[i].sf)
            ct++;
        if(c.sf<v[i].inc)
            c=v[i];
    }

    cout<<ct;
    return 0;
}
