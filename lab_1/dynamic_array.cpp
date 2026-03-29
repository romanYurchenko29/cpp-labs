#include "dynamic_array.h"
#include <stdexcept>

DynamicArray::DynamicArray() : size(0), capacity(10)
{
    data = new int[capacity];
}

DynamicArray::DynamicArray(size_t size) : size(size), capacity(size)
{
    if (size == 0)
    {
        capacity = 10;
    }
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(size_t size, int value) : size(size), capacity(size)
{
    if (size == 0)
    {
        capacity = 10;
    }
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}

DynamicArray::DynamicArray(const DynamicArray &other) : size(other.size), capacity(other.capacity)
{
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &&other) noexcept
    : data(other.data), size(other.size), capacity(other.capacity)
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] data;
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

size_t DynamicArray::getSize() const
{
    return size;
}

int &DynamicArray::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int &DynamicArray::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void DynamicArray::resize(size_t newSize)
{
    if (newSize <= capacity)
    {
        if (newSize > size)
        {
            for (size_t i = size; i < newSize; ++i)
            {
                data[i] = 0;
            }
        }
        size = newSize;
    }
    else
    {
        resizeCapacity(newSize);
        for (size_t i = size; i < newSize; ++i)
        {
            data[i] = 0;
        }
        size = newSize;
    }
}

void DynamicArray::reserve(size_t additionalCapacity)
{
    size_t newCapacity = capacity + additionalCapacity;
    if (newCapacity > capacity)
    {
        resizeCapacity(newCapacity);
    }
}

size_t DynamicArray::getCapacity() const
{
    return capacity;
}

void DynamicArray::resizeCapacity(size_t newCapacity)
{
    int *newData = new int[newCapacity];
    size_t copySize = size < newCapacity ? size : newCapacity;
    for (size_t i = 0; i < copySize; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::pushBack(int value)
{
    if (size >= capacity)
    {
        resizeCapacity(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

int DynamicArray::popBack()
{
    if (size == 0)
    {
        throw std::out_of_range("Cannot pop from empty array");
    }
    return data[--size];
}

bool DynamicArray::operator==(const DynamicArray &other) const
{
    if (size != other.size)
    {
        throw std::logic_error("Arrays of different sizes cannot be compared");
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray &other) const
{
    return !(*this == other);
}

bool DynamicArray::operator<(const DynamicArray &other) const
{
    size_t minSize = size < other.size ? size : other.size;
    for (size_t i = 0; i < minSize; ++i)
    {
        if (data[i] < other.data[i])
            return true;
        if (data[i] > other.data[i])
            return false;
    }
    return size < other.size;
}

bool DynamicArray::operator<=(const DynamicArray &other) const
{
    return (*this < other) || (*this == other);
}

bool DynamicArray::operator>(const DynamicArray &other) const
{
    return !(*this <= other);
}

bool DynamicArray::operator>=(const DynamicArray &other) const
{
    return !(*this < other);
}

DynamicArray DynamicArray::operator+(const DynamicArray &other) const
{
    DynamicArray result(size + other.size);
    for (size_t i = 0; i < size; ++i)
    {
        result.data[i] = data[i];
    }
    for (size_t i = 0; i < other.size; ++i)
    {
        result.data[size + i] = other.data[i];
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const DynamicArray &arr)
{
    os << "[";
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        os << arr[i];
        if (i < arr.getSize() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

std::istream &operator>>(std::istream &is, DynamicArray &arr)
{
    size_t newSize;
    std::cout << "Enter size of array: ";
    is >> newSize;

    arr.resize(newSize);

    std::cout << "Enter " << newSize << " elements: ";
    for (size_t i = 0; i < newSize; ++i)
    {
        is >> arr[i];
    }

    return is;
}