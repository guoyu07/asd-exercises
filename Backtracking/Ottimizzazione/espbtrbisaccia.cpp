#include "espbtrbisaccia.h"

EspBtrBisaccia::EspBtrBisaccia(int i_n, int* i_p, int* i_c, int i_b, int* o_r) : n(i_n) , profitti(i_p) , costi(i_c) , budget(i_b), scelta_ottima(o_r)
{
    scelta = new int[n+1];
}

EspBtrBisaccia::~EspBtrBisaccia()
{
    delete [] scelta;
}

bool EspBtrBisaccia::ViolaVincoli()
{
    int costo_corrente = 0;
    for(int i=0; i<livello; i++)
        costo_corrente += costi[i]*scelta[i];
    return costo_corrente > budget;
}

void EspBtrBisaccia::OutputRispostaPositiva()
{ }

void EspBtrBisaccia::OutputRispostaNegativa()
{ }

void EspBtrBisaccia::PrimoStessoLivello()
{
    scelta[livello-1] = 0;
}

bool EspBtrBisaccia::ProssimoStessoLivello()
{
    if(scelta[livello-1] == 0)
    {
        scelta[livello-1] = 1;
        return true;
    }
    else
        return false;
}

bool EspBtrBisaccia::SoluzioneCompleta()
{
    return livello == n;
}

bool EspBtrBisaccia::NonMiglioraOttimoCorrente()
{
    misura = 0;
    int i;
    for(i=0; i<livello; i++)
        misura += profitti[i]*scelta[i];
    int profitto_massimo = misura;
    for(; i<n; i++)
        profitto_massimo += profitti[i];
    return profitto_massimo <= misura_ottima;
}

void EspBtrBisaccia::InizializzaOttimoCorrente()
{
    misura_ottima = 0;
    for(int i=0; i<n; i++)
    {
        scelta_ottima[i] = scelta[i];
        misura_ottima += profitti[i]*scelta[i];
    }
}

void EspBtrBisaccia::AggiornaOttimoCorrente()
{
    for(int i=0; i<n; i++)
        scelta_ottima[i] = scelta[i];
    misura_ottima = misura;
}

void BisacciaBtr(int n, int* p, int* c, int b, int* r)
{
    EspBtrBisaccia istanza(n,p,c,b,r);
    BacktrackingOtt(istanza);
}
