#include "data.h"

Data::Data() : giorno(1), mese(1), anno(1970)
{ }

Data::Data(int a, int m, int g)
{
    anno = a;

    if(m < 1 || m > 12)
        mese = 1;
    else
        mese = m;

    if(g < 1 || g > GiorniDelMese())
        giorno = 1;
    else
        giorno = g;
}

int Data::Giorno()
{
    return giorno;
}

int Data::Mese()
{
    return mese;
}

int Data::Anno()
{
    return anno;
}

int Data::GiorniDelMese()
{
    switch (mese)
    {
    case 2:
        if(Bisestile())
            return 29;
        else
            return 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    default:
        return 32;
        break;
    }
}

bool Data::Bisestile()
{
    if(anno%400 == 0)
        return true;
    if(anno%100 == 0)
        return false;
    if(anno%4 == 0)
        return true;
    return false;
}

ostream& operator<<(ostream& os, Data d)
{
    return os << d.Giorno() << "/" << d.Mese() << "/" << d.Anno();
}

Data operator+(Data d1, Data d2)
{
    Data aux;
    aux.giorno = d1.giorno + d2.giorno;
    aux.mese = d1.mese + d2.mese;
    aux.anno = d1.anno + d2.anno;
    if(aux.giorno > aux.GiorniDelMese())
    {
        aux.giorno -= aux.GiorniDelMese();
        aux.mese++;
    }
    if(aux.mese > 12)
    {
        aux.mese -= 12;
        aux.anno++;
    }
    return aux;
}

Data operator+(Data d1, int g)
{
    Data aux;
    aux.giorno = d1.giorno + g;
    aux.mese = d1.mese;
    aux.anno = d1.anno;
    if(aux.giorno > aux.GiorniDelMese())
    {
        aux.giorno -= aux.GiorniDelMese();
        aux.mese++;
    }
    if(aux.mese > 12)
    {
        aux.mese -= 12;
        aux.anno++;
    }
    return aux;
}

Data operator-(Data d1, Data d2)
{
    Data aux;
    aux.giorno = d1.giorno - d2.giorno;
    aux.mese = d1.mese - d2.mese;
    aux.anno = d1.anno - d2.anno;
    if(aux.giorno < 1)
    {
        aux.giorno += aux.GiorniDelMese();
        aux.mese--;
    }
    if(aux.mese < 1)
    {
        aux.mese += 12;
        aux.anno--;
    }
    return aux;
}

Data operator-(Data d1, int g)
{
    Data aux;
    aux.giorno = d1.giorno - g;
    aux.mese = d1.mese;
    aux.anno = d1.anno;
    if(aux.giorno < 1)
    {
        aux.giorno += aux.GiorniDelMese();
        aux.mese--;
    }
    if(aux.mese < 1)
    {
        aux.mese += 12;
        aux.anno--;
    }
    return aux;
}

bool operator==(Data d1, Data d2)
{
    return d1.Giorno() == d2.Giorno() && d1.Mese() == d2.Mese() && d1.Anno() == d2.Anno();
}

bool operator<(Data d1, Data d2)
{
    return (d1.Anno() < d2.Anno()) || (d1.Anno() == d2.Anno() && d1.Mese() < d2.Mese()) ||
            (d1.Anno() == d2.Anno() && d1.Mese() == d2.Mese() && d1.Giorno() < d2.Giorno());
}

bool operator>(Data d1, Data d2)
{
    return (d1.Anno() > d2.Anno()) || (d1.Anno() == d2.Anno() && d1.Mese() > d2.Mese()) ||
            (d1.Anno() == d2.Anno() && d1.Mese() == d2.Mese() && d1.Giorno() > d2.Giorno());
}
