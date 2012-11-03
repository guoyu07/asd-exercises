#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "espbtrbisaccia.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i, N, budget, sommac, sommap;

    cout << "Numero di opzioni disponibili: ";
    cin >> N;

    budget = N;
    int costi[N], profitti[N], ris[N];

    for(i=0; i<N; i++)
    {
        costi[i] = rand() % budget;
        profitti[i] = rand() % budget;
    }

    BisacciaBtr(N, profitti, costi, budget, ris);

    sommac = 0;
    sommap = 0;

    cout <<"Indice\tCosti\tProfitti" << endl;

    for(i=0; i<N; i++)
        if(ris[i])
        {
            cout<< i+1 << "\t" << costi[i] << "\t" << profitti[i] << endl;
            sommac += costi[i];
            sommap += profitti[i];
        }
    cout << "_ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "Somme\t" << sommac << "\t" << sommap << endl << endl;


    return a.exec();
}
