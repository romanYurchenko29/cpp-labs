#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdexcept>

class CircularBuffer
{
private:
    int *data;
    int capacity;
    int head;
    int tail;
    int count;

public:
    CircularBuffer(int size);
    ~CircularBuffer();

    void push(int value);
    int pop();
    int front() const;

    int size() const;
    bool isEmpty() const;
    void clear();

    int getAt(int index) const;
};

#endif
