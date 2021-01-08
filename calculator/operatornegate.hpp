#ifndef OPERATOR_NEGATE_HPP
#define OPERATOR_NEGATE_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorNegate : public Operator::Unary {

public:
    OperatorNegate() : Operator::Unary("negate", '~') {}

    double calculate(double a) {
        return -a;
    }
};

#endif