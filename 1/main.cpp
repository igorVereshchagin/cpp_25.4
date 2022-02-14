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
  point_t begin;
  point_t end;
};

struct suture_t
{
  point_t begin;
  point_t end;
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
  std::vector<cut_t>::const_iterator it_cut = operation.cuts.cbegin();
  std::vector<suture_t>::const_iterator it_sut = operation.sutures.cbegin();
  std::vector<point_t>::const_iterator it_hem = operation.hemostats.cbegin();
  std::vector<point_t>::const_iterator it_twz = operation.tweezers.cbegin();
  for (std::vector<op_code_t>::const_iterator it_op = operation.op_codes.cbegin(); it_op != operation.op_codes.cend(); it_op++)
  {
    if (*it_op == op_cut)
    {
      std::cout << "Cut from ";
      output(it_cut->begin);
      std::cout << " till ";
      output(it_cut++->end);
      std::cout << std::endl;
    }
    else if (*it_op == op_suture)
    {
      std::cout << "Suture from ";
      output(it_sut->begin);
      std::cout << " till ";
      output(it_sut++->end);
      std::cout << std::endl;
    }
    else if (*it_op == op_hemostat)
    {
      std::cout << "Hemostat at ";
      output(*it_hem++);
      std::cout << std::endl;
    }
    else if (*it_op == op_pinch)
    {
      std::cout << "Pinch at ";
      output(*it_twz++);
      std::cout << std::endl;
    }
  }
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
      cut_t cut;
      std::cout << "Input begin and end of cut:" << std::endl;
      input(cut.begin);
      input(cut.end);
      scalpel(cut.begin, cut.end);
      operation.op_codes.push_back(op_cut);
      operation.cuts.push_back(cut);
    }
    else if (command == "hemostat" && started(operation))
    {
      point_t pt;
      std::cout << "Input point to hemostat:" << std::endl;
      input(pt);
      hemostat(pt);
      operation.op_codes.push_back(op_hemostat);
      operation.hemostats.push_back(pt);
    }
    else if (command == "tweezers" && started(operation))
    {
      point_t pt;
      std::cout << "Input point to pinch:" << std::endl;
      input(pt);
      tweezers(pt);
      operation.op_codes.push_back(op_pinch);
      operation.tweezers.push_back(pt);
    }
    else if (command == "suture" && started(operation))
    {
      suture_t sut;
      std::cout << "Input begin and end of suture:" << std::endl;
      input(sut.begin);
      input(sut.end);
      suture(sut.begin, sut.end);
      operation.op_codes.push_back(op_suture);
      operation.sutures.push_back(sut);
    }
    else if (command == "history" && started(operation))
    {
      history(operation);
    }
    else if (command == "finish" && started(operation))
    {
      if (!operation.sutures.empty())
      {
        double cmp_eps = 0.001;
        std::vector<cut_t>::iterator it_cut = operation.cuts.begin();
        std::vector<suture_t>::iterator it_sut = operation.sutures.end() - 1;
        if ((compare(it_cut->begin, it_sut->begin, cmp_eps) && compare(it_cut->end, it_sut->end, cmp_eps)) ||
            (compare(it_cut->begin, it_sut->end, cmp_eps) && compare(it_cut->end, it_sut->begin, cmp_eps)))
        {
          operation.op_codes.push_back(op_finish);
        }
      }
    }
    else
    {
      std::cout << "Invalid command" << std::endl;
    }
  }while(!finished(operation));
  std::cout << "Operation finished successful, the patient is alive!" << std::endl;
  return 0;
}
