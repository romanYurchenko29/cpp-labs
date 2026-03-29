#include "box.h"
#include "container.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdexcept>

namespace Storages
{
  class WeightLimitExceeded : public std::exception
  {
  public:
    const char *what() const noexcept override
    {
      return "Превышен максимальный вес контейнера!";
    }
  };

  Container::Container(int length, int width, int height, double weight)
  {
    this->length = length;
    this->width = width;
    this->height = height;
    this->maxWeight = weight;
  };

  int Container::getBoxesCount() { return boxes.size(); }

  double Container::getWeight()
  {
    double result = 0.0;
    for (Box box : boxes)
    {
      result += box.weight;
    }
    return result;
  }

  int Container::getTotalValue()
  {
    int total = 0;
    for (const Box &box : boxes)
    {
      total += box.value;
    }
    return total;
  }

  Box Container::getAtIndex(int index)
  {
    if (isValidIndex(index))
    {
      return boxes[index];
    }
  }

  int Container::addBox(const Box &box)
  {
    if (getWeight() + box.weight > maxWeight)
    {
      throw WeightLimitExceeded();
    }
    boxes.push_back(box);
    return boxes.size() - 1;
  }

  int Container::addBoxAtIndex(const Box &box, int index)
  {
    if (isValidIndex(index))
    {
      if (getWeight() + box.weight > maxWeight)
      {
        throw WeightLimitExceeded();
      }
      boxes.insert(boxes.begin() + index, box);
      return index;
    }
  }

  void Container::deleteAtIndex(int index)
  {
    if (!isValidIndex(index))
    {
      return;
    }
    boxes.erase(boxes.begin() + index);
  }

  std::ostream &Storages::operator<<(std::ostream &os, const Container &container)
  {
    os << "Container(" << container.length << " " << container.width << " " << container.height
       << ", maxWeight: " << container.maxWeight << ", boxes: [";
    for (size_t i = 0; i < container.boxes.size(); ++i)
    {
      os << container.boxes[i];
      if (i < container.boxes.size() - 1)
        os << ", ";
    }
    os << "])";
    return os;
  }

  std::istream &Storages::operator>>(std::istream &is, Container &container)
  {
    is >> container.length >> container.width >> container.height >> container.maxWeight;
    int boxCount;
    is >> boxCount;
    container.boxes.clear();
    for (int i = 0; i < boxCount; ++i)
    {
      Box box;
      is >> box;
      container.boxes.push_back(box);
    }
    return is;
  }

  const Box &Container::operator[](int index) const
  {
    if (index < 0 || static_cast<std::vector<int>::size_type>(index) >= boxes.size())
    {
      throw std::out_of_range("Индекс за пределами диапазона");
    }
    return boxes[index];
  }

  bool Container::isValidIndex(int index)
  {
    if (index < 0 || static_cast<std::vector<int>::size_type>(index) >= boxes.size())
    {
      throw std::out_of_range("Индекс за пределами диапазона");
    }
    else
    {
      return true;
    }
  }
}