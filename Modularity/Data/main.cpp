#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "data.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int i=0; i<20; i++)
    {
        Data d(rand()%2000+1000, rand()%12+1, rand()%31);
        cout << d << endl;
    }

    return a.exec();
}
