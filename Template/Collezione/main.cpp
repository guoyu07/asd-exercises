#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "collezione.h"
#include "../../Modularity/Telefonata/telefonata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Collezione<Telefonata> c;

    for(int i=0; i<20; i++)
    {
        DataTempo in(rand()%2000+1000, rand()%12+1, rand()%31, rand()%24, rand()%60,rand()%60);
        DataTempo fi = in + Tempo(rand()%24, rand()%60, rand()%60);
        Telefonata t(in,fi,rand());
        c.Metti(t);
    }

    cout << c;

    return a.exec();
}
