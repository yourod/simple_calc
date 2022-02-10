#ifndef CALCULATE_H
#define CALCULATE_H


#include <iostream>
#include <list>
#include <algorithm>
#include <string>
class calculate
{
public:
    calculate();
    void separation(std::string operation, std::list<std::string>& sep);
    void sum_and_substr(double& result, std::list<std::string>& sep);
    void dev_and_mult(double& result, std::list<std::string>& sep,int& check);
    void calculate_this(double& result, std::string operation,int& check);
};
#endif // CALCULATE_H
