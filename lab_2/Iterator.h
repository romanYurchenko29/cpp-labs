#ifndef ITERATOR_H
#define ITERATOR_H

#include "CircularBuffer.h"

class Iterator
{
private:
    const CircularBuffer &buffer;
    int current;

public:
    Iterator(const CircularBuffer &buf);

    void start();
    void next();
    bool finish() const;
    int getValue() const;
};

#endif
