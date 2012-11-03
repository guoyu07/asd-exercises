#ifndef MERGESORT_H
#define MERGESORT_H

#include "MergeSort_global.h"

template <class T>
class MERGESORTSHARED_EXPORT MergeSort {

public:
    static void Sort(T* a, int n)
    {
        MergeSortRic(a,0,n-1);
    }

private:
    static void Merge(T a[], int basso, int medio, int alto)
    {
        int dim = alto-basso+1;
        T* temp = new T[dim];
        int itemp = 0;
        int i1 = basso;
        int i2 = medio+1;
        while(i1 <= medio && i2 <= alto)
        {
            if(a[i1] < a[i2])
            {
                temp[itemp] = a[i1];
                i1++;
            }
            else
            {
                temp[itemp] = a[i2];
                i2++;
            }
            itemp++;
        }
        if(itemp < dim)
        {
            if(i1 <= medio)
            {
                while(i1 <= medio)
                {
                    temp[itemp] = a[i1];
                    i1++;
                    itemp++;
                }
            }
            else
            {
                while(i2 <= alto)
                {
                    temp[itemp] = a[i2];
                    i2++;
                    itemp++;
                }
            }
        }
        for(itemp=0; itemp<dim; itemp++)
            a[itemp+basso] = temp[itemp];
        delete [] temp;
    }

    static void MergeSortRic(T* a, int basso, int alto)
    {
        if(basso < alto)
        {
            int medio = (alto+basso)/2;
            MergeSortRic(a,basso,medio);
            MergeSortRic(a,medio+1,alto);
            Merge(a,basso,medio,alto);
        }
    }
};

#endif // MERGESORT_H
