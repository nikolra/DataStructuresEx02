#include "Pair.h"

int Pair::getPriority() const {
    return priority;
}

void Pair::setPriority(int priority) {
    this->priority = priority;
}

const string &Pair::getData() const {
    return data;
}

void Pair::setData(const string &data) {
    this->data = data;
}

Pair::Pair(int priority, const string &data) : priority(priority), data(data) {}

Pair::Pair() {}

int Pair::getBrothersIndex() const {
    return brothersIndex;
}

void Pair::setBrothersIndex(int brothersIndex) {
    Pair::brothersIndex = brothersIndex;
}
