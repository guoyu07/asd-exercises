#ifndef RISORSA_H
#define RISORSA_H

#include "../../DivideEtImpera/MergeSort/mergesort.h"

class Risorsa {
public:
    int fine;
    int indice;
    bool operator<(Risorsa);
};

void RisorsaGreedy(int,int[],int[],bool[]);

#endif // RISORSA_H
