#ifndef RICERCA_H
#define RICERCA_H

#include "espbtrric.h"

class  EspBtrNregine : public EspBtrRic {
public:
    EspBtrNregine(int,char**);
    ~EspBtrNregine();
    bool SoluzioneCompleta();
    void PrimoStessoLivello();
    bool ProssimoStessoLivello();
    bool ViolaVincoli();
    void OutputRispostaPositiva();
    void OutputRispostaNegativa();

private:
    int n;
    char** scacchiera;
    int* s;
};

void NRegineBtr(int, char**);

#endif // RICERCA_H
