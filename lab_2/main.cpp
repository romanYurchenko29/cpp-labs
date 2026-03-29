#include <iostream>
#include "CircularBuffer.h"
#include "Iterator.h"

int main()
{
    CircularBuffer buffer(5);
    buffer.push(10);
    buffer.push(20);
    buffer.push(30);

    std::cout << "Front: " << buffer.front() << std::endl;

    std::cout << "Pop: " << buffer.pop() << std::endl;

    buffer.push(40);
    buffer.push(50);

    std::cout << "Buffer size: " << buffer.size() << std::endl;

    Iterator it(buffer);

    std::cout << "Iterating: ";
    for (it.start(); !it.finish(); it.next())
    {
        std::cout << it.getValue() << " ";
    }
    std::cout << std::endl;

    buffer.clear();
    std::cout << "Is empty: " << buffer.isEmpty() << std::endl;
    return 0;
}
