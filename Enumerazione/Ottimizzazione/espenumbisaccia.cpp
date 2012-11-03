#include "espenumbisaccia.h"

EspEnumBisaccia::EspEnumBisaccia(int i_n, int* i_p, int* i_c, int i_b, int* o_r) : n(i_n) , profitti(i_p) , costi(i_c) , budget(i_b), scelta_ottima(o_r)
{
    scelta = new int[n+1];
}

EspEnumBisaccia::~EspEnumBisaccia()
{
    delete [] scelta;
}

bool EspEnumBisaccia::Ammissibile()
{
    int somma = 0;
    for(int i=0; i<n; i++)
        somma += costi[i]*scelta[i];
    return somma <= budget;
}

void EspEnumBisaccia::Primo()
{
    for(int i=0; i<=n; i++)
        scelta[i] = 0;
}

void EspEnumBisaccia::Successore()
{
    int i = 0;
    while(scelta[i] == 1)
    {
        scelta[i] = 0;
        i++;
    }
    scelta[i] = 1;
}

bool EspEnumBisaccia::Ultimo()
{
    return scelta[n];
}

void EspEnumBisaccia::OutputRispostaPositiva()
{ }

void EspEnumBisaccia::OutputRispostaNegativa()
{ }

void EspEnumBisaccia::InizializzaOttimoCorrente()
{
    misura_ottima = 0;
    for(int i=0; i<n; i++)
    {
        scelta_ottima[i] = scelta[i];
        misura_ottima += profitti[i]*scelta[i];
    }
}

void EspEnumBisaccia::AggiornaOttimoCorrente()
{
    for(int i=0; i<n; i++)
        scelta_ottima[i] = scelta[i];
    misura_ottima = misura;
}

bool EspEnumBisaccia::MiglioraOttimoCorrente()
{
    misura = 0;
    for(int i=0; i<n; i++)
        misura += profitti[i]*scelta[i];
    return misura > misura_ottima;
}

void BisacciaEnum(int n, int* p, int* c, int b, int* r)
{
    EspEnumBisaccia istanza(n,p,c,b,r);
    EnumerazioneOtt(istanza);
}
