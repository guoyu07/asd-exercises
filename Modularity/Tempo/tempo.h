#ifndef TEMPO_H
#define TEMPO_H

#include <iostream>

using namespace std;

class Tempo
{
    friend Tempo operator+(Tempo, Tempo);
    friend Tempo operator-(Tempo, Tempo);
    friend bool operator==(Tempo, Tempo);
    friend bool operator<(Tempo, Tempo);
    friend bool operator>(Tempo, Tempo);

public:
    Tempo();
    Tempo(int);
    Tempo(int, int);
    Tempo(int, int, int);

    int Ore();
    int Minuti();
    int Secondi();

protected:
    long int secondi;
};

ostream& operator<<(ostream&, Tempo);
Tempo operator+(Tempo, Tempo);
Tempo operator-(Tempo, Tempo);
bool operator==(Tempo, Tempo);
bool operator<(Tempo, Tempo);
bool operator>(Tempo, Tempo);

#endif // TEMPO_H
