#ifndef PILA_H
#define PILA_H

#include <iostream>

using namespace std;

template <class E>
struct nodo
{
    E info;
    nodo* next;
};

/* classe per la realizzazione del tipo astratto Pila<Elem>
 * rappresentazione mediante sequenze di record e puntatori senza
 * duplicazioni; realizzazione con side-effect senza condivisione */
template <class Elem>
class Pila
{
    friend ostream& operator<<(ostream& os, Pila<Elem> s)
    {
        os << "{ ";
        while(!s.EstVuota())
        {
            os << s.Top() << " ";
            s.Pop();
        }
        os << "}" << endl;
        return os;
    }
public:
    Pila();                         // costruttore di pila vuota
    Pila(const Pila&);              // costruttore di copia
    ~Pila();                        // distruttore

    void PilaVuota();               // assegna all'oggetto di invocazione la pila vuota
    bool EstVuota();                // verifica se la pila è vuota

    void Push(Elem);                // inserisce un elemento in testa alla pila
    void Pop();                     // elimina un elemento dalla testa della pila
    Elem Top();                     // restituisce un l'elemento in testa alla pila

    Pila& operator=(const Pila&);   // assegnazione

private:
    nodo<Elem>* top;             // puntatore iniziale della sequenza di record
    static nodo<Elem>* Copia(nodo<Elem>*);      // funzione di servizio
    static void Rilascia(nodo<Elem>*);          // funzione di servizio
};

/* restituisce il puntatore ad una sequenza di record che duplica in
 * nuovi record quella puntata da p */
template <class Elem>
nodo<Elem>* Pila<Elem>::Copia(nodo<Elem>* p)
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
void Pila<Elem>::Rilascia(nodo<Elem>* p)
{
    if(p != NULL)
    {
        Rilascia(p->next);
        delete p;
    }
}

template <class Elem>
Pila<Elem>::Pila() : top(NULL)
{ }

template <class Elem>
Pila<Elem>::Pila(const Pila& t) : top(Copia(t.top))
{ }

template <class Elem>
Pila<Elem>::~Pila()
{
    Rilascia(top);
}

template <class Elem>
void Pila<Elem>::PilaVuota()
{
    Rilascia(top);
    top = NULL;
}

template <class Elem>
bool Pila<Elem>::EstVuota()
{
    return top == NULL;
}

template <class Elem>
void Pila<Elem>::Push(Elem e)
{
    nodo<Elem>* temp = new nodo<Elem>;
    temp->info = e;
    temp->next = top;
    top = temp;
}

template <class Elem>
void Pila<Elem>::Pop()
{
    if(!EstVuota())
    {
        nodo<Elem>* temp = top;
        top = top->next;
        delete temp;
    }
}

template <class Elem>
Elem Pila<Elem>::Top()
{
    return top->info;
}

template <class Elem>
Pila<Elem>& Pila<Elem>::operator=(const Pila<Elem>& t)
{
    if(t.top != top)
    {
        nodo<Elem>* temp = top;
        top = Copia(t.top);
        Rilascia(temp);
    }
    return *this;
}

#endif // PILA_H
