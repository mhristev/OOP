#ifndef OPERATOR_DIVIDE_HPP
#define OPERATOR_DIVIDE_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorDivide : public Operator::Binary {

public:
    OperatorDivide() : Operator::Binary("divide", '/') {}

    double calculate(double a, double b) {
        if(b == 0){
            throw "You can't devide by zero!";
        }
        return a / b;
    }
};

#endif