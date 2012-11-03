#include "espbtrric.h"

EspBtrRic::EspBtrRic() : livello(0)
{ }

void EspBtrRic::ScendiLivello()
{
    livello++;
}

void EspBtrRic::SaliLivello()
{
    livello--;
}

bool EspBtrRic::SullaRadice()
{
    return livello == 0;
}

void Backtracking(EspBtrRic& esp)
{
    esp.ScendiLivello();
    esp.PrimoStessoLivello();
    do{
        bool fai_backtracking = esp.ViolaVincoli();
        if(esp.SoluzioneCompleta() && !fai_backtracking)
        {
            esp.OutputRispostaPositiva();
            return;
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
    esp.OutputRispostaNegativa();
}

