#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int j;
    int val;
}elem;

struct matrice
{
    int l;
    int c;
    int elem_nenule;
    elem el[elem_nenule];

};

struct matrice inmultire (struct matrice *a1, struct matrice *a2)
{
    struct matrice rez;
    int i,j,k,l,poz=0;
    for(i=0;i<a1->l;i++)
        for(j=0;j<a2->c;j++)
    {
        for(k=0;k<a2->c;k++)
        {
            for(l=0;l<a2->c;l++)
            {
                if(a1->el[k].j==a2->el[l].i)
                    rez.el[poz].val+=a1->el[k].val*a1->el[l].val;
            }


            p[i][j]=p[i][j]+(a[i][k]*b[k][j]);
        }

    }
}

int main()
{
    int n1,n2;
    printf("Introduceti numarul de elemente nenule ale primei matrici:");
    scanf("%d", &n1);

    elem vect_prima_mat[n1]={0};
    for(i=0;i<n1;i++)
    {
        printf("introduceti linia, coloana si valoarea:");
        scanf("%d %d %d", &p[i].i, &p[i].j, &p[i].val);
    }

    printf("Introduceti numarul de elemente nenule ale celei de-a doua matrice:");
    scanf("%d", &n2);

    elem vect_prima_mat[n2]={0};
    for(i=0;i<n2;i++)
    {
        printf("introduceti linia, coloana si valoarea:");
        scanf("%d %d %d", &p[i].i, &p[i].j, &p[i].val);
    }



    return 0;
}
