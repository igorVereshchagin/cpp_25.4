#include <iostream>
#include "ram.h"
#include "gpu.h"

void display()
{
  int buf[8];
  read(buf);
  for (int i = 0; i < 8; i++)
    std::cout << buf[i] << std::endl;
}