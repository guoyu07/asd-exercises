#ifndef COLLEZIONE_H
#define COLLEZIONE_H

#include<iostream>

using namespace std;

template<class E>
struct elemento
{
    E info;
    elemento* next;
};

template<class T>
class Collezione
{
    friend ostream& operator<<(ostream& os, Collezione<T>& c)
    {
        elemento<T>* temp = c.primo;
        os << "{ ";
        while(temp != NULL)
        {
            os << temp->info << " ";
            temp = temp->next;
        }
        os << "}" << endl;
        return os;
    }

public:
    Collezione();
    Collezione(const Collezione<T>&);
    ~Collezione();

    bool Vuota();
    void Metti(T);
    T TogliUno();
    void Togli(T);

    Collezione& operator=(const Collezione<T>&);

private:
    elemento<T>* primo;
    elemento<T>* Copia(elemento<T>*);
    void Distruggi(elemento<T>*);
};

template<class T>
Collezione<T>::Collezione() : primo(NULL)
{ }

template<class T>
Collezione<T>::Collezione(const Collezione<T>& c)
{
    primo = Copia(c.primo);
}

template<class T>
Collezione<T>::~Collezione()
{
    Distruggi(primo);
}

template<class T>
bool Collezione<T>::Vuota()
{
    return primo == NULL;
}

template<class T>
void Collezione<T>::Metti(T t)
{
    elemento<T>* aux = new elemento<T>;
    aux->info = t;
    aux->next = primo;
    primo = aux;
}

template<class T>
T Collezione<T>::TogliUno()
{
    if(primo != NULL)
    {
        T auxt = primo->info;
        elemento<T>* aux = primo;
        primo = primo->next;
        delete aux;
        return auxt;
    }
}

template<class T>
void Collezione<T>::Togli(T t)
{
    elemento<T>* aux = new elemento<T>;
    aux->next = primo;
    primo = aux;

    while (aux->next != NULL)
    {
        if (aux->next->info == t)
        {
            elemento<T>* aux2 = aux->next;
            aux->next = aux->next->next;
            delete aux2;

            aux2 = primo;
            primo = primo->next;
            delete aux2;
            return;
        }
        aux = aux->next;
    }
    aux = primo;
    primo = primo->next;
    delete aux;
}

template<class T>
Collezione<T>& Collezione<T>::operator=(const Collezione<T>& c)
{
    if(c.primo != primo)
    {
        elemento<T>* temp = primo;
        primo = Copia(c.primo);
        Distruggi(temp);
    }

    return *this;
}

template<class T>
elemento<T>* Collezione<T>::Copia(elemento<T>* e)
{
    if(e == NULL)
        return NULL;
    else
    {
        elemento<T>* aux = new elemento<T>;
        aux->info = e->info;
        aux->next = Copia(e->next);
        return aux;
    }
}

template<class T>
void Collezione<T>::Distruggi(elemento<T>* e)
{
    while(e != NULL)
    {
        elemento<T>* temp = e;
        e = e->next;
        delete temp;
    }
}

#endif // COLLEZIONE_H
