#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#pragma once
#include <iostream>

class DynamicArray
{
private:
    int *data;
    size_t size;
    size_t capacity;

    void resizeCapacity(size_t newCapacity);

public:
    // Конструкторы
    DynamicArray();
    explicit DynamicArray(size_t size);
    DynamicArray(size_t size, int value);
    DynamicArray(const DynamicArray &other);
    DynamicArray(DynamicArray &&other) noexcept;

    // Деструктор
    ~DynamicArray();

    // Операторы присваивания
    DynamicArray &operator=(const DynamicArray &other);
    DynamicArray &operator=(DynamicArray &&other) noexcept;

    // Методы доступа
    size_t getSize() const;
    int &operator[](size_t index);
    const int &operator[](size_t index) const;

    // Управление размером и емкостью
    void resize(size_t newSize);
    void reserve(size_t additionalCapacity);
    size_t getCapacity() const;

    // Операции с элементами
    void pushBack(int value);
    int popBack();

    // Операторы сравнения
    bool operator==(const DynamicArray &other) const;
    bool operator!=(const DynamicArray &other) const;
    bool operator<(const DynamicArray &other) const;
    bool operator<=(const DynamicArray &other) const;
    bool operator>(const DynamicArray &other) const;
    bool operator>=(const DynamicArray &other) const;

    // Конкатенация
    DynamicArray operator+(const DynamicArray &other) const;
};

// Операторы ввода/вывода
std::ostream &operator<<(std::ostream &os, const DynamicArray &arr);
std::istream &operator>>(std::istream &is, DynamicArray &arr);

#endif // DYNAMIC_ARRAY_H