#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*SELECTION SORT*/

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
        array_dump(a,length);
    }
}

/*INSERTION SORT*/

static void insert(int a[], unsigned int i, unsigned int length) {
    unsigned int j = i;

    while (length > j && j > 0 && goes_before(a[j], a[j-1]))
    {
        swap(a,j-1,j);
        array_dump(a,length);
        j--;
    }
    
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
        assert(array_is_sorted(a, i));
    }
}

/*QUICK SORT*/

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i,j,ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;

    while (i <= j)
    {
        if (goes_before(a[i],a[ppiv]))
        {
            i++;
        }
        else if (goes_before(a[ppiv],a[j]))
        {
            j--;
        }
        else if (goes_before(a[ppiv],a[i]) && goes_before(a[j],a[ppiv]))
        {
            swap(a,i,j);
            i++;
            j--;
        }
        array_dump(a,der);
    }

    swap(a,ppiv,j);
    array_dump(a,der);
    ppiv = j;
    
    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;

    if (der > izq)
    {
        ppiv = partition(a,izq,der);
        quick_sort_rec(a,izq,ppiv);
        quick_sort_rec(a,ppiv+1,der);
    }
    
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

