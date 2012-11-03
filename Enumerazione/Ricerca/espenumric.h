#ifndef ESPENUMRIC_H
#define ESPENUMRIC_H

class EspEnumRic
{
public:
    virtual bool Ammissibile() = 0;
    virtual void OutputRispostaPositiva() = 0;
    virtual void OutputRispostaNegativa() = 0;
    virtual void Primo() = 0;
    virtual void Successore() = 0;
    virtual bool Ultimo() = 0;
};

void Enumerazione(EspEnumRic&);

#endif // ESPENUMRIC_H
