#ifndef OPERATOR_FACTORIEL_HPP
#define OPERATOR_FACTORIEL_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorFactoriel : public Operator::Unary {

public:
    OperatorFactoriel() : Operator::Unary("factoriel", '!') {}

    double calculate(double a) {
        int b = int(a);
        double result = 1;
        for(int i = b; i != 0; --i){
            result = result * i;
        }
        return result;
    }
};

#endif