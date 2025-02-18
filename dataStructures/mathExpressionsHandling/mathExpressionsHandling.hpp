#pragma once

#include <iostream>
#include <map>

template <typename T>
bool isNum(const T &expression);

class OperatorsHandling
{
  private:
    static std::map<std::string, int> operatorsPriority;

  public:
    bool isOperator(std::string expr);
    int getOperatorPriority(std::string expr);
};

class ExpressionsHandling
{
  public:
    OperatorsHandling opHandling;

  public:
    std::string toPrefix(const std::string &expression);
    int clacPrefix(const std::string &expression);

    std::string toInfix(const std::string &expression);
    int clacInfix(const std::string &expression);

    std::string toPostfix(const std::string &expression);
    int clacPostfix(const std::string &expression);
};
