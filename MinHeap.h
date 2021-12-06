#ifndef DATASTRUCTURESEX02_MINHEAP_H
#define DATASTRUCTURESEX02_MINHEAP_H


#include "Heap.h"
#include "MaxHeap.h"
class MinHeap : public Heap{

public:
    MinHeap(int size) :Heap(size){}
    Pair Min();
    Pair DeleteMin(Heap& otherHeap);
    void FixHeap(int node, Heap& otherHeap) override;
    void FixHeapUp(int node, Heap& otherHeap) override;
    int Insert(Pair item, Heap& otherHeap) override;

    friend class MaxHeap;
};


#endif DATASTRUCTURESEX02_MINHEAP_H
