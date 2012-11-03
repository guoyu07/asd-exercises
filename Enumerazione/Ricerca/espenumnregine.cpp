#include <stdlib.h>
#include "espenumnregine.h"

EspEnumNregine::EspEnumNregine(int in, char** out)
{
    n = in;
    scacchiera = out;
    ultimo = false;
    s = new int[n+1];
}

EspEnumNregine::~EspEnumNregine()
{
    delete [] s;
}

bool EspEnumNregine::Ammissibile()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<=n; j++)
            if(abs(s[i]-s[j]) == abs(i-j))
                return false;
    return true;
}

void EspEnumNregine::OutputRispostaPositiva()
{
    int i;
    for(i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scacchiera[i][j] = '-';
    for(i=1; i<=n; i++)
        scacchiera[i-1][s[i]-1] = 'Q';
}

void EspEnumNregine::OutputRispostaNegativa()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scacchiera[i][j] = '-';
}

void EspEnumNregine::Primo()
{
    for(int i=1; i<=n; i++)
        s[i] = i;
}

void EspEnumNregine::Successore()
{
    int k = n-1;
    while(k>=1 && s[k]>s[k+1])
        k--;
    if(k < 1)
    {
        ultimo = true;
        return;
    }
    int p = k;
    while(p<=n-1 && s[p+1]>s[k])
        p++;
    Scambia(s[k],s[p]);
    for(int h=1; h<=(n-k)/2; h++)
        Scambia(s[k+h],s[n-h+1]);
}

void Scambia(int& i,int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

bool EspEnumNregine::Ultimo()
{
    return ultimo;
}

void NRegineEnum(int n, char ** scacchiera)
{
    EspEnumNregine istanza(n,scacchiera);
    Enumerazione(istanza);
}
