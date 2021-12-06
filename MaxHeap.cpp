#include "MaxHeap.h"

void MaxHeap::FixHeap(int node, Heap& otherHeap)
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
        Swap(node, max, otherHeap);
        FixHeap(max, otherHeap);
    }
}

Pair MaxHeap::Max()
{
    return data[0];
}

Pair MaxHeap::DeleteMax(Heap& otherHeap)
{
    if(heapSize < 1)
        throw new HeapException("no nodes in the heap");
    Pair max = data[0];
    heapSize--;
    data[0] = data[heapSize];
    FixHeap(0, otherHeap);
    return max;
}

int MaxHeap::Insert(Pair item, Heap& otherHeap)
{
    if(heapSize == maxSize)
        throw new HeapException("no more space in the heap");
    int i = heapSize;
    heapSize++;
    while( ( i > 0 ) && (data[Parent(i)].getPriority() < item.getPriority()))
    {
        data[i] = data[Parent((i))];

        int brother = data[Parent(i)].getBrothersIndex();
        MinHeap& heap =  dynamic_cast<MinHeap&>(otherHeap);
        heap.data[brother].setBrothersIndex(i);

        i = Parent(i);
    }

    data[i] = item;

    return i;
}

void MaxHeap::FixHeapUp(int node, Heap& otherHeap)
{//I am bigger than my parent

    int parent = Parent(node);

    while(node != 0 && data[node].getPriority() > data [parent].getPriority())
    {
        Swap(node, parent, otherHeap);
        node = parent;
        parent = Parent(node);
    }
}
