#pragma once
#include "point.h"

void scalpel(const point_t &start, const point_t &finish)
{
  std::cout << "Cut from ";
  output(start);
  std::cout << " till ";
  output(finish);
  std::cout << std::endl;
}

void hemostat(const point_t &pt)
{

}

void tweezers(const point_t &pt)
{

}

void suture(const point_t &start, const point_t &finish)
{

}