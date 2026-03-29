#include "container.cpp"

#include <iostream>

int main()
{
  Box boxes[3] = {
      Box(2, 3, 4, 10, 5.5),
      Box(1, 1, 1, 5, 2.0),
      Box(5, 5, 5, 20, 10.0)};

  std::cout << "Sum of values: " << boxArraySum(boxes, 3) << std::endl;
  std::cout << "Can nest all boxes: " << std::boolalpha << canNestAllBoxes(boxes, 3) << std::endl;
  std::cout << "Max weight (maxV=100): " << maxWeight(boxes, 3, 100) << std::endl;
  std::cout << "Check box parameters (maxSumV=10): " << std::boolalpha << checkBoxParameters(boxes, 3, 10) << std::endl;

  for (int i = 0; i < 3; ++i)
  {
    std::cout << boxes[i] << std::endl;
  }

  return 0;
}