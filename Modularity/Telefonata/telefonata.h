#ifndef TELEFONATA_H
#define TELEFONATA_H

#include <iostream>
#include "../../Inheritance/DataTempo/datatempo.h"

using namespace std;

class Telefonata
{
public:
    Telefonata();
    Telefonata(DataTempo, DataTempo, long int);

    DataTempo Inizio();
    DataTempo Fine();
    long int Numero();
    float Costo();

private:
    DataTempo inizio, fine;
    long int numero;
    static const int tariffa = 10;
};

ostream& operator<<(ostream&, Telefonata);
bool operator==(Telefonata, Telefonata);

#endif // TELEFONATA_H
