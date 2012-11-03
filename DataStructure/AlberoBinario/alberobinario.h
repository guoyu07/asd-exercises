#ifndef ALBEROBINARIO_H
#define ALBEROBINARIO_H

#include <iostream>

using namespace std;

template <class E>
struct nodo
{
    E dato;
    nodo *sin, *des;
};

/* classe per la realizzazione del tipo astratto AlberoBinario(Elem)
 * rappresentazione mediante sequenze di record e puntatori
 * realizzazione funzionale con condivisione */
template <class Elem>
class AlberoBinario
{
    friend ostream& operator<<(ostream& os, AlberoBinario<Elem>& s)
    {
        os << "{ ";
        s.StampaNodo(os,s.punt_rad);
        os << " }" << endl;
        return os;
    }
public:
    AlberoBinario();

    bool EstVuoto();
    int Radice();
    AlberoBinario Sinistro();
    AlberoBinario Destro();

    AlberoBinario AlberoBinarioVuoto();
    AlberoBinario FaiAlberoBinario(AlberoBinario<Elem>,Elem,AlberoBinario<Elem>);

protected:
    nodo<Elem>* punt_rad;

private:
    void StampaNodo(ostream&,nodo<Elem>*);
};

template <class Elem>
void AlberoBinario<Elem>::StampaNodo(ostream& os, nodo<Elem>* n)
{
    if(n != NULL)
    {
        StampaNodo(os,n->sin);
        os << "(" << n->dato << ")";
        StampaNodo(os,n->des);
    }
}

template <class Elem>
AlberoBinario<Elem>::AlberoBinario() : punt_rad(NULL)
{ }

template <class Elem>
bool AlberoBinario<Elem>::EstVuoto()
{
    return punt_rad == NULL;
}

template <class Elem>
int AlberoBinario<Elem>::Radice()
{
    return punt_rad->dato;
}

template <class Elem>
AlberoBinario<Elem> AlberoBinario<Elem>::AlberoBinarioVuoto()
{
    AlberoBinario<Elem> alb;
    return alb;
}

template <class Elem>
AlberoBinario<Elem> AlberoBinario<Elem>::FaiAlberoBinario(AlberoBinario<Elem> sx,Elem r,AlberoBinario<Elem> dx)
{
    AlberoBinario<Elem> alb;
    alb.punt_rad = new nodo<Elem>;
    alb.punt_rad->dato = r;
    alb.punt_rad->sin = sx.punt_rad;
    alb.punt_rad->des = dx.punt_rad;
    return alb;
}

template <class Elem>
AlberoBinario<Elem> AlberoBinario<Elem>::Sinistro()
{
    AlberoBinario<Elem> alb;
    alb.punt_rad = punt_rad->sin;
    return alb;
}

template <class Elem>
AlberoBinario<Elem> AlberoBinario<Elem>::Destro()
{
    AlberoBinario<Elem> alb;
    alb.punt_rad = punt_rad->des;
    return alb;
}

#endif // ALBEROBINARIO_H
