#include <stdio.h>
#include <stdlib.h>

void afisareText (char **S, int N, int L)
{
    printf ("\n");
    int i,j;
    for ( i=0; i<N; i++)
    {
        for ( j=0; j<L; j++)
            printf ("%c", S[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

void afisareMat (int **V, int N, int L)
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<L; j++)
            printf ("%d", V[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

int rauMaxim (char **S, int N, int L)
{
    int **V = (int **)malloc(N * sizeof(int **)), i, j, lungimeM = 1, sw,drum=0;

    for (i=0; i<N; i++)
        V[i] = (int *)malloc(L * sizeof(int));

    for (i=0; i<N; i++)
        for (j=0; j<L; j++)
        {
            if (S[i][j] != ' ')     // daca nu suntem pe rau e 0;
            {
                V[i][j] = 0;
                continue;
            }

                if (i == 0)         // daca suntem pe prima linie si suntem pe un rau e 1.
                {
                    V[i][j] = 1;
                    drum=1;
                    continue;
                }

                    sw = 0;
                    if (V[i-1][j-1] > 0 && j-1 >= 0) // daca elementul din stanga sus e parte din rau si exista in matrice.
                    {   V[i][j] = V[i-1][j-1] + 1;
                        if(drum<V[i][j])
                            drum=V[i][j];
                        continue;
                        }

                    if (V[i-1][j] > 0)              // daca elementul de sus e parte din rau.
                    {   V[i][j] = V[i-1][j] + 1;
                        if(drum<V[i][j])
                            drum=V[i][j];
                        continue;
                        }

                    if (V[i-1][j+1]> 0 && j < L-1) // daca elementul din dreapta sus e parte din rau si exista in matrice.
                    {
                        V[i][j] = V[i-1][j+1] + 1;
                        if(drum<V[i][j])
                            drum=V[i][j];
                        continue;
                    }

                                                    // altfel e 1.
                        V[i][j] = 1;
                        if(drum<V[i][j])
                            drum=V[i][j];
                }



    afisareMat(V,N,L);
    for (i=0; i<N; i++)
        for (j=0; j<L; j++)
            if (V[i][j] > lungimeM)
                lungimeM = V[i][j];

    if (lungimeM == 1)
        printf ("NU EXISTA! \n");
    else
        printf ("Lungimea maxima a unui rau este de: %d \n", lungimeM);

    free (V);
    return drum;
}

int main()
{
    int L, N;
    char *S[] = {"PROBLEMA DE LA EXAMEN", "NU MI SE PARE FOARTE ", "GREU DE REZOLVAT IN  ", "TIMPUL ACORDAT       "};

    printf ("Introduceti L si N: ");
    scanf ("%d %d", &L, &N);

    afisareText(S,N,L);
    printf("\n\n Drumul facut de mine este =%d", rauMaxim (S,N,L));

    return 0;
}
