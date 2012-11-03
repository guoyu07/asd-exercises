#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "listasemplice.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ListaSemplice<int> lista;

    for(int i=0; i<20; i++)
        lista.Inserisci(rand()%40);

    cout << lista << endl;

    return a.exec();
}

