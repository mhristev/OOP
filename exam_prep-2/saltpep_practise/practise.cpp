#include <iostream>
using namespace std;

class BigFoo;

class miniFoo{
    string name;
public:
    miniFoo() : name("Ivan") {}
    miniFoo(string name) : name(name) {}
    miniFoo(const miniFoo& source){
        cout << "Copy constructor called" << endl;
        this->name = source.name;
    }

    void operator=(miniFoo& small){
        this->name = small.name;
    }

    friend BigFoo;

};

class BigFoo{
    miniFoo *array;
    int capacity;
    int full;
public:
    BigFoo(int capacity){
        this->capacity = capacity;
        this->full = 0;
        array = new miniFoo[capacity];
    }

    BigFoo(const BigFoo& source){
        cout << "Copy constructor of BigFoo" << endl;
        this->capacity = source.capacity;
        this->full = source.full;
        this->array = new miniFoo[source.capacity];
        for(int i = 0; i < source.full; i++){
            array[i].name = source.array[i].name;
        }
    }

    void add_small(string name){
        miniFoo* mini = new miniFoo(name);
        array[full] = *mini; 
        full++;
    }

    void print(){
        for(int i = 0; i < capacity; i++){
            cout << array[i].name << endl;
        }
    }



    ~BigFoo(){
        delete [] array;
    }


};




int main(){

    BigFoo test(10);
    test.add_small("Martin");
    test.add_small("Petar");
    BigFoo test2 = test;
    test2.print();


}



//otkude e tazi sol










