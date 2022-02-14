#pragma once
#include "point.h"

void scalpel(const point_t &begin, const point_t &end)
{
  std::cout << "Cut from ";
  output(begin);
  std::cout << " till ";
  output(end);
  std::cout << std::endl;
}

void hemostat(const point_t &pt)
{
  std::cout << "Hemostat at ";
  output(pt);
  std::cout << std::endl;
}

void tweezers(const point_t &pt)
{
  std::cout << "Pinch at ";
  output(pt);
  std::cout << std::endl;
}

void suture(const point_t &begin, const point_t &end)
{
  std::cout << "Suture from ";
  output(begin);
  std::cout << " till ";
  output(end);
  std::cout << std::endl;
}