#ifndef DATASTRUCTURESEX02_HEAP_H
#define DATASTRUCTURESEX02_HEAP_H

#include "Pair.h"
#include "HeapException.h"
class Heap {

protected:
    Pair* data;
    int maxSize;
    int heapSize;
    bool isAllocated;

protected:
    int Left(int node);
    int Right(int node);
    int Parent(int node);
    virtual void FixHeap(int node) = 0;
    virtual void FixHeapUp(int node) = 0;
    void Swap(Pair &p1, Pair &p2);
    int FindMax(int n1, int n2, int n3);
    Pair Delete(int node);

public:
    Heap(int max);
    Heap(Pair Arr[], int n);
    ~Heap();
    virtual void Insert(Pair item) = 0;
    Pair Delete(Pair pair);

    int getHeapSize() const;
};


#endif DATASTRUCTURESEX02_HEAP_H
