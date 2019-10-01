#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nr_leg;
    char nume[30];

}stud;

void codif(stud *s, int n, int c, int *v)
{
    int i,j=0;
    for (i=0;i<n;i++)
    {
        a[i]=v[i].nr_leg^c;
        printf("Nr %d codificat este %d", v[i].nr_leg, a[i]);
    }
}

void afisare ( int a, FILE *f)
{
    int ca=a,k=0, i, v[15];
    while (ca)
    {
        v[k]=ca%2;
        ca/=2;
        k++;
    }

    for(i=k-1;i>-1;i--)
    {
        fprintf("%d", v[i]);
    }
}

int main()
{
    int i,j,n;
    scanf("%d", &n);
    stud v[n];
    int a[n]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d ", &v[i].nr_leg);
        scanf("%s ", &v[i].nume);
    }


    return 0;
}
