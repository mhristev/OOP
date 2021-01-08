#include <iostream>

using namespace std;


class Shape{
    string name;
public:
    Shape(string name): name(name) {}

    virtual double getArea(){
        return 0;
    }

    string getName(){
        return name;
    }
};

class Square: public Shape{
    double a;
public:
    Square(string name, double a): Shape(name), a(a) {}

    virtual double getArea(){
        //cout << "S " << this->getName() << ": " << a*a << endl;
        return a*a;
    }

};

class Triangle: public Shape{
    double a;
    double b;
    double c;
public:
    Triangle(string name, double a, double b, double c): Shape(name), a(a), b(b), c(c) {}

    virtual double getArea(){
        //cout << "S " << this->getName() << ": " << (a*b)/2 << endl;
        return (a*b)/2;
    }

};

void print_area(Shape& s){
    cout << "S " << s.getName() << ": " << s.getArea() << endl;
}

int main(){
    Square sqr("square", 4);
    

    Triangle triangl("triagl", 5, 2, 3);
    print_area(triangl);
    print_area(sqr);
}