#include <iostream>
#include <string>
#include "kbd.h"
#include "gpu.h"
#include "disk.h"
#include "cpu.h"

int main()
{
  std::string command;
  do
  {
    std::cout << "Input command:" << std::endl;
    std::cin >> command;
    if (command == "sum")
      compute();
    else if (command == "save")
      save();
    else if (command == "load")
      load();
    else if (command == "input")
      input();
    else if (command == "display")
      display();
    else if (command == "exit")
      continue;
    else
      std::cout << "Invalid command" << std::endl;
  }while(command != "exit");
  return 0;
}
