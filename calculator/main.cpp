#include <iostream>
#include "calculator.hpp"
#include "operatorplus.hpp"
#include "operatorminus.hpp"
#include "operatordivide.hpp"
#include "operatormultiply.hpp"
#include "operatornegate.hpp"
#include "operatorfactoriel.hpp"

using namespace std;

int main() {
    Calculator calculator;

    OperatorPlus plus;
    OperatorMinus minus;
    OperatorMultiply multiply;
    OperatorDivide devide;
    OperatorNegate negate;
    OperatorFactoriel factoriel;

    calculator.registerOperator(plus);
    calculator.registerOperator(minus);
    calculator.registerOperator(devide);
    calculator.registerOperator(multiply);
    calculator.registerOperator(negate);
    calculator.registerOperator(factoriel);

    try {
        cout << calculator.process(4.0) << endl;
        cout << calculator.process('!') << endl;
    } catch (string ex) {
        cout << ex << endl;
    }

    return 0;
}