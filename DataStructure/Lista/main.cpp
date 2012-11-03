#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include "lista.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Lista<int> lista;

    for(int i=0; i<20; i++)
        if(rand()%2 == 0)
        {
            Lista<int> lista2;
            for(int j=0; j<10; j++)
                if(rand()%2 == 0)
                {
                    Lista<int> lista3;
                    for (int k=0; k<5; k++)
                        lista3.Cons(rand()%40);
                    lista2.Cons(lista3);
                }
                else
                {
                    lista2.Cons(rand()%40);
                }
            lista.Cons(lista2);
        }
        else
        {
            lista.Cons(rand()%40);
        }

    cout << lista;

    return a.exec();
}
