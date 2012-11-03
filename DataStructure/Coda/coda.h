#ifndef CODA_H
#define CODA_H

#include <iostream>

using namespace std;

template <class E>
struct nodo
{
    E info;
    nodo* next;
};

/* classe per la realizzazione del tipo astratto Coda<Elem>
 * rappresentazione mediante sequenze di record e puntatori senza
 * duplicazioni; realizzazione con side-effect senza condivisione */
template <class Elem>
class Coda
{
    friend ostream& operator<<(ostream& os, Coda<Elem> s)
    {
        os << "{ ";
        while(!s.EstVuota())
        {
            os << s.Primo() << " ";
            s.OutCoda();
        }
        os << "}" << endl;
        return os;
    }
public:
    Coda();                         // costruttore di coda vuota
    Coda(const Coda&);              // costruttore di copia
    ~Coda();                        // distruttore

    void CodaVuota();               // assegna all'oggetto di invocazione la coda vuota
    bool EstVuota();                // verifica se la coda è vuota

    void InCoda(Elem);              // inserisce un elemento in fondo alla coda
    void OutCoda();                 // elimina un elemento dalla testa della coda
    Elem Primo();                   // restituisce l'elemento in testa alla coda

    Coda& operator=(const Coda&);   // assegnazione

private:
    nodo<Elem>* primo;              // puntatore iniziale della sequenza di record
    static nodo<Elem>* Copia(nodo<Elem>*);      // funzione di servizio
    static void Rilascia(nodo<Elem>*);          // funzione di servizio
};

/* restituisce il puntatore ad una sequenza di record che duplica in
 * nuovi record quella puntata da p */
template <class Elem>
nodo<Elem>* Coda<Elem>::Copia(nodo<Elem>* p)
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

/* rilascia i record della sequenza puntata da p */
template <class Elem>
void Coda<Elem>::Rilascia(nodo<Elem>* p)
{
    if(p != NULL)
    {
        Rilascia(p->next);
        delete p;
    }
}

template <class Elem>
Coda<Elem>::Coda() : primo(NULL)
{ }

template <class Elem>
Coda<Elem>::Coda(const Coda& t) : primo(Copia(t.primo))
{ }

template <class Elem>
Coda<Elem>::~Coda()
{
    Rilascia(primo);
}

template <class Elem>
void Coda<Elem>::CodaVuota()
{
    Rilascia(primo);
    primo = NULL;
}

template <class Elem>
bool Coda<Elem>::EstVuota()
{
    return primo == NULL;
}

template <class Elem>
void Coda<Elem>::InCoda(Elem e)
{
    nodo<Elem>* temp = new nodo<Elem>;
    temp->info = e;
    temp->next = NULL;
    if(primo == NULL)
        primo = temp;
    else
    {
        nodo<Elem>* temp2 = primo;
        while(temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp;
    }
}

template <class Elem>
void Coda<Elem>::OutCoda()
{
    if(!EstVuota())
    {
        nodo<Elem>* temp = primo;
        primo = primo->next;
        delete temp;
    }
}

template <class Elem>
Elem Coda<Elem>::Primo()
{
    return primo->info;
}

template <class Elem>
Coda<Elem>& Coda<Elem>::operator=(const Coda<Elem>& t)
{
    if(t.primo != primo)
    {
        nodo<Elem>* temp = primo;
        primo = Copia(t.primo);
        Rilascia(temp);
    }
    return *this;
}

#endif // CODA_H
