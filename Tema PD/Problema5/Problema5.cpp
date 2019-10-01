#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int m,n,nr_p,dmax,imax,jmax;
    int a[100][100], adia[100][100];    

    ifstream fin("m.in");
    fin>>m>>n;

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            fin>>a[i][j];
        }
    }

    for (int k=0;k<min(m,n);k++)
    {
        for (int i=m-1-k;i>=0;i--) {
            int j = n-1-k;
            if (a[i][j]==0) adia[i][j] = 1;
            if (i!=m-1 && j!=n-1)
            {
                adia[i][j] += min(adia[i+1][j],min(adia[i][j+1],adia[i+1][j+1]));
                if (adia[i][j]>1) nr_p+=adia[i][j]-1;
            }
            if (adia[i][j]>dmax)
            {
                dmax = adia[i][j];
                imax = i;
                jmax = j;
            }
        }
        for (int j=n-1-k-1;j>-1;j--) {
            int i = m-1-k;
            if (a[i][j]==0) adia[i][j] = 1;
            if (i!=m-1 && j!=n-1)
            {
                adia[i][j] += min(adia[i+1][j],min(adia[i][j+1],adia[i+1][j+1]));
                if (adia[i][j]>1) nr_p++;
            }
            if (adia[i][j]>dmax)
            {
                dmax = adia[i][j];
                imax = i;
                jmax = j;
            }
        }
    }
    cout<<dmax<<" "<<imax<<" "<<jmax<<endl;
    cout<<"Numar patrate="<<nr_p;


    return 0;
}
