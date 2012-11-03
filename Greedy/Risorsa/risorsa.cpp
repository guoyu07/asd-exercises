#include "risorsa.h"

bool Risorsa::operator<(Risorsa r)
{
    return fine < r.fine;
}

void RisorsaGreedy(int n, int in[], int fi[], bool a[])
{
    Risorsa* risorsa = new Risorsa[n];
    int i;
    for(i=0; i<n; i++)
    {
        risorsa[i].fine = fi[i];
        risorsa[i].indice = i;
    }
    MergeSort<Risorsa>::Sort(risorsa,n);
    a[risorsa[0].indice] = true;
    int ultimo_scelto = 0;
    for(i=1; i<n; i++)
        if(in[risorsa[i].indice] >= fi[risorsa[ultimo_scelto].indice])
        {
            a[risorsa[i].indice] = true;
            ultimo_scelto = i;
        }
        else
            a[risorsa[i].indice] = false;
    delete [] risorsa;
}
