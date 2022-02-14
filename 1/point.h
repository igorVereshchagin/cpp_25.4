#pragma once
#include <iostream>
#include <cmath>

struct point_t
{
  double x;
  double y;
};

bool compare(const point_t &pt1, const point_t &pt2, double epsilon)
{
  if (fabs(pt1.x - pt2.x) < epsilon && fabs(pt1.y - pt2.y) < epsilon)
    return true;
  return false;
}

void output(const point_t &pt)
{
  std::cout << "(" << pt.x << ", " << pt.y << ")";
}

void input(point_t &pt)
{
  std::cout << "Input coordinates of point: ";
  std::cin >> pt.x >> pt.y;
}