#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "datatempo.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int i=0; i<20; i++)
    {
        DataTempo dt(rand()%2000+1000, rand()%12+1, rand()%31, rand()%24, rand()%60,rand()%60);
        cout << dt << endl;
    }

    return a.exec();
}
