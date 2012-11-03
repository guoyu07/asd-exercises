#ifndef INSIEME_H
#define INSIEME_H

#include <iostream>

using namespace std;

template <class E>
struct nodo
{
    E info;
    nodo* next;
};


/* classe per la realizzazione del tipo astratto Insieme<Elem>
 * rappresentazione mediante sequenze di record e puntatori senza
 * duplicazioni; realizzazione funzionale con condivisione */
template <class Elem>
class Insieme
{
    friend ostream& operator<<(ostream& os, Insieme<Elem>& s)
    {
        nodo<Elem>* temp = s.inizio;
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
    Insieme();                      // costruttore di insieme vuoto

    static Insieme InsVuoto();      // restituisce l'insieme vuoto
    bool EstVuoto();                // verifica se l'insieme è vuoto
    bool Membro(Elem);              // verifica se un valore è elemento dell'insieme

    Insieme Inserisci(Elem);        // inserisce un elemento nell'insieme
    Insieme Elimina(Elem);          // elimina un elemento dall'insieme
    Elem Scegli();                  // restituisce un elemento dell'insieme

    Elem Somma(Insieme<Elem>);      // restituisce la somma degli elementi dell'insieme

private:
    nodo<Elem>* inizio;             // puntatore iniziale della sequenza di record
    static bool Appartiene(Elem,nodo<Elem>*);       // funzione di servizio
    static nodo<Elem>* Cancella(Elem,nodo<Elem>*);  // funzione di servizio
};

/* restituisce true se e solo se e appartiene alla sequenza puntata da p */
template <class Elem>
bool Insieme<Elem>::Appartiene(Elem e,nodo<Elem>* p)
{
    return(p != NULL) && ((p->info == e) || (Appartiene(e,p->next)));
}

/* restituisce il puntatore ad una sequenza di record che copia
 * quella copiata da p fino al record r (escluso) con info == e (se esiste),
 * e poi condivide memoria con i record che seguono r */
template <class Elem>
nodo<Elem>* Insieme<Elem>::Cancella(Elem e,nodo<Elem>* p)
{
    if(p == NULL)
        return NULL;
    else if(p->info == e)
        return p->next;
    else
    {
        nodo<Elem>* q = new nodo<Elem>;
        q->info = p->info;
        q->next = Cancella(e,p->next);
        return q;
    }
}

template <class Elem>
Insieme<Elem>::Insieme() : inizio(NULL)
{ }

template <class Elem>
Insieme<Elem> Insieme<Elem>::InsVuoto()
{
    Insieme<Elem> t;
    return t;
}

template <class Elem>
bool Insieme<Elem>::EstVuoto()
{
    return inizio == NULL;
}

template <class Elem>
bool Insieme<Elem>::Membro(Elem e)
{
    return Appartiene(e,inizio);
}

template <class Elem>
Insieme<Elem> Insieme<Elem>::Inserisci(Elem e)
{
    if(Appartiene(e,inizio))
        return *this;
    else
    {
        Insieme<Elem> y;
        y.inizio = new nodo<Elem>;
        y.inizio->info = e;
        y.inizio->next = inizio;
        return y;
    }
}

template <class Elem>
Insieme<Elem> Insieme<Elem>::Elimina(Elem e)
{
    if(!Appartiene(e,inizio))
        return *this;
    else
    {
        Insieme<Elem> y;
        y.inizio = Cancella(e,inizio);
        return y;
    }
}

template <class Elem>
Elem Insieme<Elem>::Scegli()
{
    return inizio->info;
}

/* restituisce la somma degli elementi dell'insieme a;
 * è utilizzabile se il tipo che istanzia Elem ha il costruttore
 * di copia, l'operatore "+" e un convertitore dal tipo int */
template <class Elem>
Elem Insieme<Elem>::Somma(Insieme<Elem> a)
{
    if(a.EstVuoto())
        return 0;
    else
    {
        Elem temp = a.Scegli();
        return temp + Somma(Elimina(temp));
    }
}

#endif // INSIEME_H
