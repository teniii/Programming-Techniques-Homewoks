#include <iostream>
#include <algorithm>

using namespace std;

struct proiect
{
    int index,t,dl;//index pentru afisare
};

int cmp(struct proiect a, struct proiect b)
{
    if(a.dl<b.dl) return 1;
    return 0;
    //sortare crescatoare dupa deadline
}

int main()
{
    int n,aux=0,maxim=-1;
    cin>>n;
    struct proiect v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i].t>>v[i].dl;
        v[i].index=i; //indexare de la 0, la afisare o sa fie de la 1
    }

    sort(v,v+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<"activitatea "<<v[i].index+1<<" - ";
        cout<<"["<<aux<<","<<aux+v[i].t<<") - intarziere ";
        if(aux+v[i].t<=v[i].dl) cout<<"0"<<endl; //verificam daca s-a depasit deadline-ul
        else cout<<aux+v[i].t-v[i].dl<<endl;
        if(maxim < aux+v[i].t-v[i].dl) maxim=aux+v[i].t-v[i].dl;//memoram cea mai mare intarziere
        aux+=v[i].t; //aici memoram zilele lucrate pana la pasul i

    }
    cout<<endl;
    cout<<"Intarzierea minima este "<<maxim;



    return 0;
}
