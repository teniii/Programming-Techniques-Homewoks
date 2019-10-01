#include <iostream>

using namespace std;

struct domino
{
    int st,dr;
};

struct domino v[50],sol[50];
int poz[50];

void vecini(int n)
{
    int ind[10],coef=0,okp=1,ok;
    for(int i=0;i<n-1;i++)
    {
        if(v[i].st==v[i+1].st || v[i].st+v[i].st==6 || v[i].st==v[i+1].dr || v[i].st+v[i+1].dr==6) //daca stanga merge pusa undeva la cealalta piesa, adaugam 2
            poz[i]+=2;
        if(v[i].dr==v[i+1].dr || v[i].dr+v[i].dr==6 || v[i].dr==v[i+1].dr || v[i].dr+v[i+1].dr==6) //daca dreapta merge pusa, adaugam 1
            poz[i]+=1;

        if(poz[i]==0){ cout<<"Imposibil"; return;}

        if(i==n-2)
        {
            if(v[i-1].dr==v[i].st || v[i-1].dr+v[i].st==6) //am ajuns pe ultima pozitie si verificam cum sa fie afisata ultima piesa
                {
                    sol[i].st=v[i].st;
                    sol[i].dr=v[i].dr; //cout<<v[i].st<<" "<<v[i].dr;
                }
            else
                {
                    sol[i].st=v[i].dr;
                    sol[i].dr=v[i].st; //cout<<v[i].dr<<" "<<v[i].st;
                }
        }



        if(poz[i]==3)
        {
            ind[coef]=i; //memoram pozitiile unde merg ambele aranjari pt situatia de fundatura
            coef++;
        }

        if(poz[i]==1)
        {
            if(v[i+1].dr==v[i].st || v[i+1].dr+v[i].st==6)
                {
                    sol[i].st=v[i].st;
                    sol[i].dr=v[i].dr; //cout<<v[i].st<<" "<<v[i].dr;
                }
            else if(v[i+1].st==v[i].dr || v[i+1].st+v[i].dr==6 )
                {
                    sol[i].st=v[i].dr;
                    sol[i].dr=v[i].st; //cout<<v[i].dr<<" "<<v[i].st;
                }
        }
        if (poz[i]==2)
        {
            if(v[i+1].dr==v[i].st || v[i+1].dr+v[i].st==6)
                {
                    sol[i].st=v[i].st;
                    sol[i].dr=v[i].dr; //cout<<v[i].st<<" "<<v[i].dr;
                }
            else if(v[i+1].st==v[i].dr || v[i+1].st+v[i].dr==6 )
                {
                    sol[i].st=v[i].dr;
                    sol[i].dr=v[i].st; //cout<<v[i].dr<<" "<<v[i].st;
                }
        }
               /* else {
                    i=ind[coef]-1; //reluam procesul de la ultimul indice ce accepta ambele pozitionari
                    coef--;
                    poz[i+1]--;
                }*/

        }
        sol[n-1].st=v[n-1].st;
        sol[n-1].dr=v[n-1].dr;
        for(int i=0;i<n;i++)
        {
            cout<<sol[i].st<<" "<<sol[i].dr<<" ";
        }
    }




int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i].st>>v[i].dr;
    vecini(n);

    return 0;
}

/*
int verif(int a, int b)
{
    if((v[a].st==v[b].st || v[a].st+v[b].st==6)&&(v[a].st==v[b].dr || v[a].st+v[b].dr==6))
        pos[a].st=3;
    else if (v[a].st==v[b].st || v[a].st+v[b].st==6)
             pos[a].st=1;
    else if (v[a].st==v[b].dr || v[a].st+v[b].dr==6)
            pos[a].st=2;
    else pos[a].st=-1;

    if((v[a].dr==v[b].st || v[a].dr+v[b].st==6)&&(v[a].dr==v[b].dr || v[a].dr+v[b].dr==6))
        pos[a].dr=3;
    else if (v[a].dr==v[b].st || v[a].dr+v[b].st==6)
             pos[a].dr=1;
    else if (v[a].dr==v[b].dr || v[a].dr+v[b].dr==6)
            pos[a].dr=2;
    else pos[a].dr=-1;
}

void solutie()
{

    if(pos[0].dr==-1)
    {
        sol[0].dr=v[0].st;
        sol[0].st=v[0].dr;
    }

    for(int i=0;i<n-1;i++)
    {
        if(sol[i].dr==-1 && sol[i].st==-1)
        {
            cout<<"Imposibil";
            return;
        }
        if(pos[i].dr==2)
        {
            sol[i].dr=v[i].dr;
            sol[i].st=v[i].st;
            sol[i+1].dr=v[i+1].st;
            sol[i+1].st=v[i+1].dr;
        }


    }
}
*/
