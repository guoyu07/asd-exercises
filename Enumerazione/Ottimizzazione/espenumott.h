#ifndef ESPENUMOTT_H
#define ESPENUMOTT_H

class EspEnumOtt
{
public:
    virtual bool Ammissibile() = 0;
    virtual void Primo() = 0;
    virtual void Successore() = 0;
    virtual bool Ultimo() = 0;
    virtual void OutputRispostaPositiva() = 0;
    virtual void OutputRispostaNegativa() = 0;
    virtual void InizializzaOttimoCorrente() = 0;
    virtual void AggiornaOttimoCorrente() = 0;
    virtual bool MiglioraOttimoCorrente() = 0;
};

void EnumerazioneOtt(EspEnumOtt&);

#endif // ESPENUMOTT_H
