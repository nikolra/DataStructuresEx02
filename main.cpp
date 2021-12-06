#include <iostream>
#include "MinMaxMedianHeap.h"
#include "AppUI.h"
int main() {

    try{
        AppUI appUi;
        appUi.Run();
        return 0;
    } catch (HeapException e)
    {
        cout << e.GetMessage();
    }
}
