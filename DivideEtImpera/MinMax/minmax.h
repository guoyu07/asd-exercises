#ifndef MINMAX_H
#define MINMAX_H

#include "MinMax_global.h"

template <class T>
class MINMAXSHARED_EXPORT MinMax {
public:
    static void Calculate(T v[],int n,T& min,T& max)
    {
        MinMaxRic(v,0,n-1,min,max);
    }

private:
    static void MinMaxRic(T v[],int inf,int sup,T& min,T& max)
    {
        if(sup-inf == 0)
        {
            min = v[inf];
            max = v[inf];
        }
        else if(sup-inf == 1)
        {
            if(v[inf] < v[sup])
            {
                min = v[inf];
                max = v[sup];
            }
            else
            {
                min = v[sup];
                max = v[inf];
            }
        }
        else
        {
            int medio = (inf+sup)/2;
            T min1,max1;
            MinMaxRic(v,inf,medio,min,max);
            MinMaxRic(v,medio+1,sup,min1,max1);
            if(min1 < min)
                min = min1;
            if(max1 > max)
                max = max1;
        }
    }
};

#endif // MINMAX_H
