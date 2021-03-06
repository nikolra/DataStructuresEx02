#ifndef DATASTRUCTURESEX02_MAXHEAP_H
#define DATASTRUCTURESEX02_MAXHEAP_H


#include "Pair.h"
#include "Heap.h"
#include "MinHeap.h"
class MaxHeap : public Heap{

public:
    MaxHeap(int size) :Heap(size){}
    Pair Max();
    Pair DeleteMax(Heap& otherHeap);
    void FixHeap(int node, Heap& otherHeap) override;
    void FixHeapUp(int node, Heap& otherHeap) override;
    int Insert(Pair item, Heap& otherHeap) override;

    friend class MinHeap;

};
#endif DATASTRUCTURESEX02_MAXHEAP_H
