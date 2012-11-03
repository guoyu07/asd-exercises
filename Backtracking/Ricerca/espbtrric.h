#ifndef ESPBTRRIC_H
#define ESPBTRRIC_H

class EspBtrRic {
public:
    EspBtrRic();
    virtual bool ViolaVincoli() = 0;
    virtual void OutputRispostaPositiva() = 0;
    virtual void OutputRispostaNegativa() = 0;
    virtual void PrimoStessoLivello() = 0;
    virtual bool ProssimoStessoLivello() = 0;
    virtual bool SoluzioneCompleta() = 0;
    virtual void ScendiLivello();
    virtual void SaliLivello();
    virtual bool SullaRadice();

protected:
    int livello;
};

void Backtracking(EspBtrRic&);

#endif // ESPBTRRIC_H
