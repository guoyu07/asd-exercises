#include "tempo.h"

Tempo::Tempo() : secondi(0)
{ }

Tempo::Tempo(int o)
{
    if(o < 0 || o > 24)
        secondi = 0;
    else
        secondi = long(o) * 3600;
}

Tempo::Tempo(int o, int m)
{
    if(o < 0 || o > 23 || m < 0 || m > 59)
        secondi = 0;
    else
        secondi = long(o) * 3600 + m * 60;
}

Tempo::Tempo(int o, int m, int s)
{
    if(o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        secondi = 0;
    else
        secondi = long(o) * 3600 + m * 60 + s;
}

int Tempo::Ore()
{
    return secondi / 3600;
}

int Tempo::Minuti()
{
    return (secondi - ( secondi / 3600) * 3600) / 60;
}

int Tempo::Secondi()
{
    return (secondi % 60);
}

ostream& operator<<(ostream& os, Tempo t)
{
    return os << t.Ore() << ':' << t.Minuti() << ':' << t.Secondi();
}

Tempo operator+(Tempo t1, Tempo t2)
{
    Tempo aux;
    aux.secondi = (t1.secondi + t2.secondi) % 86400;
    return aux;
}

Tempo operator-(Tempo t1, Tempo t2)
{
    Tempo aux;
    if ( t1 < t2 )
        aux.secondi = 86400 + t1.secondi - t2.secondi;
    else
        aux.secondi = t1.secondi - t2.secondi;

    return aux;
}

bool operator==(Tempo t1, Tempo t2)
{
    return t1.secondi == t2.secondi;
}

bool operator<(Tempo t1, Tempo t2)
{
    return t1.secondi < t2.secondi;
}

bool operator>(Tempo t1, Tempo t2)
{
    return t1.secondi > t2.secondi;
}
