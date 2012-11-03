#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "alberobinario.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AlberoBinario<int> alb;

    alb = alb.FaiAlberoBinario(
                alb.FaiAlberoBinario(
                    alb.FaiAlberoBinario(
                        alb.AlberoBinarioVuoto(),
                        rand()%20,
                        alb.AlberoBinarioVuoto()),
                    rand()%20,
                    alb.AlberoBinarioVuoto()),
                rand()%20,
                alb.FaiAlberoBinario(
                    alb.AlberoBinarioVuoto(),
                    rand()%20,
                    alb.FaiAlberoBinario(
                        alb.AlberoBinarioVuoto(),
                        rand()%20,
                        alb.AlberoBinarioVuoto()
                        )
                    )
                );

    cout << alb;

    return a.exec();
}
