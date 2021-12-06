#include "MinHeap.h"

void MinHeap::FixHeap(int node, Heap& otherHeap)
{
    int min;
    int left = Left(node);
    int right = Right(node);

    if((left < heapSize) && (data[left].getPriority() < data[node].getPriority()))
        min = left;
    else
        min = node;

    if (( right < heapSize) && (data[right].getPriority() < data[min].getPriority()))
        min = right;

    if(min != node)
    {
        Swap(node, min, otherHeap);
        FixHeap(min, otherHeap);
    }
}

Pair MinHeap::Min()
{
    return data[0];
}

Pair MinHeap::DeleteMin(Heap& otherHeap)
{
    if(heapSize < 1)
        throw new HeapException("no nodes in the heap");
    Pair min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    FixHeap(0, otherHeap);
    return min;
}

int MinHeap::Insert(Pair item)
{
    if(heapSize == maxSize)
        throw new HeapException("no more space in the heap");
    int i = heapSize;
    heapSize++;
    while( ( i > 0 ) && (data[Parent(i)].getPriority() > item.getPriority()))
    {
        data[i] = data[Parent((i))];
        i = Parent(i);
    }

    data[i] = item;

    return i;
}

void MinHeap::FixHeapUp(int node, Heap& otherHeap)
{//I am bigger than my parent

    int parent = Parent(node);

    while(node != 0 && data[node].getPriority() < data [parent].getPriority())
    {
        Swap(node, parent, otherHeap);
        node = parent;
        parent = Parent(node);
    }
}

