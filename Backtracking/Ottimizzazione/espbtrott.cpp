#include "espbtrott.h"

EspBtrOtt::EspBtrOtt() : livello(0)
{ }

void EspBtrOtt::ScendiLivello()
{
    livello++;
}

void EspBtrOtt::SaliLivello()
{
    livello--;
}

bool EspBtrOtt::SullaRadice()
{
    return livello == 0;
}

void BacktrackingOtt(EspBtrOtt& esp)
{
    bool trovata_una_soluzione = false;
    esp.ScendiLivello();
    esp.PrimoStessoLivello();
    do{
        bool fai_backtracking;
        if(!trovata_una_soluzione)
            fai_backtracking = esp.ViolaVincoli();
        else
            fai_backtracking = esp.ViolaVincoli() || esp.NonMiglioraOttimoCorrente();
        if(esp.SoluzioneCompleta() && !fai_backtracking)
        {
            if(!trovata_una_soluzione)
            {
                esp.InizializzaOttimoCorrente();
                trovata_una_soluzione = true;
            }
            else
                esp.AggiornaOttimoCorrente();
            fai_backtracking = true;
        }
        if(fai_backtracking)
        {
            do{
                if(esp.ProssimoStessoLivello())
                    fai_backtracking = false;
                else
                    esp.SaliLivello();
            }while(fai_backtracking && !esp.SullaRadice());
        }
        else
        {
            esp.ScendiLivello();
            esp.PrimoStessoLivello();
        }
    }while(!esp.SullaRadice());
    if(trovata_una_soluzione)
        esp.OutputRispostaPositiva();
    else
        esp.OutputRispostaNegativa();
}
