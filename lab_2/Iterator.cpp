#include "Iterator.h"

Iterator::Iterator(const CircularBuffer &buf)
    : buffer(buf), current(0) {}

void Iterator::start()
{
    current = 0;
}

void Iterator::next()
{
    current++;
}

bool Iterator::finish() const
{
    return current >= buffer.size();
}

int Iterator::getValue() const
{
    return buffer.getAt(current);
}
