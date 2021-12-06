#ifndef DATASTRUCTURESEX02_HEAPEXCEPTION_H
#define DATASTRUCTURESEX02_HEAPEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class HeapException : public exception{

private:
    string message;
public:
    HeapException(string message);
    string GetMessage();
};


#endif //DATASTRUCTURESEX02_HEAPEXCEPTION_H
