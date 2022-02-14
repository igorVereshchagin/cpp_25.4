#include <iostream>
#include "ram.h"
#include "cpu.h"

void compute()
{
  int buf[8];
  read(buf);
  int sum = 0;
  for (int i = 0; i < 8; i++)
    sum += buf[i];
  std::cout << sum << std::endl;
}