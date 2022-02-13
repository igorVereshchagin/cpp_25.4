#include <iostream>
#include "tools.h"
#include <string>
#include <vector>

enum op_code_t
{
  op_cut,
  op_suture,
  op_hemostat,
  op_pinch,
  op_finish
};

struct cut_t
{
  point_t start;
  point_t finish;
};

struct suture_t
{
  point_t start;
  point_t finish;
};

struct operation_t
{
  std::vector<cut_t> cuts;
  std::vector<suture_t> sutures;
  std::vector<point_t> hemostats;
  std::vector<point_t> tweezers;
  std::vector<op_code_t> op_codes;
};

bool started(const operation_t &operation)
{
  return !operation.op_codes.empty();
}

bool finished(const operation_t &operation)
{
  return !operation.op_codes.empty() && (operation.op_codes[operation.op_codes.size() - 1] == op_finish);
}

void history(const operation_t &operation)
{

}

int main()
{
  operation_t operation;
  do
  {
    std::string command;
    std::cout << "Input command:" << std::endl;
    std::cin >> command;
    if (command == "scalpel")
    {

    }
    else if (command == "hemostat" && started(operation))
    {

    }
    else if (command == "tweezers" && started(operation))
    {

    }
    else if (command == "suture" && started(operation))
    {

    }
    else if (command == "history" && started(operation))
    {

    }
    else if (command == "finish" && started(operation))
    {

    }
  }while(!finished(operation));
  return 0;
}
