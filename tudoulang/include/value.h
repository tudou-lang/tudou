#ifndef value_h
#define value_h

#include "common.h"
#include <cstdio>

using Value = double;

class ValueArray {
    public:
    std::vector<Value> values;
    int count = 0;
    void writeValueArray(Value value){
        values.push_back(value);
        count += 1;
    }
    ValueArray() = default;
    ~ValueArray() = default;
};

void printValue(Value value);

#endif