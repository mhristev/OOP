#ifndef OPERATOR_MULTIPLY_HPP
#define OPERATOR_MULTIPLY_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorMultiply : public Operator::Binary {

public:
    OperatorMultiply() : Operator::Binary("multiply", '*') {}

    double calculate(double a, double b) {
        return a * b;
    }
};

#endif