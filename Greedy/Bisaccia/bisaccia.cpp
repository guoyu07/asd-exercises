#include "bisaccia.h"

bool Bisaccia::operator<(Bisaccia b)
{
    return p_su_c > b.p_su_c;
}

void BisacciaGreedy(int n, int p[], int c[], int b, int x[])
{
    Bisaccia* bisaccia = new Bisaccia[n];
    int i;
    for(i=0; i<n; i++)
    {
        bisaccia[i].p_su_c = double(p[i])/c[i];
        bisaccia[i].indice = i;
    }
    MergeSort<Bisaccia>::Sort(bisaccia,n);
    for(i=0; i<n; i++)
    {
        if(c[bisaccia[i].indice] <= b)
        {
            x[bisaccia[i].indice] = 1;
            b = b - c[bisaccia[i].indice];
        }
        else
            x[bisaccia[i].indice] = 0;
    }
    delete [] bisaccia;
}
