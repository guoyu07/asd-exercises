#ifndef MULTIINSIEME_H
#define MULTIINSIEME_H

#include <iostream>

using namespace std;

template <class T>
struct record
{
    T info;
    int num;
    record* next;
};

/* classe per la realizzazione del tipo astratto MultiInsieme<Elem>
 * rappresentazione mediante sequenze di record
 * realizzazione con side-effect senza condivisione */
template <class Elem>
class MultiInsieme
{
    friend ostream& operator<<(ostream& os, MultiInsieme<Elem>& s)
    {
        record<Elem>* temp = s.inizio;
        os << "{ ";
        while(temp != NULL)
        {
            os << temp->info << "(" << temp->num << ") ";
            temp = temp->next;
        }
        os << "}" << endl;
        return os;
    }

public:
    MultiInsieme();
    MultiInsieme(const MultiInsieme<Elem>&);
    ~MultiInsieme();

    void MultiInsiemeVuoto();
    bool EstVuoto();
    virtual void Inserisci(Elem);
    virtual void Elimina(Elem);
    virtual int Molteplicita(Elem);
    virtual Elem Scegli();
    MultiInsieme& Unione(MultiInsieme<Elem>);
    MultiInsieme& Differenza(MultiInsieme<Elem>);

    MultiInsieme& operator=(const MultiInsieme<Elem>&);

protected:
    record<Elem>* inizio;
    record<Elem>* Cerca(Elem);
    void Togli(record<Elem>*);
    void Distruggi(record<Elem>*);
    record<Elem>* Copia(record<Elem>*);
};

template <class Elem>
record<Elem>* MultiInsieme<Elem>::Cerca(Elem e)
{
    record<Elem>* p = inizio;
    while(p != NULL)
    {
        if(p->info == e)
            return p;
        p = p->next;
    }
    return NULL;
}

template <class Elem>
void MultiInsieme<Elem>::Togli(record<Elem>* p)
{
    if(inizio == p)
    {
        inizio = inizio->next;
        delete p;
        return;
    }
    record<Elem>* aux = inizio;
    while(aux->next != p)
        aux = aux->next;
    aux->next = p->next;
    delete p;
}

template <class Elem>
void MultiInsieme<Elem>::Distruggi(record<Elem>* p)
{
    if(p != NULL)
    {
        Distruggi(p->next);
        delete p;
    }
}

template <class Elem>
record<Elem>* MultiInsieme<Elem>::Copia(record<Elem>* p)
{
    if(p == NULL)
        return NULL;
    else
    {
        record<Elem>* aux = new record<Elem>;
        aux->info = p->info;
        aux->num = p->num;
        aux->next = Copia(p->next);
        return aux;
    }
}

template <class Elem>
MultiInsieme<Elem>::MultiInsieme() : inizio(NULL)
{ }

template <class Elem>
MultiInsieme<Elem>::MultiInsieme(const MultiInsieme<Elem>& s) : inizio(Copia(s.inizio))
{ }

template <class Elem>
MultiInsieme<Elem>::~MultiInsieme()
{
    Distruggi(inizio);
}

template <class Elem>
void MultiInsieme<Elem>::MultiInsiemeVuoto()
{
    Distruggi(inizio);
    inizio == NULL;
}

template <class Elem>
bool MultiInsieme<Elem>::EstVuoto()
{
    return inizio == NULL;
}

template <class Elem>
void MultiInsieme<Elem>::Inserisci(Elem e)
{
    record<Elem>* p = Cerca(e);
    if(p == NULL)
    {
        p = inizio;
        inizio = new record<Elem>;
        inizio->info = e;
        inizio->num = 1;
        inizio->next = p;
    }
    else
       (p->num)++;
}

template <class Elem>
void MultiInsieme<Elem>::Elimina(Elem e)
{
    record<Elem>* p = Cerca(e);
    if(p == NULL)
        return;
    else
    {
        if(p->num > 1)
            (p->num)--;
        else
            Togli(p);
    }
}

template <class Elem>
int MultiInsieme<Elem>::Molteplicita(Elem e)
{
    record<Elem>* p = Cerca(e);
    if(p == NULL)
        return 0;
    else
        return p->num;
}

template <class Elem>
Elem MultiInsieme<Elem>::Scegli()
{
    return inizio->info;
}

template <class Elem>
MultiInsieme<Elem>& MultiInsieme<Elem>::Unione(MultiInsieme<Elem> s)
{
    while(!s.EstVuoto())
    {
        Elem e = s.Scegli();
        this->Inserisci(e);
        s.Elimina(e);
    }
    return *this;
}

template <class Elem>
MultiInsieme<Elem>& MultiInsieme<Elem>::Differenza(MultiInsieme<Elem> s)
{
    while(!s.EstVuoto())
    {
        Elem e = s.Scegli();
        this->Elimina(e);
        s.Elimina(e);
    }
    return *this;
}

template <class Elem>
MultiInsieme<Elem>& MultiInsieme<Elem>::operator=(const MultiInsieme<Elem>& s)
{
    if(&s != this)
    {
        Distruggi(inizio);
        inizio = Copia(s);
    }
    return *this;
}

#endif // MULTIINSIEME_H
