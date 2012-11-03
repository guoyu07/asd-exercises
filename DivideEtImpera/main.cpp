#include <QtCore/QCoreApplication>

#include <iostream>
#include <stdlib.h>

#include "MergeSort/mergesort.h"
#include "MinMax/minmax.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i, N = 100, min, max, v[N];

    for(i=0; i<N; i++)
        v[i] = rand() % 500;

    MinMax<int>::Calculate(v,N,min,max);

    MergeSort<int>::Sort(v,N);

    for(i=0; i<N; i++)
        cout << v[i] << " ";

    cout << endl << "Min: " << min << " Max: " << max;

    return a.exec();
}
