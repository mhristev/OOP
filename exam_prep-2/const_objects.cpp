#include <iostream>

using namespace std;

class Foo{
    int x;
    int y;
public: 
    Foo(int x, int y) : x(x), y(y){}

    int getX()const{
        return this->x;
    }

    void setX(int x){
       this->x = x;
    }

   // friend void printconst(const Foo& foo);
};

void print(Foo& foo){
    cout << "x = " << foo.getX() << endl;
}

void printconst(const Foo& foo){
    cout << "x = " << foo.getX() << endl;
}



int main(){
    Foo foo(1, 2);
    const Foo foo2(5, 6);

    cout << foo.getX() << endl;
    foo.setX(100);
    print(foo);


    printconst(foo);


}