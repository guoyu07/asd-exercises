#include <QtCore/QCoreApplication>

#include <iostream>
#include <stdlib.h>
#include "risorsa.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i, N;

    cout << "Numero di opzioni disponibili: ";
    cin >> N;

    int in[N], fi[N];
    bool t[N];

    for(i=0; i<N; i++)
    {
        in[i] = rand() % N;
        fi[i] = in[i] + rand() % N;
    }

    RisorsaGreedy(N,in,fi,t);

    cout <<"Indice\tInizio\tFine" << endl << endl;

    for(i=0; i<N; i++)
        if(t[i])
            cout<< i+1 << "\t" << in[i] << "\t" << fi[i] <<  endl;


    return a.exec();
}
