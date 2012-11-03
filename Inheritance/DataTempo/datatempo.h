#ifndef DATATEMPO_H
#define DATATEMPO_H

#include <iostream>
#include "../../Modularity/Data/data.h"
#include "../../Modularity/Tempo/tempo.h"

using namespace std;

class DataTempo : public Data, public Tempo
{
    friend DataTempo operator+(DataTempo,DataTempo);
    friend DataTempo operator+(DataTempo,Tempo);
    friend DataTempo operator+(DataTempo,Data);
    friend DataTempo operator-(DataTempo,DataTempo);
    friend DataTempo operator-(DataTempo,Tempo);
    friend DataTempo operator-(DataTempo,Data);
    friend bool operator==(DataTempo,DataTempo);
    friend bool operator<(DataTempo,DataTempo);
    friend bool operator>(DataTempo,DataTempo);

public:
    DataTempo();
    DataTempo(Data,Tempo);
    DataTempo(int,int,int,int,int,int);
};

ostream& operator<<(ostream&,DataTempo);
DataTempo operator+(DataTempo,DataTempo);
DataTempo operator+(DataTempo,Tempo);
DataTempo operator+(DataTempo,Data);
DataTempo operator-(DataTempo,DataTempo);
DataTempo operator-(DataTempo,Tempo);
DataTempo operator-(DataTempo,Data);
bool operator==(DataTempo,DataTempo);
bool operator<(DataTempo,DataTempo);
bool operator>(DataTempo,DataTempo);

#endif // DATATEMPO_H
