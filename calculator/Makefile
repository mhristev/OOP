all: calculator

# operator.o: operator.hpp
# operatorplus.o: operatorplus.hpp
calculator.o: calculator.hpp calculator.cpp
main.o: main.cpp operator.hpp operatorplus.hpp operatorminus.hpp operatordivide.hpp operatormultiply.hpp operatorfactoriel.hpp operatornegate.hpp calculator.hpp

calculator: main.o calculator.o
	g++ main.o calculator.o -o calculator

clean:
	rm -f *.o calculator
