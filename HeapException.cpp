#include "HeapException.h"

HeapException::HeapException(string message)
{
    this->message = message;
}

string HeapException::GetMessage()
{
    return this->message;
}