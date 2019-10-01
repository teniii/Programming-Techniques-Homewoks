#include <iostream>
#include <fstream>

using namespace std;

//ifstream fin ("rau.in");
FILE *f=fopen("rau.in","r+");

int l,n;
int v[100][100];
char a[100][100];

int functie()
{
    int lung=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(a[i][j]!=' ')
            {
                v[i][j]=0;continue;
            }
            //cout<<lung<<endl;
            if(i==0)  //daca ajungem aici inseamna ca avem space
            {
                v[i][j]=1;
                lung=1;continue;
            }

            if(j>0 && v[i-1][j-1]!= 0)
            {
                v[i][j]=v[i-1][j-1] +1;
                if(v[i][j]>lung)
                    lung=v[i][j];
                continue;
            }

            if( v[i-1][j]!= 0)
            {
                v[i][j]=v[i-1][j] +1;
                if(v[i][j]>lung)
                    lung=v[i][j];
                continue;
            }

            if(j<l-1 && v[i-1][j+1]!= 0)
            {
                v[i][j]=v[i-1][j+1] +1;
                if(v[i][j]>lung)
                    lung=v[i][j];
                continue;
            }

            v[i][j]=1; //se ajunge aici doar daca nu are un rau deasupra
            if(v[i][j]>lung)
                    lung=v[i][j];
        }
    }
    return lung;
}

int main()
{
    fscanf(f,"%d %d",&l,&n);

    for(int i=0;i<=n;i++)
        fgets(a[i],l+2,f);
    //for(int i=0;i<n+2;i++)
       // printf("%s \n",a[i]);

    cout<<"Lungimea maxima a unui rau este: "<<functie()<<endl;
    /* for(int i=1;i<=n;i++)
    {
        for(int j=0;j<l;j++)
            cout<<v[i][j];
        cout<<endl;
    } */

    return 0;
}
