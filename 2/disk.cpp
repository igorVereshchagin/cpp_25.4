#include <fstream>
#include <iostream>
#include "ram.h"
#include "disk.h"

void save()
{
  std::ofstream save_file("data.txt");
  if (!save_file.is_open())
  {
    std::cout << "Can't open file data.txt" << std::endl;
    return;
  }
  int buf[8];
  read(buf);
  for (int i = 0; i < 8; i++)
    save_file << buf[i] << std::endl;
  save_file.close();
}

void load()
{
  std::ifstream load_file("data.txt");
  if (!load_file.is_open())
  {
    std::cout << "Can't open file data.txt" << std::endl;
    return;
  }
  int buf[8];
  for (int i = 0; i < 8; i++)
    load_file >> buf[i];
  write(buf);
  load_file.close();
}