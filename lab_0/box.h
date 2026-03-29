#include <iostream>
#ifndef BOX_H
#define BOX_H

namespace Storages
{
    class Box
    {
    public:
        int length;
        int width;
        int height;
        int value;
        double weight;

        Box();

        Box(int length, int width, int height, int value, double weight);

        bool operator==(const Box &other) const;

        friend std::ostream &operator<<(std::ostream &os, const Box &box);

        friend std::istream &operator>>(std::istream &is, Box &box);

    public:
        int volume() const;
    };

    std::ostream &operator<<(std::ostream &os, const Box &box);

    std::istream &operator>>(std::istream &is, Box &box);

    int boxArraySum(Box *boxArr, int size);

    bool checkBoxParameters(Box *boxArr, int size, int maxSumV);

    double maxWeight(Box *boxArr, int size, int maxV);

    bool canNestAllBoxes(Box *boxArr, int size);
}

#endif //BOX_H