#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "../ListaSemplice/listasemplice.h"

using namespace std;

/* classe per la realizzazione del tipo astratto ListaSemplice<F>
 * rappresentazione mediante sequenze di record e puntatori senza
 * duplicazioni; realizzazione con side-effect senza condivisione */
template <class F>
class Lista
{
    friend ostream& operator<<(ostream& os, Lista<F>& s)
    {
        os << "{ ";
        Stampa(os,s);
        os << "}";
        return os;
    }

public:
    Lista();                                    // costruttore di lista vuota
    Lista(const Lista&);                        // costruttore di copia
    ~Lista();                                   // distruttore

    void ListaVuota();                          // assegna all'oggetto di invocazione la lista vuota
    bool EstVuota();                            // verifica se la lista è vuota
    bool EstListaCar();                         // verifica che il primo elemento della lista sia una lista

    void Cons(F);                               // inserisce un elemento nella lista
    void Cons(Lista<F>);                        // inserisce una lista nella lista
    F CarElem();                                // restituisce il primo elemento della lista se è un elemento
    Lista<F> CarList();                         // restituisce il primo elemento della lista se è una lista
    void Cdr();                                 // elimina il primo elemento della lista

    Lista<F> Concatena(Lista<F>,Lista<F>);      // concatena una lista alla lista
    ListaSemplice<F> Raccogli(Lista<F>);        // raccogli sul primo livello tutti gli elementi della lista

    Lista& operator=(const Lista&);             // assegnazione
private:
    template <class E>
    class atomolista
    {
    public:
        atomolista() : flag(false), atomo(0), lista(NULL), next(NULL) {}
        bool flag;              // 0 --> Atomo, 1 --> Lista
        E atomo;                // significativo se flag == 0
        Lista<E>* lista;         // significativo se flag == 1
        atomolista<E>* next;    // punta all'elemento successivo
    };
    atomolista<F>* primo;                       // puntatore iniziale della sequenza di record
    static atomolista<F>* Copia(atomolista<F>*);    // funzione di servizio
    static void Rilascia(atomolista<F>*);           // funzione di servizio
    static void Stampa(ostream&,Lista<F>);          // funzione di servizio
};

/* restituisce il puntatore ad una sequenza di record che duplica in
 * nuovi record quella puntata da p */
template <class F>
Lista<F>::atomolista<F>* Lista<F>::Copia(atomolista<F>* p)
{
    if(p != NULL)
    {
        atomolista<F>* q = new atomolista<F>;
        q->flag = p->flag;
        if(p->flag)
        {
            q->lista = new Lista<F>;
            q->lista->primo = Copia(p->lista->primo);
        }
        else
            q->atomo = p->atomo;
        q->next = Copia(p->next);
        return q;
    }
    else
        return NULL;
}

/* rilascia i record della sequenza puntata da p */
template <class F>
void Lista<F>::Rilascia(atomolista<F>* p)
{
    if(p != NULL)
    {
        Rilascia(p->next);
        if(p->flag)
            Rilascia(p->lista->primo);
        delete p;
    }
}

/* Stampa la lista */
template <class F>
void Lista<F>::Stampa(ostream& os,Lista<F> l)
{
    if(!l.EstVuota())
    {
        if(l.EstListaCar())
        {
            os << "{ ";
            Stampa(os,l.CarList());
            os << "} ";
        }
        else
            os << l.CarElem() << " ";
        l.Cdr();
        Stampa(os,l);
    }
}

template <class F>
Lista<F>::Lista() : primo(NULL)
{ }

template <class F>
Lista<F>::Lista(const Lista& t) : primo(Copia(t.primo))
{ }

template <class F>
Lista<F>::~Lista()
{
    Rilascia(primo);
}

template <class F>
void Lista<F>::ListaVuota()
{
    Rilascia(primo);
    primo = NULL;
}

template <class F>
bool Lista<F>::EstVuota()
{
    return primo == NULL;
}

template <class F>
bool Lista<F>::EstListaCar()
{
    if(primo != NULL)
        return primo->flag;
}

template <class F>
void Lista<F>::Cons(F e)
{
    atomolista<F>* temp = new atomolista<F>;
    temp->flag = false;
    temp->atomo = e;
    temp->next = primo;
    primo = temp;
}

template <class F>
void Lista<F>::Cons(Lista<F> l)
{
    atomolista<F>* temp = new atomolista<F>;
    temp->flag = true;
    temp->lista = new Lista<F>;
    temp->lista->primo = Copia(l.primo);
    temp->next = primo;
    primo = temp;
}

template <class F>
F Lista<F>::CarElem()
{
    if(primo != NULL && !EstListaCar())
    {
        return primo->atomo;
    }
}

template <class F>
Lista<F> Lista<F>::CarList()
{
    if(primo != NULL && EstListaCar())
    {
        return *(primo->lista);
    }
}

template <class F>
void Lista<F>::Cdr()
{
    atomolista<F>* temp = primo;
    primo = primo->next;
    if(temp->flag)
        Rilascia(temp->lista->primo);
    delete temp;
}

template <class F>
Lista<F> Lista<F>::Concatena(Lista<F> l1,Lista<F> l2)
{
    Lista<F> aux;
    if(l1.EstVuota())
        return l2;
    else if(l2.EstVuota())
        return l1;
    else{
        while(l1.EstVuota())
        {
            if(l1.EstListaCar())
                aux.Cons(l1.CarList());
            else
                aux.Cons(l1.CarElem());
            l1.Cdr();
        }
        while(l2.EstVuota())
        {
            if(l2.EstListaCar())
                aux.Cons(l2.CarList());
            else
                aux.Cons(l2.CarElem());
            l2.Cdr();
        }
        return aux;
    }
}

template <class F>
ListaSemplice<F> Lista<F>::Raccogli(Lista<F> l)
{
    ListaSemplice<F> aux;
    while(!l.EstVuota())
    {
        if(l.EstListaCar())
        {
            aux.Concatena(Raccogli(l.CarList()));
        }
        else
        {
            aux.Inserisci(l.CarElem(),aux.Lunghezza());
        }
        l.Cdr();
    }
    return aux;
}

template <class F>
Lista<F>& Lista<F>::operator=(const Lista<F>& t)
{
    if(t.primo != primo)
    {
        atomolista<F>* temp = primo;
        primo = Copia(t.primo);
        Rilascia(temp);
    }
    return *this;
}

#endif // LISTA_H
