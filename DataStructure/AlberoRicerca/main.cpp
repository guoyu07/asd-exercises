#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "alberoricerca.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AlberoRicerca<int> alb;

    for(int i=0; i<20; i++)
        alb.Inserisci(rand()% 40);

    cout << alb;

    return a.exec();
}
