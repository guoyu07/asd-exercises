#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "insiemessr.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Insieme<int> ins;

    for(int i=0; i<20; i++)
        ins.Inserisci(rand()%40);

    cout << ins;

    return a.exec();
}
