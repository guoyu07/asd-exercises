#include "telefonata.h"

Telefonata::Telefonata() : numero(0)
{ }

Telefonata::Telefonata(DataTempo i, DataTempo f, long int n) : inizio(i), fine(f), numero(n)
{ }

DataTempo Telefonata::Inizio()
{
    return inizio;
}

DataTempo Telefonata::Fine()
{
    return fine;
}

long int Telefonata::Numero()
{
    return numero;
}

float Telefonata::Costo()
{
    DataTempo aux = fine - inizio;
    return ((float)(aux.Ore()*60 + aux.Minuti()) * tariffa)/100;
}

ostream& operator<<(ostream& os, Telefonata t)
{
    return os << "Telefonata a: " << t.Numero() << endl
                 << "\tInizio " << t.Inizio() << endl
                    << "\tFine " << t.Fine() << endl
                       << "\tCosto " << t.Costo() << endl;
}

bool operator==(Telefonata t1, Telefonata t2)
{
    return t1.Inizio() == t2.Inizio() && t1.Fine() == t2.Fine() && t1.Numero() == t2.Numero();
}
