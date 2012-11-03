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
 * duplicazioni; realizzazione funzionale senza condivisione */
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
    Insieme(const Insieme&);        // costruttore di copia
    ~Insieme();                     // distruttore

    static Insieme InsVuoto();      // restituisce l'insieme vuoto
    bool EstVuoto();                // verifica se l'insieme è vuoto
    bool Membro(Elem);              // verifica se un valore è elemento dell'insieme

    Insieme Inserisci(Elem);        // inserisce un elemento nell'insieme
    Insieme Elimina(Elem);          // elimina un elemento dall'insieme
    Elem Scegli();                  // restituisce un elemento dell'insieme

    Insieme& operator=(const Insieme&);     // assegnazione
private:
    nodo<Elem>* inizio;             // puntatore iniziale della sequenza di record
    static bool Appartiene(Elem,nodo<Elem>*);   // funzione di servizio
    static nodo<Elem>* Copia(nodo<Elem>*);      // funzione di servizio
    static void Cancella(Elem,nodo<Elem>*&);    // funzione di servizio
    static void Rilascia(nodo<Elem>*);          // funzione di servizio
};

/* restituisce true se e solo se e appartiene alla sequenza puntata da p */
template <class Elem>
bool Insieme<Elem>::Appartiene(Elem e,nodo<Elem>* p)
{
    return (p != NULL) && ((p->info == e) || (Appartiene(e,p->next)));
}

/* restituisce il puntatore ad una sequenza di record che duplica in
 * nuovi record quella puntata da p */
template <class Elem>
nodo<Elem>* Insieme<Elem>::Copia(nodo<Elem>* p)
{
    if(p != NULL)
    {
        nodo<Elem>* q = new nodo<Elem>;
        q->info = p->info;
        q->next = Copia(p->next);
        return q;
    }
    else
        return NULL;
}

/* elimina i record con info == e (se esiste) dalla sequenza di
 * record puntata da p */
template <class Elem>
void Insieme<Elem>::Cancella(Elem e,nodo<Elem>*& p)
{
    if(p != NULL)
    {
        if(p->info == e)
        {
            nodo<Elem>* q = p;
            p = p->next;
            delete q;
        }
        else
            Cancella(e,p->next);
    }
}

/* rilascia i record della sequenza puntata da p */
template <class Elem>
void Insieme<Elem>::Rilascia(nodo<Elem>* p)
{
    if(p != NULL)
    {
        Rilascia(p->next);
        delete p;
    }
}

template <class Elem>
Insieme<Elem>::Insieme() : inizio(NULL)
{ }

template <class Elem>
Insieme<Elem>::Insieme(const Insieme& t) : inizio(Copia(t.inizio))
{ }

template <class Elem>
Insieme<Elem>::~Insieme()
{
    Rilascia(inizio);
}

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
        y.inizio->next = Copia(inizio);
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
        y.inizio = Copia(inizio);
        Cancella(e,y.inizio);
        return y;
    }
}

template <class Elem>
Elem Insieme<Elem>::Scegli()
{
    return inizio->info;
}

template <class Elem>
Insieme<Elem>& Insieme<Elem>::operator=(const Insieme<Elem>& t)
{
    if(this != &t)
    {
        nodo<Elem>* temp = inizio;
        inizio = Copia(t.inizio);
        Rilascia(temp);
    }
    return *this;
}

#endif // INSIEME_H
