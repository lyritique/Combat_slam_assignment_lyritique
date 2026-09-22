#include <iostream>

double getValue (std::string label)
{
    std::cout << "请输入" << label ;
    double input {};
    std::cin  >> input;
    return input;
}

