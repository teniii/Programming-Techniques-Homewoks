#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f= fopen("date.in", "r");
    char x;
    int i,n, v[26]={0},max=-1;

    while(!feof(f))
    {
        fscanf(f, "%c", &x);
        v[(int)x-'a']++;
    }
    fclose(f);

    for(i=0;i<26;i++)
        {
            if(v[i]>max) max=v[i];
        }

    for(i=0;i<26;i++)
    {
        if(v[i]==max)
            printf("%c ", (char)(i+'a') );
    }
    return 0;
}
