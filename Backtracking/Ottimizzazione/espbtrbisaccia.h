#ifndef OTTIMIZZAZIONE_H
#define OTTIMIZZAZIONE_H

#include "espbtrott.h"

class  EspBtrBisaccia : public EspBtrOtt {
public:
    EspBtrBisaccia(int, int*, int*, int, int*);
    ~EspBtrBisaccia();
    bool ViolaVincoli();
    void OutputRispostaPositiva();
    void OutputRispostaNegativa();
    void PrimoStessoLivello();
    bool ProssimoStessoLivello();
    bool SoluzioneCompleta();
    bool NonMiglioraOttimoCorrente();
    void InizializzaOttimoCorrente();
    void AggiornaOttimoCorrente();

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

void BisacciaBtr(int,int*,int*,int,int*);

#endif // OTTIMIZZAZIONE_H
