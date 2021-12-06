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
        int indexMaxHeap = maxValuesMaxHeap.Insert(Pair(priority, value));
        int indexMinHeap = maxValuesMinHeap.Insert(Pair(priority, value));
        maxValuesMaxHeap.setBrotherIndex(indexMaxHeap, indexMinHeap);
        maxValuesMinHeap.setBrotherIndex(indexMinHeap, indexMaxHeap);

        if(size % 2 == 1)
        {
            Pair temp = maxValuesMinHeap.DeleteMin(maxValuesMaxHeap);

            maxValuesMaxHeap.Delete(temp.getBrothersIndex(), maxValuesMinHeap);
            int maxIndex = minValuesMaxHeap.Insert(temp);
            int minIndex = minValuesMinHeap.Insert(temp);
            minValuesMaxHeap.setBrotherIndex(maxIndex, minIndex);
            minValuesMinHeap.setBrotherIndex(minIndex, maxIndex);
        }
    }
    else
    {
        int indexMaxHeap = minValuesMaxHeap.Insert(Pair(priority, value));
        int indexMinHeap = minValuesMinHeap.Insert(Pair(priority, value));
        minValuesMaxHeap.setBrotherIndex(indexMaxHeap, indexMinHeap);
        minValuesMinHeap.setBrotherIndex(indexMinHeap, indexMaxHeap);
        if(size % 2 == 0)
        {
            Pair temp = minValuesMaxHeap.DeleteMax(minValuesMinHeap);
            minValuesMinHeap.Delete(temp.getBrothersIndex(), minValuesMaxHeap);
            int maxIndex = maxValuesMaxHeap.Insert(temp);
            int minIndex = maxValuesMinHeap.Insert(temp);
            maxValuesMaxHeap.setBrotherIndex(maxIndex, minIndex);
            maxValuesMinHeap.setBrotherIndex(minIndex, maxIndex);
        }
    }
}

Pair MinMaxMedianHeap::DeleteMax()
{
    Pair max = maxValuesMaxHeap.DeleteMax(minValuesMinHeap);

    maxValuesMinHeap.Delete(max.getBrothersIndex(), maxValuesMaxHeap);
    size--;
    if(size % 2 == 0)
    {
        Pair temp = minValuesMaxHeap.DeleteMax(minValuesMinHeap);

        minValuesMinHeap.Delete(temp.getBrothersIndex(), minValuesMaxHeap);
        int maxIndex = maxValuesMaxHeap.Insert(temp);
        int minIndex = maxValuesMinHeap.Insert(temp);
        maxValuesMaxHeap.setBrotherIndex(maxIndex, minIndex);
        maxValuesMinHeap.setBrotherIndex(minIndex, maxIndex);
    }

    return max;
}

Pair MinMaxMedianHeap::DeleteMin()
{
    Pair min = minValuesMinHeap.DeleteMin(minValuesMaxHeap);

    minValuesMaxHeap.Delete(min.getBrothersIndex(), minValuesMinHeap);
    size--;
    if(size % 2 == 1)
    {
        Pair temp = maxValuesMinHeap.DeleteMin(minValuesMaxHeap);

        maxValuesMaxHeap.Delete(temp.getBrothersIndex(), maxValuesMinHeap§);
        int maxIndex = minValuesMaxHeap.Insert(temp);
        int minIndex = minValuesMinHeap.Insert(temp);
        minValuesMaxHeap.setBrotherIndex(maxIndex, minIndex);
        minValuesMinHeap.setBrotherIndex(minIndex, maxIndex);
    }

    return min;
}
