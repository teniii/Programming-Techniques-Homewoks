#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int n,aux=0,max_neg=-9999,prod=1;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]<0)
        {
            aux++;//memoram nr de elem neg
            if(max_neg<v[i])
                max_neg=v[i];//memoram cel mai mare nr negativ
                            //pt a fi omis daca exista un nr par de
                            //elemente negative
        }
    }

    if(aux==0)
    {
        int min_poz=999;
        for(int i=0;i<n;i++)
        {
            if(v[i]<min_poz)
                min_poz=v[i];
        }
        cout<<endl<<min_poz;
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(aux%2==0)
            if(v[i]==max_neg)
            continue; //presupunem ca elementele sunt distincte
        if(v[i]==0) continue;
        prod*=v[i];
    }

    cout<<endl<<prod;

    return 0;
}
