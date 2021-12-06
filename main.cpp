#include <iostream>
#include "MinMaxMedianHeap.h"

int main() {

    MinMaxMedianHeap mmmHeap = MinMaxMedianHeap(10);
    mmmHeap.Insert(3, "hi");
    mmmHeap.Insert(2, "why");
    mmmHeap.Insert(9, "bye");
    mmmHeap.Insert(7, "day");
    cout << mmmHeap.Median().getPriority() << " " << mmmHeap.Median().getData() << endl;
    return 0;
}
