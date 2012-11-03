#ifndef ESPENUMBISACCIA_H
#define ESPENUMBISACCIA_H

#include "espenumott.h"

class EspEnumBisaccia : public EspEnumOtt
{
public:
    EspEnumBisaccia(int,int*,int*,int,int*);
    ~EspEnumBisaccia();

    bool Ammissibile();
    void Primo();
    void Successore();
    bool Ultimo();
    void OutputRispostaPositiva();
    void OutputRispostaNegativa();
    void InizializzaOttimoCorrente();
    void AggiornaOttimoCorrente();
    bool MiglioraOttimoCorrente();

private:
    int n;
    int* profitti;
    int* costi;
    int budget;
    int* scelta;
    int misura;
    int* scelta_ottima;
    int misura_ottima;
};

void BisacciaEnum(int,int*,int*,int,int*);

#endif // ESPENUMBISACCIA_H
