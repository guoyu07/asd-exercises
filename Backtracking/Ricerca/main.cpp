#include <QtCore/QCoreApplication>
#include <iostream>

#include "espbtrnregine.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n,i,j;
    cout << "Dimensione della scacchiera: ";
    cin >> n;

    char** scacchieraNperN = new char*[n];
    for(i=0; i<n; i++)
        scacchieraNperN[i] = new char[n];

    NRegineBtr(n,scacchieraNperN);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout << scacchieraNperN[i][j];
        cout << endl;
    }

    return a.exec();
}
