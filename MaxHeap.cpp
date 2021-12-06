#include "MaxHeap.h"

void MaxHeap::FixHeap(int node)
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

Pair MaxHeap::Max()
{
    return data[0];
}

Pair MaxHeap::DeleteMax()
{
    if(heapSize < 1)
        throw new HeapException("no nodes in the heap");
    Pair max = data[0];
    heapSize--;
    data[0] = data[heapSize];
    FixHeap(0);
    return max;
}

void MaxHeap::Insert(Pair item)
{
    if(heapSize == maxSize)
        throw new HeapException("no more space in the heap");
    int i = heapSize;
    heapSize++;
    while( ( i > 0 ) && (data[Parent(i)].getPriority() < item.getPriority()))
    {
        data[i] = data[Parent((i))];
        i = Parent(i);
    }

    data[i] = item;
}

void MaxHeap::FixHeapUp(int node)
{//I am bigger than my parent

    int parent = Parent(node);

    while(node != 0 && data[node].getPriority() > data [parent].getPriority())
    {
        Swap(data[node], data[parent]);
        node = parent;
        parent = Parent(node);
    }
}
