#ifndef ESPENUMNREGINE_H
#define ESPENUMNREGINE_H

#include "espenumric.h"

class EspEnumNregine : public EspEnumRic
{
public:
    EspEnumNregine(int,char**);
    ~EspEnumNregine();

    void Primo();
    void Successore();
    bool Ultimo();
    bool Ammissibile();
    void OutputRispostaPositiva();
    void OutputRispostaNegativa();

private:
    int n;
    char** scacchiera;
    int* s;
    bool ultimo;
};

void NRegineEnum(int,char**);
void Scambia(int&,int&);

#endif // ESPENUMNREGINE_H
