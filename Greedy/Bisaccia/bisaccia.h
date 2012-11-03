#ifndef BISACCIA_H
#define BISACCIA_H

#include "../../DivideEtImpera/MergeSort/mergesort.h"

class Bisaccia {
public:
    double p_su_c;
    int indice;
    bool operator<(Bisaccia);
};

void BisacciaGreedy(int, int[], int[], int, int[]);

#endif // BISACCIA_H
