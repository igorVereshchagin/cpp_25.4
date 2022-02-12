#pragma once
#include <iostream>

struct point_t
{
  int x;
  int y;
};

bool compare(const point_t &pt1, const point_t &pt2)
{
  if (pt1.x == pt2.x && pt1.y == pt2.y)
    return true;
  return false;
}

void output(const point_t &pt)
{
  std::cout << "(" << pt.x << ", " << pt.y << ")";
}