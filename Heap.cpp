#include "Heap.h"

int Heap::Left(int node)
{
    return 2 * node + 1;
}

int Heap::Right(int node)
{
    return 2 * node + 2;
}

int Heap::Parent(int node)
{
    return  (node - 1) / 2;
}

void Heap::Swap(int i1, int i2, Heap& otherHeap)
{
    Pair temp = data[i1];
    data[i1] = data[i2];
    data[i2] = temp;

    int i1BrotherIndex = this->data[i1].getBrothersIndex();
    int i2BrotherIndex = this->data[i2].getBrothersIndex();
    otherHeap.data[i1BrotherIndex].setBrothersIndex(i2);
    otherHeap.data[i2BrotherIndex].setBrothersIndex(i1);
}

Heap::Heap(int max)
{
    data = new Pair[max];
    maxSize = max;
    heapSize = 0;
    isAllocated = true;
}

Heap::~Heap()
{
    if(isAllocated)
        delete [] data;
    data = nullptr;
}


Pair Heap::Delete(int node, Heap& otherHeap)
{
    if(heapSize < 1)
        throw new HeapException("no nodes in the heap");
    Pair temp = data[node];
    heapSize--;
    data[node] = data[heapSize];
    if(FindMax(data[node].getPriority(), data[ 2 * node + 1].getPriority(),
               data[2 * node + 2].getPriority()) != data[node].getPriority())
    {
    FixHeap(node, otherHeap);
    }
    else{
        FixHeapUp(node, otherHeap);
    }

    return temp;
}

int Heap::FindMax(int n1, int n2, int n3)
{
    int max = n1 > n2 ? n1 : n2;
    max = max > n3 ? max : n3;

    return max;
}

int Heap::getHeapSize() const {
    return heapSize;
}

void Heap::setBrotherIndex(int myIndex, int brotherIndex)
{
    this->data[myIndex].setBrothersIndex(brotherIndex);
}