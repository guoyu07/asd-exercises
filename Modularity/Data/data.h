#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data
{
    friend Data operator+(Data, Data);
    friend Data operator+(Data, int);
    friend Data operator-(Data, Data);
    friend Data operator-(Data, int);

public:
    Data();
    Data(int, int, int);
    int Giorno();
    int Mese();
    int Anno();

protected:
    int giorno;
    int mese;
    int anno;
    int GiorniDelMese();

private:
    bool Bisestile();
};

ostream& operator<<(ostream&, Data);
Data operator+(Data, Data);
Data operator+(Data, int);
Data operator-(Data, Data);
Data operator-(Data, int);
bool operator==(Data, Data);
bool operator<(Data, Data);
bool operator>(Data, Data);

#endif // DATA_H
