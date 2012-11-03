#ifndef LISTASEMPLICE_H
#define LISTASEMPLICE_H

#include <iostream>

using namespace std;

template <class E>
struct nodo
{
    E info;
    nodo* next;
};

/* classe per la realizzazione del tipo astratto ListaSemplice<F>
 * rappresentazione mediante sequenze di record e puntatori senza
 * duplicazioni; realizzazione con side-effect senza condivisione */
template <class F>
class ListaSemplice
{
    friend ostream& operator<<(ostream& os, ListaSemplice<F>& s)
    {
        os << "{ ";
        for(IterListaSemplice<F> it(s); !it.ElemNullo(); it.Avanza())
            cout << it.ElemCorrente() << " ";
        os << "}" << endl;
        return os;
    }

public:
    ListaSemplice();                            // costruttore di lista semplice vuota
    ListaSemplice(const ListaSemplice&);        // costruttore di copia
    ~ListaSemplice();                           // distruttore

    void ListaSempliceVuota();                  // assegna all'oggetto di invocazione la lista semplice vuota
    bool EstVuota();                            // verifica se la lista semplice è vuota

    F Ritrova(int);                             // restituisce un elemento data la sua posizione
    int TrovaPos(F,int);                        // restituisce la posizione di un elemento
    int Lunghezza();                            // restituisce il numero di elementi nella lista semplice

    void Inserisci(F,int);                      // inserisce un elemento nella lista semplice
    void Elimina(int);                          // elimina un elemento data la sua posizione
    void EliminaElem(F,int);                    // elimina un elemento dalla lista semplice

    void Concatena(ListaSemplice<F>);           // concatena una lista alla lista semplice

    ListaSemplice& operator=(const ListaSemplice&); // assegnazione

    template <class G>
    class IterListaSemplice{
    public:
        IterListaSemplice(const ListaSemplice<G>& l) : lista(&l), corrente(l.primo) { } //costruttore

        void Reset() { corrente = lista->primo; }       // si riposiziona ad inizio lista
        bool ElemNullo() { return corrente == NULL; }   // verifica se non esiste elemento corrente
        void Avanza() { corrente = corrente->next; }    // avanza di un elemento
        G ElemCorrente() { return corrente->info; }     // restituisce l'elemento corrente della lista

    private:
        const ListaSemplice<G>* lista;              // lista a cui l'iteratore è associato
        nodo<G>* corrente;                          // nodo corrente della lista
    };

private:
    nodo<F>* primo;                             // puntatore iniziale della sequenza di record
    int lunghezza;                              // numero di elementi nella lista semplice
    static nodo<F>* Copia(nodo<F>*);                // funzione di servizio
    static void Rilascia(nodo<F>*);                 // funzione di servizio
};

/* restituisce il puntatore ad una sequenza di record che duplica in
 * nuovi record quella puntata da p */
template <class F>
nodo<F>* ListaSemplice<F>::Copia(nodo<F>* p)
{
    if(p != NULL)
    {
        nodo<F>* q = new nodo<F>;
        q->info = p->info;
        q->next = Copia(p->next);
        return q;
    }
    else
        return NULL;
}

/* rilascia i record della sequenza puntata da p */
template <class F>
void ListaSemplice<F>::Rilascia(nodo<F>* p)
{
    if(p != NULL)
    {
        Rilascia(p->next);
        delete p;
    }
}

template <class F>
ListaSemplice<F>::ListaSemplice() : primo(NULL) , lunghezza(0)
{ }

template <class F>
ListaSemplice<F>::ListaSemplice(const ListaSemplice& t) : primo(Copia(t.primo)) , lunghezza(t.lunghezza)
{ }

template <class F>
ListaSemplice<F>::~ListaSemplice()
{
    Rilascia(primo);
}

template <class F>
void ListaSemplice<F>::ListaSempliceVuota()
{
    Rilascia(primo);
    primo = NULL;
    lunghezza = 0;
}

template <class F>
bool ListaSemplice<F>::EstVuota()
{
    return primo == NULL;
}

template <class F>
F ListaSemplice<F>::Ritrova(int i)
{
    if(i < lunghezza)
    {
        nodo<F>* temp = primo;
        while(i != 0)
        {
            temp = temp->next;
            i--;
        }
        return temp->info;
    }
}

template <class F>
int ListaSemplice<F>::TrovaPos(F e,int i=1)
{
    nodo<F>* temp = primo;
    int aux = 0;
    while(temp != NULL)
    {
        if(temp->info == e)
        {
            i--;
            if(i == 0)
                return aux;
        }
        aux++;
        temp = temp->next;
    }
}

template <class F>
int ListaSemplice<F>::Lunghezza()
{
    return lunghezza;
}

template <class F>
void ListaSemplice<F>::Inserisci(F e,int i=0)
{
    if(i <= lunghezza)
    {
        nodo<F>* temp = new nodo<F>;
        temp->info = e;
        temp->next = NULL;
        nodo<F>* temp2 = primo;
        if(temp2 == NULL)
            primo = temp;
        else
        {
            if(i == 0)
            {
                temp->next = primo;
                primo = temp;
            }
            else
            {
                while(i != 1)
                {
                    temp2 = temp2->next;
                    i--;
                }
                temp->next = temp2->next;
                temp2->next = temp;
            }
        }
        lunghezza++;
    }
}

template <class F>
void ListaSemplice<F>::Elimina(int i)
{
    if(i < lunghezza)
    {
        nodo<F>* temp = primo;
        if(i == 0)
        {
            primo = primo->next;
            delete temp;
        }
        else
        {
            while(i != 1)
            {
                temp = temp->next;
                i--;
            }
            nodo<F>* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        }
        lunghezza--;
    }
}

template <class F>
void ListaSemplice<F>::EliminaElem(F e, int i=1)
{
    Elimina(TrovaPos(e,i));
}

template <class F>
void ListaSemplice<F>::Concatena(ListaSemplice<F> l)
{
    for(IterListaSemplice<F> it(l); !it.ElemNullo(); it.Avanza())
        Inserisci(it.ElemCorrente(),Lunghezza());
}

template <class F>
ListaSemplice<F>& ListaSemplice<F>::operator=(const ListaSemplice<F>& t)
{
    if(t.primo != primo)
    {
        nodo<F>* temp = primo;
        primo = Copia(t.primo);
        Rilascia(temp);
    }
    return *this;
}

#endif // LISTASEMPLICE_H
