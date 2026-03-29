#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int size)
    : capacity(size), head(0), tail(0), count(0)
{
    data = new int[capacity];
}

CircularBuffer::~CircularBuffer()
{
    delete[] data;
}

void CircularBuffer::push(int value)
{
    if (count == capacity)
    {
        throw std::overflow_error("Buffer overflow");
    }

    data[tail] = value;
    tail = (tail + 1) % capacity;
    count++;
}

int CircularBuffer::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Buffer is empty");
    }

    int value = data[head];
    head = (head + 1) % capacity;
    count--;
    return value;
}

int CircularBuffer::front() const
{
    if (isEmpty())
    {
        throw std::underflow_error("Buffer is empty");
    }
    return data[head];
}

int CircularBuffer::size() const
{
    return count;
}

bool CircularBuffer::isEmpty() const
{
    return count == 0;
}

void CircularBuffer::clear()
{
    head = tail = count = 0;
}

int CircularBuffer::getAt(int index) const
{
    if (index < 0 || index >= count)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[(head + index) % capacity];
}
