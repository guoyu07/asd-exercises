#ifndef INSIEME_H
#define INSIEME_H

#include <iostream>

using namespace std;

template <class E>
struct nodo
{
    int cont;
    E info;
    nodo* next;
};

/* classe per la realizzazione del tipo astratto Insieme<Elem>
 * rappresentazione mediante sequenze di record e puntatori senza
 * duplicazioni; realizzazione con side-effect con condivisione */
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

    void InsVuoto();                // assegna all'oggetto di invocazione l'insieme vuoto
    bool EstVuoto();                // verifica se l'insieme è vuoto
    bool Membro(Elem);              // verifica se un valore è elemento dell'insieme

    void Inserisci(Elem);           // inserisce un elemento nell'insieme
    void Elimina(Elem);             // elimina un elemento dall'insieme
    Elem Scegli();                  // restituisce un elemento dell'insieme

    Insieme& operator=(const Insieme&);     // assegnazione
private:
    nodo<Elem>* inizio;             // puntatore iniziale della sequenza di record
    static bool Appartiene(Elem,nodo<Elem>*);   // funzione di servizio
    static void Cancella(Elem,nodo<Elem>*&);    // funzione di servizio
    static void AggiornaCont(nodo<Elem>*&,int); // funzione di servizio
};

/* restituisce true se e solo se e appartiene alla sequenza puntata da p */
template <class Elem>
bool Insieme<Elem>::Appartiene(Elem e,nodo<Elem>* p)
{
    return (p != NULL) && ((p->info == e) || (Appartiene(e,p->next)));
}

/* ricopia in nuovi record gli elementi che nella sequenza si trovano
 * prima di quello da eliminare, aggiunstando i contatori dei nuovi record
 * e di quelli che rimangono nella sequenza originaria */
template <class Elem>
void Insieme<Elem>::Cancella(Elem e,nodo<Elem>*& p)
{
    if(p->info == e)
    {
        nodo<Elem>* temp = p;
        p = p->next;
        if(temp->cont <= 1)
            delete temp;
        else
            temp->cont--;
    }
    else if(p->cont > 1)
    {
        nodo<Elem>* temp = p;
        p = new nodo<Elem>;
        p->info = temp->info;
        p->next = temp->next;
        p->cont = 1;
        temp->cont--;
        Cancella(e,p->next);
    }
    else
        Cancella(e,p->next);
}

/* somma il valore di q al campo cont di tutti i record raggiungibili da p */
template <class Elem>
void Insieme<Elem>::AggiornaCont(nodo<Elem>*& p,int q)
{
    nodo<Elem>* s = p;
    while(s != NULL)
    {
        s->cont = s->cont + q;
        if(s->cont == 0)
        {
            nodo<Elem>* temp = s;
            s = s->next;
            p = p->next;
            delete temp;
        }
        else
            s = s->next;
    }
}

template <class Elem>
Insieme<Elem>::Insieme() : inizio(NULL)
{ }

template <class Elem>
Insieme<Elem>::Insieme(const Insieme& t)
{
    inizio = t.inizio;
    AggiornaCont(inizio,+1);
}

template <class Elem>
Insieme<Elem>::~Insieme()
{
    AggiornaCont(inizio,-1);
}

template <class Elem>
void Insieme<Elem>::InsVuoto()
{
    AggiornaCont(inizio,-1);
    inizio = NULL;
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
void Insieme<Elem>::Inserisci(Elem e)
{
    if(!Appartiene(e,inizio))
    {
        nodo<Elem>* temp = new nodo<Elem>;
        temp->cont = 1;
        temp->info = e;
        temp->next = inizio;
        inizio = temp;
    }
}

template <class Elem>
void Insieme<Elem>::Elimina(Elem e)
{
    if(Appartiene(e,inizio))
        Cancella(e,inizio);
}

template <class Elem>
Elem Insieme<Elem>::Scegli()
{
    return inizio->info;
}

template <class Elem>
Insieme<Elem>& Insieme<Elem>::operator=(const Insieme<Elem>& t)
{
    if(inizio != t.inizio)
    {
        nodo<Elem>* temp = inizio;
        inizio = t.inizio;
        AggiornaCont(inizio,+1);
        AggiornaCont(temp,-1);
    }
    return *this;
}

#endif // INSIEME_H
