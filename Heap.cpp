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

void Heap::FixHeap(int node)
{
    int max;
    int left = Left(node);
    int right = Right(node);

    if((left < heapSize) && (data[left].getPriority() > data[node].getPriority()))
        max = left;
    else
        max = node;

    if (( right < heapSize) && (data[right].getPriority() > data[max].getPriority()))
        max = right;

    if(max != node)
    {
        Swap(data[node], data[max]);
        FixHeap(max);
    }
}

void Heap::Swap(Pair &p1, Pair &p2)
{
    Pair temp = p1;
    p1 = p2;
    p2 = temp;
}

Heap::Heap(int max)
{
    data = new Pair[max];
    maxSize = max;
    heapSize = 0;
    isAllocated = true;
}

Heap::Heap(Pair Arr[], int n)
{
    heapSize = maxSize = n;

    data = Arr;
    isAllocated = false;

    for(int i = 0; i < n / 2 - 1; i--)
        FixHeap(i);
}

Heap::~Heap()
{
    if(isAllocated)
        delete [] data;
    data = nullptr;
}
Pair Heap::Delete(Pair pair)
{
    for(int i = 0; i < heapSize; i++)
    {
        if(pair.getPriority() == data[i].getPriority())
            if(pair.getData() == data[i].getData())
                return Delete(i);
    }

    throw new HeapException("node to delete wasn't found :(");
}

Pair Heap::Delete(int node)
{
    if(heapSize < 1)
        throw new HeapException("no nodes in the heap");
    Pair temp = data[node];
    heapSize--;
    data[node] = data[heapSize];
    if(FindMax(data[node].getPriority(), data[ 2 * node + 1].getPriority(),
               data[2 * node + 2].getPriority()) != data[node].getPriority())
    {
    FixHeap(node);
    }
    else{
        FixHeapUp(node);
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
