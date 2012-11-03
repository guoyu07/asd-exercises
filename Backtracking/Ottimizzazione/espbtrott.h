#ifndef ESPBTROTT_H
#define ESPBTROTT_H

class EspBtrOtt
{
public:
    EspBtrOtt();
    virtual bool ViolaVincoli() = 0;
    virtual void OutputRispostaPositiva() = 0;
    virtual void OutputRispostaNegativa() = 0;
    virtual void PrimoStessoLivello() = 0;
    virtual bool ProssimoStessoLivello() = 0;
    virtual bool SoluzioneCompleta() = 0;
    virtual bool NonMiglioraOttimoCorrente() = 0;
    virtual void InizializzaOttimoCorrente() = 0;
    virtual void AggiornaOttimoCorrente() = 0;
    virtual void ScendiLivello();
    virtual void SaliLivello();
    virtual bool SullaRadice();

protected:
    int livello;
};

void BacktrackingOtt(EspBtrOtt&);

#endif // ESPBTROTT_H
