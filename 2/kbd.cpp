#include <iostream>
#include "kbd.h"
#include "ram.h"

void input()
{
  int buf[8];
  std::cout << "Input 8 numbers:" << std::endl;
  for (int i = 0; i < 8; i++)
    std::cin >> buf[i];
  write(buf);
}
