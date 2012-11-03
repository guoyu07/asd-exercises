#include "datatempo.h"

DataTempo::DataTempo()
{ }

DataTempo::DataTempo(Data d,Tempo t) : Data(d), Tempo(t)
{ }

DataTempo::DataTempo(int a,int me,int g,int o,int mi,int s) : Data(a,me,g), Tempo(o,mi,s)
{ }

ostream& operator<<(ostream& os, DataTempo d)
{
    return os << d.Giorno() << "/" << d.Mese() << "/" << d.Anno() << " "
              << d.Ore() << ":" << d.Minuti() << ":" << d.Secondi();
}

DataTempo operator+(DataTempo d1,DataTempo d2)
{
    DataTempo aux;
    aux.giorno = d1.giorno + d2.giorno;
    aux.mese = d1.mese + d2.mese;
    aux.anno = d1.anno + d2.anno;
    aux.secondi = d1.secondi + d2.secondi;

    if(aux.secondi >  86400)
    {
        aux.secondi = aux.secondi % 86400;
        aux.giorno++;
    }

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

DataTempo operator+(DataTempo d,Tempo t)
{
    DataTempo aux;
    aux.giorno = d.giorno;
    aux.mese = d.mese;
    aux.anno = d.anno;
    aux.secondi = d.secondi + t.Ore()*3600 + t.Minuti()*60 + t.Secondi();

    if(aux.secondi >  86400)
    {
        aux.secondi = aux.secondi % 86400;
        aux.giorno++;
    }

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

DataTempo operator+(DataTempo dt,Data d)
{
    DataTempo aux;
    aux.giorno = dt.giorno + d.Giorno();
    aux.mese = dt.mese + d.Mese();
    aux.anno = dt.anno + d.Anno();
    aux.secondi = dt.secondi;

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

DataTempo operator-(DataTempo d1,DataTempo d2)
{
    DataTempo aux;
    aux.giorno = d1.giorno - d2.giorno;
    aux.mese = d1.mese - d2.mese;
    aux.anno = d1.anno - d2.anno;
    aux.secondi = d1.secondi - d2.secondi;

    if(aux.secondi < 0)
    {
        aux.secondi += 86400;
        aux.giorno--;
    }

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

DataTempo operator-(DataTempo d,Tempo t)
{
    DataTempo aux;
    aux.giorno = d.giorno;
    aux.mese = d.mese;
    aux.anno = d.anno;
    aux.secondi = d.secondi - + t.Ore()*3600 + t.Minuti()*60 + t.Secondi();

    if(aux.secondi < 0)
    {
        aux.secondi += 86400;
        aux.giorno--;
    }

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

DataTempo operator-(DataTempo dt,Data d)
{
    DataTempo aux;
    aux.giorno = dt.giorno - d.Giorno();
    aux.mese = dt.mese - d.Mese();
    aux.anno = dt.anno - d.Anno();
    aux.secondi = dt.secondi;

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

bool operator==(DataTempo d1,DataTempo d2)
{
    return d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno == d2.giorno && d1.secondi == d2.secondi;
}

bool operator<(DataTempo d1,DataTempo d2)
{
    return d1.anno < d2.anno || (d2.anno == d2.anno && d1.mese < d2.mese) ||
            (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno < d2.giorno) ||
            (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno == d2.giorno && d1.secondi < d2.secondi);
}


bool operator>(DataTempo d1,DataTempo d2)
{
    return d1.anno > d2.anno || (d2.anno == d2.anno && d1.mese > d2.mese) ||
            (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno > d2.giorno) ||
            (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno == d2.giorno && d1.secondi > d2.secondi);
}
