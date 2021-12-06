#ifndef DATASTRUCTURESEX02_MINHEAP_H
#define DATASTRUCTURESEX02_MINHEAP_H


#include "Heap.h"

class MinHeap : public Heap{

public:
    MinHeap(int size) :Heap(size){}
    Pair Min();
    Pair DeleteMin();
    void FixHeap(int node) override;
    void FixHeapUp(int node) override;
    void Insert(Pair item) override;
};


#endif DATASTRUCTURESEX02_MINHEAP_H
