#include <iostream>
#include "dynamic_array.h"

int main()
{
    std::cout << "=== Testing constructors ===" << std::endl;

    DynamicArray arr1;
    std::cout << "Empty array (default): " << arr1 << std::endl;

    DynamicArray arr2(5);
    std::cout << "Array of size 5 (zeros): " << arr2 << std::endl;

    DynamicArray arr3(3, 7);
    std::cout << "Array of size 3 (sevens): " << arr3 << std::endl;

    // Доступ к элементам и изменение
    std::cout << "\n=== Testing element access ===" << std::endl;
    for (size_t i = 0; i < arr2.getSize(); ++i)
    {
        arr2[i] = i + 1;
    }
    std::cout << "Modified arr2: " << arr2 << std::endl;

    // Тестирование копирования и перемещения
    std::cout << "\n=== Testing copy and move ===" << std::endl;
    DynamicArray arr4 = arr2; // Копирование
    std::cout << "Copied array (arr4): " << arr4 << std::endl;

    DynamicArray arr5 = std::move(arr3);
    std::cout << "Moved array (arr5): " << arr5 << std::endl;
    std::cout << "After move, arr3 should be empty: " << arr3 << std::endl;

    // Тестирование resize
    std::cout << "\n=== Testing resize ===" << std::endl;
    arr1.resize(4);
    std::cout << "arr1 resized to 4: " << arr1 << std::endl;

    arr1.resize(6);
    std::cout << "arr1 resized to 6 (with zeros): " << arr1 << std::endl;

    arr1.resize(3);
    std::cout << "arr1 resized to 3 (truncated): " << arr1 << std::endl;

    // Тестирование reserve и capacity
    std::cout << "\n=== Testing reserve and capacity ===" << std::endl;
    std::cout << "arr2 size: " << arr2.getSize() << ", capacity: " << arr2.getCapacity() << std::endl;
    arr2.reserve(10);
    std::cout << "arr2 after reserve(10), size: " << arr2.getSize()
              << ", capacity: " << arr2.getCapacity() << std::endl;

    // Тестирование pushBack и popBack
    std::cout << "\n=== Testing pushBack and popBack ===" << std::endl;
    arr1.pushBack(42);
    std::cout << "arr1 after pushBack(42): " << arr1 << std::endl;

    int val = arr1.popBack();
    std::cout << "Popped value: " << val << ", arr1 after popBack: " << arr1 << std::endl;

    // Тестирование операторов сравнения
    std::cout << "\n=== Testing comparison operators ===" << std::endl;
    DynamicArray arr6(3, 1);
    DynamicArray arr7(3, 1);
    DynamicArray arr8(3, 2);

    std::cout << "arr6 == arr7: " << (arr6 == arr7) << std::endl;
    std::cout << "arr6 != arr8: " << (arr6 != arr8) << std::endl;
    std::cout << "arr6 < arr8: " << (arr6 < arr8) << std::endl;
    std::cout << "arr8 > arr6: " << (arr8 > arr6) << std::endl;

    // Тестирование конкатенации
    std::cout << "\n=== Testing concatenation ===" << std::endl;
    DynamicArray arr9 = arr6 + arr8;
    std::cout << "arr6 + arr8 = " << arr9 << std::endl;

    // Тестирование ввода/вывода
    std::cout << "\n=== Testing input/output ===" << std::endl;
    DynamicArray arr10;
    std::cout << "Enter array data:" << std::endl;

    return 0;
}