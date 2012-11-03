#include "bolletta.h"

Bolletta::Bolletta() : primo(NULL)
{ }

Bolletta::Bolletta(const Bolletta& b)
{
    primo = Copia(b.primo);
}

Bolletta::~Bolletta()
{
    Distruggi(primo);
}

bool Bolletta::Vuota()
{
    return primo == NULL;
}

void Bolletta::MettiTelefonata(Telefonata t)
{
    elemento* aux = new elemento;
    aux->info = t;
    aux->next = primo;
    primo = aux;
}

void Bolletta::TogliTelefonata(Telefonata t)
{
    elemento* aux = new elemento;
    aux->next = primo;
    primo = aux;

    while (aux->next != NULL)
    {
        if (aux->next->info == t)
        {
            elemento* aux2 = aux->next;
            aux->next = aux->next->next;
            delete aux2;

            aux2 = primo;
            primo = primo->next;
            delete aux2;
            return;
        }
        aux = aux->next;
    }
    aux = primo;
    primo = primo->next;
    delete aux;
}

Telefonata Bolletta::TogliUna()
{
    if(primo != NULL)
    {
        Telefonata auxtel = primo->info;
        elemento* aux = primo;
        primo = primo->next;
        delete aux;
        return auxtel;
    }
}

Bolletta& Bolletta::operator= (const Bolletta& b)
{
    if(primo != b.primo)
    {
        elemento* temp = primo;
        primo = Copia(b.primo);
        Distruggi(temp);
    }
    return *this;
}

Bolletta::elemento* Bolletta::Copia(elemento* e)
{
    if(e == NULL)
        return NULL;
    else
    {
        elemento* aux = new elemento;
        aux->info = e->info;
        aux->next = Copia(e->next);
        return aux;
    }
}

void Bolletta::Distruggi(elemento* e)
{
    while(e != NULL)
    {
        elemento* temp = e;
        e = e->next;
        delete temp;
    }
}

ostream& operator<<(ostream& os, Bolletta b)
{
    Bolletta::elemento* aux = b.primo;
    int i = 1;
    os << "*** CONTENUTO DELLA BOLLETTA ***" << endl;
    while (aux != NULL)
    {
        os << i << ": " << aux->info << endl;
        i++;
        aux = aux->next;
    }
    os << "************* FINE *************" << endl;
    return os;
}

Tempo DurataTotale(Bolletta b)
{
    Tempo aux;
    while (!b.Vuota())
    {
        Telefonata temp  = b.TogliUna();
        aux = aux + temp.Fine() - temp.Inizio();
    }
    return aux;
}

float CostoTotale(Bolletta b)
{
    float aux;
    while(!b.Vuota())
    {
        Telefonata temp = b.TogliUna();
        aux += temp.Costo();
    }
    return aux;
}

Bolletta TutteLeChiamateA(long int n, Bolletta& b)
{
    Bolletta aux, resto;
    while(!b.Vuota())
    {
        Telefonata temp = b.TogliUna();
        if(temp.Numero() == n)
            aux.MettiTelefonata(temp);
        else
            resto.MettiTelefonata(temp);
    }
    b=resto;
    return aux;
}
