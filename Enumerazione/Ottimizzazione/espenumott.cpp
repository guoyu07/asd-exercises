#include "espenumott.h"

void EnumerazioneOtt(EspEnumOtt& esp)
{
    bool esiste_ottimo_corrente = false;
    for (esp.Primo(); !esp.Ultimo(); esp.Successore())
        if(esp.Ammissibile())
        {
            if(!esiste_ottimo_corrente)
            {
                esp.InizializzaOttimoCorrente();
                esiste_ottimo_corrente = true;
            }
            else
                if(esp.MiglioraOttimoCorrente())
                    esp.AggiornaOttimoCorrente();
        }
    if(esiste_ottimo_corrente)
        esp.OutputRispostaPositiva();
    else
        esp.OutputRispostaNegativa();

}
