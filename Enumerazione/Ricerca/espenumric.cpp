#include "espenumric.h"

void Enumerazione(EspEnumRic& esp)
{
    for(esp.Primo(); !esp.Ultimo(); esp.Successore())
        if(esp.Ammissibile())
        {
            esp.OutputRispostaPositiva();
            return;
        }
    esp.OutputRispostaNegativa();
}
