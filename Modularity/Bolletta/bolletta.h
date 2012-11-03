#ifndef BOLLETTA_H
#define BOLLETTA_H

#include <iostream>
#include "../Telefonata/telefonata.h"

using namespace std;

class Bolletta
{
    friend ostream& operator<<(ostream&, Bolletta);

public:
    Bolletta();
    Bolletta(const Bolletta&);
    ~Bolletta();
    bool Vuota();
    void MettiTelefonata(Telefonata);
    void TogliTelefonata(Telefonata);
    Telefonata TogliUna();

    Bolletta& operator=(const Bolletta&);

private:
    struct elemento
    {
        Telefonata info;
        elemento* next;
    };
    elemento* primo;

    elemento* Copia(elemento*);
    void Distruggi(elemento*);
};

ostream& operator<<(ostream&, Bolletta);
Tempo DurataTotale(Bolletta);
float CostoTotale(Bolletta);
Bolletta TutteLeChiamateA(long int, Bolletta&);

#endif // BOLLETTA_H
