#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "pila.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Pila<int> pila;

    for(int i=0; i<20; i++)
        pila.Push(rand()%40);

    cout << pila;

    return a.exec();
}
