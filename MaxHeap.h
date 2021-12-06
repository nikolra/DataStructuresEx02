#ifndef DATASTRUCTURESEX02_MAXHEAP_H
#define DATASTRUCTURESEX02_MAXHEAP_H


#include "Pair.h"
#include "Heap.h"

class MaxHeap : public Heap{

public:
    MaxHeap(int size) :Heap(size){}
    Pair Max();
    Pair DeleteMax();
    void FixHeap(int node) override;
    void FixHeapUp(int node) override;
    void Insert(Pair item) override;

};
#endif DATASTRUCTURESEX02_MAXHEAP_H
