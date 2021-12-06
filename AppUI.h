#ifndef DATASTRUCTURESEX02_APPUI_H
#define DATASTRUCTURESEX02_APPUI_H

#include "HeapException.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "MinMaxMedianHeap.h"

using namespace std;
class AppUI {

public:
    AppUI(){}
    void Run();
    static const int MAX_SIZE = 10;
private:
    int readInt();
    char* stringToCharArray(string& s);
    void commitAction(char c, MinMaxMedianHeap& heap);
    void checkInput(MinMaxMedianHeap& heap);
};


#endif DATASTRUCTURESEX02_APPUI_H
