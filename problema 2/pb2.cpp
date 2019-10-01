#include <iostream>
#include <fstream>
using namespace std;

int a[100][100];

void fil(int li,int ls,int ci,int cs,int val)
{
    for(int i=li;i<=ls;i++)
        for(int j=ci;j<cs;j++)
            a[i][j]=val;
}

void dei(int n, int li, int ls, int ci, int cs)
{
    ifstream in("date.in");
    char aux;
   /* if(n==1)
        {
        cin>>aux;
        if(aux=='w')
            a[ci][li]=0;
        else if(aux=='b')
            a[ci][li];
        else cout<<"Matrice imposibil de construit";

        return;} */

    //for(int i=li;i<=ls;i++)
       // for(int j=ci;j<=ls;j++)
    while(in>>aux)
    {

        if(aux=='w' &&n==1)
        {
            a[li][ci]=0;
            return;
        }
        if(aux=='b'&&n==1)
        {
            a[li][ci]=1;
            return;
        }
        if(aux=='i')
        {
            dei(n/2,li,li/2+ls/2,ci/2+cs/2,cs); // cadranul 1
            dei(n/2,li,li/2+ls/2,ci,ci/2+cs/2); //2
            dei(n/2,li/2+ls/2,ls,ci,ci/2+cs/2); //3
            dei(n/2,li/2+ls/2,ls,ci/2+cs/2,cs); //4
            return;
        }
        if(aux=='b')
            fil(li,ls,ci,cs,1);

        if(aux=='w')
            fil(li,ls,ci,cs,0);
    }
}

int main()
{
    ifstream in ("date.in");
    ofstream out ("date.out");
    int n;
    in>>n;
    dei(n,0,n-1,0,n-1);
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
        out<<a[i][j];
        out<<endl;}
    return 0;
}
