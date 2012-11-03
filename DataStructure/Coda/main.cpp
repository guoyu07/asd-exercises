#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "coda.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Coda<int> coda;

    for(int i=0; i<20; i++)
        coda.InCoda(rand()%40);

    cout << coda;

    return a.exec();
}
