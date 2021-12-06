#ifndef DATASTRUCTURESEX02_MINMAXMEDIANHEAP_H
#define DATASTRUCTURESEX02_MINMAXMEDIANHEAP_H


#include "Pair.h"
#include "MaxHeap.h"
#include "MinHeap.h"

class MinMaxMedianHeap {

private:
    MaxHeap maxValuesMaxHeap;
    MinHeap maxValuesMinHeap;

    MaxHeap minValuesMaxHeap;
    MinHeap minValuesMinHeap;

    int size;

public:
    MinMaxMedianHeap(int size );
    Pair Max();
    Pair DeleteMax();
    Pair Min();
    Pair DeleteMin();
    Pair Median();
    void Insert(int priority, string value);

};


#endif DATASTRUCTURESEX02_MINMAXMEDIANHEAP_H
