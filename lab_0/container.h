#include <iostream>
#include "box.h"
#include <vector>
#ifndef CONTAINER_H
#define CONTAINER_H

namespace Storages
{
    class WeightLimitExceeded : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class Container
    {
    public:
        int length;
        int width;
        int height;
        double maxWeight;
        std::vector<Box> boxes;

        Container(int length, int width, int height, double weight);

        int getBoxesCount();

        double getWeight();

        int getTotalValue();

        Box getAtIndex(int index);

        int addBox(const Box &box);

        int addBoxAtIndex(const Box &box, int index);

        void deleteAtIndex(int index);

        friend std::ostream &operator<<(std::ostream &os, const Container &container);

        friend std::istream &operator>>(std::istream &is, Container &container);

        const Box &operator[](int index) const
        {
            if (index < 0 || static_cast<std::vector<int>::size_type>(index) >= boxes.size())
            {
                throw std::out_of_range("Индекс за пределами диапазона");
            }
            return boxes[index];
        }

        bool isValidIndex(int index);
    };

    std::ostream &operator<<(std::ostream &os, const Container &container);

    std::istream &operator>>(std::istream &is, Container &container);
}

#endif CONTAINER_H