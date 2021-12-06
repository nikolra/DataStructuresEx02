#include "MinMaxMedianHeap.h"

Pair MinMaxMedianHeap::Max()
{
    return maxValuesMaxHeap.Max();
}

Pair MinMaxMedianHeap::Min()
{
    return minValuesMinHeap.Min();
}

Pair MinMaxMedianHeap::Median()
{
    return minValuesMaxHeap.Max();
}

MinMaxMedianHeap::MinMaxMedianHeap(int maxSize) : minValuesMinHeap(maxSize), minValuesMaxHeap(maxSize),
maxValuesMaxHeap(maxSize), maxValuesMinHeap(maxSize)
{
    this->size = 0;
}

void MinMaxMedianHeap::Insert(int priority, string value)
{
    size++;
    if( priority > minValuesMaxHeap.Max().getPriority())
    {
        maxValuesMaxHeap.Insert(Pair(priority, value));
        maxValuesMinHeap.Insert(Pair(priority, value));
        if(size % 2 == 1)
        {
            Pair temp = maxValuesMinHeap.DeleteMin();

            maxValuesMaxHeap.Delete(temp);
            minValuesMaxHeap.Insert(temp);
            minValuesMinHeap.Insert(temp);
        }
    }
    else
    {
        minValuesMaxHeap.Insert(Pair(priority, value));
        minValuesMinHeap.Insert(Pair(priority, value));
        if(size % 2 == 0)
        {
            Pair temp = minValuesMaxHeap.DeleteMax();
            minValuesMinHeap.Delete(temp);
            maxValuesMaxHeap.Insert(temp);
            maxValuesMinHeap.Insert(temp);
        }
    }
}

Pair MinMaxMedianHeap::DeleteMax()
{
    Pair max = maxValuesMaxHeap.DeleteMax();

    maxValuesMinHeap.Delete(max);
    size--;
    if(size % 2 == 0)
    {
        Pair temp = minValuesMaxHeap.DeleteMax();

        minValuesMinHeap.Delete(temp);
        maxValuesMaxHeap.Insert(temp);
        maxValuesMinHeap.Insert(temp);
    }

    return max;
}

Pair MinMaxMedianHeap::DeleteMin()
{
    Pair min = minValuesMinHeap.DeleteMin();

    minValuesMaxHeap.Delete(min);
    size--;
    if(size % 2 == 1)
    {
        Pair temp = maxValuesMinHeap.DeleteMin();

        maxValuesMaxHeap.Delete(temp);
        minValuesMaxHeap.Insert(temp);
        minValuesMinHeap.Insert(temp);
    }

    return min;
}
