#ifndef DATASTRUCTURESEX02_PAIR_H
#define DATASTRUCTURESEX02_PAIR_H

#include "iostream"

using namespace std;

class Pair {

private:
    int priority;
    string data;

public:
    Pair(int priority, const string &data);

    Pair();

    int getPriority() const;
    void setPriority(int priority);
    const string &getData() const;
    void setData(const string &mData);

};


#endif DATASTRUCTURESEX02_PAIR_H
