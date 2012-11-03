#ifndef INSIEMESSR_H
#define INSIEMESSR_H

#include "../InsiemeSideEffectSenzaCondivisione/insiemess.h"

/* classe per la realizzazione del tipo astratto Insieme<Elem>
 * è utilizzabile se su Elem è definito un ordinamento totale
 * rappresentazione mediante sequenze ordinate di record e puntatori senza
 * duplicazioni; realizzazione con side-effect senza condivisione */
template <class Elem>
class InsiemeR : public Insieme<Elem>
{
public:
    void Inserisci(Elem);
    void Elimina(Elem);
    void Unione(InsiemeR,InsiemeR);
    bool operator==(const InsiemeR&);
};

/* mantiene la sequenza ordinata dopo l'inserimento */
template <class Elem>
void InsiemeR<Elem>::Inserisci(Elem e)
{
    if(this->inizio == NULL || this->inizio->info > e)
    {
        nodo<Elem>* temp = new nodo<Elem>;
        temp->info = e;
        temp->next = this->inizio;
        this->inizio = temp;
    }
    else if(this->inizio->info == e)
        return;
    else
    {
        nodo<Elem>* temp = this->inizio;
        while (temp->next != NULL)
        {
            if(temp->next->info == e)
                return;
            else if(temp->next->info > e)
            {
                nodo<Elem>* temp2 = new nodo<Elem>;
                temp2->info = e;
                temp2->next = temp->next;
                temp->next = temp2;
                return;
            }
            else
                temp = temp->next;
        }
        temp->next = new nodo<Elem>;
        temp->next->info = e;
        temp->next->next = NULL;
    }
}

/* mantiene la sequenza ordinata dopo la cancellazione */
template <class Elem>
void InsiemeR<Elem>::Elimina(Elem e)
{
    if(this->inizio == NULL)
        return;
    else if(this->inizio->info == e)
    {
        nodo<Elem>* temp = this->inizio;
        this->inizio = this->inizio->next;
        delete temp;
        return;
    }
    else
    {
        nodo<Elem>* temp = this->inizio;
        while(temp->next != NULL && temp->next->info < e)
            temp = temp->next;
        if(temp->next != NULL && temp->next->info == e)
        {
            nodo<Elem>* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
    }
}

/* utilizza l'algoritmo di merging di sequenze ordinate */
template <class Elem>
void InsiemeR<Elem>::Unione(InsiemeR s1,InsiemeR s2)
{
    Rilascia(this->inizio);
    this->inizio = new nodo<Elem>;
    nodo<Elem>* temp1 = s1.inizio;
    nodo<Elem>* temp2 = s2.inizio;
    nodo<Elem>* temp3 = this->inizio;
    while(temp1 != NULL && temp2 != NULL)
    {
        temp3->next = new nodo<Elem>;
        temp3 = temp3->next;
        if(temp1->info < temp2->info)
        {
            temp3->info = temp1->info;
            temp1 = temp1->next;
        }
        else if(temp1->info > temp2->info)
        {
            temp3->info = temp2->info;
            temp2 = temp2->next;
        }
        else
        {
            temp3->info = temp2->info;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    if(temp1 == NULL)
        temp3->next = Copia(temp2);
    else
        temp3->next = Copia(temp1);
    temp3 = this->inizio;
    this->inizio = this->inizio->next;
    delete temp3;
}

template <class Elem>
bool InsiemeR<Elem>::operator==(const InsiemeR<Elem>& s)
{
    nodo<Elem>* temp = this->inizio;
    nodo<Elem>* temp2 = s.inizio;
    while(temp != NULL && temp2 != NULL)
        if(temp->info != temp2->info)
            return false;
        else
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
    return temp == NULL && temp2 == NULL;
}

#endif // INSIEMESSR_H
