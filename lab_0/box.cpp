#include "box.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

namespace Storages
{
  Box::Box()
  {
    height = 0;
    value = 0;
    weight = 0.0;
    length = 0;
    width = 0;
  }

  Box::Box(int length, int width, int height, int value, double weight)
  {
    if (length * width * height * weight == 0.0)
    {
      Box();
      this->value = value;
    }
    else
    {
      this->length = length;
      this->width = width;
      this->height = height;
      this->value = value;
      this->weight = weight;
    }
  }

  bool Box::operator==(const Box &other) const
  {
    return (length == other.length && width == other.width &&
            height == other.height && value == other.value &&
            weight == other.weight);
  }

  int Box::volume() const { return length * width * height; }

  std::ostream &Storages::operator<<(std::ostream &os, const Box &box)
  {
    os << "Box(" << box.length << " " << box.width << " " << box.height << " "
       << box.value << " " << box.weight << ")";
    return os;
  }

  std::istream &Storages::operator>>(std::istream &is, Box &box)
  {
    is >> box.length >> box.width >> box.height >> box.value >> box.weight;
    return is;
  }

  int Storages::boxArraySum(Box *boxArr, int size)
  {
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
      sum += boxArr[i].value;
    }
    return sum;
  }

  bool Storages::checkBoxParameters(Box *boxArr, int size, int maxSumV)
  {
    for (int i = 0; i < size; i++)
    {
      if (boxArr[i].length + boxArr[i].width + boxArr[i].height > maxSumV)
      {
        return false;
      }
    }
    return true;
  }

  double Storages::maxWeight(Box *boxArr, int size, int maxV)
  {
    double maxWeight = 0.0;
    for (int i = 0; i < size; i++)
    {
      if (boxArr[i].weight > maxWeight && boxArr[i].volume() <= maxV)
      {
        maxWeight = boxArr[i].weight;
      }
    }
    return maxWeight;
  }

  bool Storages::canNestAllBoxes(Box *boxArr, int size)
  {
    std::vector<Box> boxes(boxArr, boxArr + size);

    std::sort(boxes.begin(), boxes.end(),
              [](const Box &a, const Box &b)
              { return a.volume() < b.volume(); });

    for (int i = 0; i < size - 1; i++)
    {
      if (!(boxes[i].length < boxes[i + 1].length &&
            boxes[i].width < boxes[i + 1].width &&
            boxes[i].height < boxes[i + 1].height))
      {
        return false;
      }
    }
    return true;
  }

};
