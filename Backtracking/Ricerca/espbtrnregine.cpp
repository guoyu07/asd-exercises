#include <stdlib.h>
#include "espbtrnregine.h"

EspBtrNregine::EspBtrNregine(int in,char** out) : n(in), scacchiera(out)
{
    s = new int[n+1];
}

EspBtrNregine::~EspBtrNregine()
{
    delete [] s;
}

bool EspBtrNregine::SoluzioneCompleta()
{
    return livello == n;
}

void EspBtrNregine::PrimoStessoLivello()
{
    s[livello] = 1;
}

bool EspBtrNregine::ProssimoStessoLivello()
{
    s[livello] = s[livello] + 1;
    return s[livello] <= n;
}

bool EspBtrNregine::ViolaVincoli()
{
    for(int i=1; i<livello; i++)
        if((s[livello] == s[i]) || abs(s[livello]-s[i]) == abs(livello-i))
            return true;
    return false;
}

void EspBtrNregine::OutputRispostaPositiva()
{
    int i;
    for(i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scacchiera[i][j] = '-';
    for(i=1; i<=n; i++)
        scacchiera[i-1][s[i]-1] = 'Q';
}

void EspBtrNregine::OutputRispostaNegativa()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scacchiera[i][j] = '-';
}

void NRegineBtr(int n, char** scacchiera)
{
    EspBtrNregine istanza(n,scacchiera);
    Backtracking(istanza);
}
