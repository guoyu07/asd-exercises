#ifndef ALBERORICERCA_H
#define ALBERORICERCA_H

#include "../AlberoBinario/alberobinario.h"

/* classe per la realizzazione di un albero binario di ricerca
 * rappresentato tramite ereditarietà dalla classe AlberoBinario.
 * Realizzazione con side-effect senza condivisione */
template <class Elem>
class AlberoRicerca : public AlberoBinario<Elem>
{
public:
    AlberoRicerca();
    AlberoRicerca(const AlberoRicerca&);
    AlberoRicerca(const AlberoBinario<Elem>&);
    ~AlberoRicerca();

    bool Cerca(Elem);
    void Inserisci(Elem);
    void Elimina(Elem);

    AlberoRicerca& operator=(const AlberoRicerca&);

private:
    void Distruggi(nodo<Elem>*&);
    nodo<Elem>* Copia(nodo<Elem>*);
    void AggiungiNodo(Elem,nodo<Elem>*&);
    void EliminaNodo(Elem,nodo<Elem>*&);
    void EliminaNodoMin(Elem&,nodo<Elem>*&);
    bool CercaNodo(Elem,nodo<Elem>*);
};

template <class Elem>
void AlberoRicerca<Elem>::Distruggi(nodo<Elem>*& p)
{
    if(p != NULL)
    {
        Distruggi(p->sin);
        Distruggi(p->des);
        delete p;
    }
}

template <class Elem>
nodo<Elem>* AlberoRicerca<Elem>::Copia(nodo<Elem>* p)
{
    if(p == NULL)
        return NULL;
    nodo<Elem>* r = new nodo<Elem>;
    r->dato = p->dato;
    r->sin = Copia(p->sin);
    r->des = Copia(p->des);
    return r;
}

template <class Elem>
void AlberoRicerca<Elem>::AggiungiNodo(Elem e, nodo<Elem>*& p)
{
    if(p == NULL)
    {
        p = new nodo<Elem>;
        p->dato = e;
        p->sin = NULL;
        p->des = NULL;
    }
    else if(e < p->dato)
        AggiungiNodo(e,p->sin);
    else if(e > p->dato)
        AggiungiNodo(e,p->des);
}

template <class Elem>
void AlberoRicerca<Elem>::EliminaNodo(Elem e, nodo<Elem>*& p)
{
    if(p != NULL)
    {
        if(e < p->dato)
            EliminaNodo(e,p->sin);
        else if(e > p->dato)
            EliminaNodo(e,p->des);
        else
        {
            if(p->sin == NULL)
            {
                nodo<Elem>* q = p;
                p = p->des;
                delete q;
            }
            else if(p->des == NULL)
            {
                nodo<Elem>* q = p;
                p = p->sin;
                delete q;
            }
            else
            {
                Elem temp;
                EliminaNodoMin(temp,p->des);
                p->dato = temp;
            }
        }
    }
}

/* elimina il nodo di valore minimo nell'albero puntato
 * da p ed assegna la sua etichetta al parametro e */
template <class Elem>
void AlberoRicerca<Elem>::EliminaNodoMin(Elem& e, nodo<Elem>*& p)
{
    if(p->sin == NULL)
    {
        e = p->dato;
        nodo<Elem>* q = p;
        p = p->des;
        delete q;
    }
    else
        EliminaNodoMin(e,p->sin);
}

template <class Elem>
bool AlberoRicerca<Elem>::CercaNodo(Elem e, nodo<Elem>* p)
{
    if(p == NULL)
        return false;
    else if(p->dato == e)
        return true;
    else if(e < p->dato)
        return CercaNodo(e,p->sin);
    else
        return CercaNodo(e,p->des);
}

template <class Elem>
AlberoRicerca<Elem>::AlberoRicerca()
{ }

template <class Elem>
AlberoRicerca<Elem>::AlberoRicerca(const AlberoRicerca& a)
{
    *this->punt_rad = Copia(a.punt_rad);
}

template <class Elem>
AlberoRicerca<Elem>::AlberoRicerca(const AlberoBinario<Elem>& a)
{
    *this = (AlberoRicerca&)a;
}

template <class Elem>
AlberoRicerca<Elem>::~AlberoRicerca()
{
    Distruggi(this->punt_rad);
}

template <class Elem>
bool AlberoRicerca<Elem>::Cerca(Elem e)
{
    return CercaNodo(e,this->punt_rad);
}

template <class Elem>
void AlberoRicerca<Elem>::Inserisci(Elem e)
{
    AggiungiNodo(e,this->punt_rad);
}

template <class Elem>
void AlberoRicerca<Elem>::Elimina(Elem e)
{
    EliminaNodo(e,*(this->punt_rad));
}

template <class Elem>
AlberoRicerca<Elem>& AlberoRicerca<Elem>::operator=(const AlberoRicerca& a)
{
    if(this == &a)
        return *this;
    nodo<Elem>* temp = this->punt_rad;
    this->punt_rad = Copia(a.punt_rad);
    Distruggi(temp);
    return *this;
}

#endif // ALBERORICERCA_H
