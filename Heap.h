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
    virtual void FixHeap(int node, Heap& otherHeap) = 0;
    virtual void FixHeapUp(int node, Heap& otherHeap) = 0;
    void Swap(int i1, int i2, Heap& otherHeap);
    int FindMax(int n1, int n2, int n3);

public:
    Heap(int max);
    ~Heap();
    virtual int Insert(Pair item) = 0;
    Pair Delete(int node, Heap& otherHeap);
    void setBrotherIndex(int myIndex, int brotherIndex);
    int getHeapSize() const;
};


#endif DATASTRUCTURESEX02_HEAP_H
