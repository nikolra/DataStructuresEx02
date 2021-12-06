#ifndef DATASTRUCTURESEX02_PAIR_H
#define DATASTRUCTURESEX02_PAIR_H

#include "iostream"

using namespace std;

class Pair {

private:
    int priority;
    string data;
    int brothersIndex;

public:
    Pair(int priority, const string &data);
    Pair();

    int getPriority() const;
    void setPriority(int priority);
    const string &getData() const;
    void setData(const string &mData);
    int getBrothersIndex() const;
    void setBrothersIndex(int brothersIndex);

    friend ostream& operator<<(ostream& out, const Pair& p)  {
        return out << p.priority << " " << p.data;
    }
};


#endif DATASTRUCTURESEX02_PAIR_H
