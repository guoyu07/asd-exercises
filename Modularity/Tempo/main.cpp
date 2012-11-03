#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "tempo.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int i=0; i<20; i++)
    {
        Tempo t(rand()%24, rand()%60,rand()%60);
        cout << t << endl;
    }

    return a.exec();
}
