#include <iostream>

using namespace std;

class smallFoo{
    string name;
public:
    smallFoo():name("Ivan"){}
    smallFoo(string name): name(name){}

    smallFoo(const smallFoo& source){
        cout << "Copy Constructor!" << endl;
        this->name = source.name;
        
    }
    
    void operator=(const smallFoo& second){
        this->name = second.name;
    }
    string getname()const{
        return this->name;
    }

};

class Foo{
public:
    smallFoo *array;
    int capacity;
    int full;
public:
    Foo(int size){
        this->capacity = size;
        this->full = 0;
        this->array = new smallFoo[size]; 
    }


    void add_smallFoo(){
        const smallFoo* mini = new smallFoo("Testing");
        array[full] = *mini;
        full++;
    }

    ~Foo(){
        delete [] array;
    }

};


int main(){
    Foo foo(10);
    foo.add_smallFoo();
    cout << foo.array[0].getname() << endl;

}