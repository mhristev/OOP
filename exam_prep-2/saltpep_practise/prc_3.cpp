#include <iostream>


using namespace std;


class Set;

class Container{
    string model; //California baby 1987
    string type; // salt or pepper
    string serialNumber; //serialNumber = serialNumber na modela
    int capacity; //capasity na modela
public:
    Container(string name, string type, string num, int capacity){
        this->model = name;
        this->type = type;
        this->serialNumber = num;
        this->capacity = capacity;
    }

    string getserialnum()const{
        return serialNumber;
    }

    friend Set;
    friend Set* operator+(const Container& first, const Container& second);

};

class Model{
public:
    string name;
    static int serialNumber;
    int capacity;
public:
    Model(string name, int capacity){
        this->name = name;
        this->capacity = capacity;
    }

    static Container* produce(Model& model, string type){
        return new Container(model.name, type, to_string(model.serialNumber++), model.capacity);
    }

    friend Set;
};




class Set{
    const Container* salt;
    const Container* pepper;
    string serialNumber; // num na salt : num na pepper
public:
    Set(const Container* salt, const Container* pepper){
        this->salt = salt;
        this->pepper = pepper;
        this->serialNumber = (salt->getserialnum() + ":" + pepper->getserialnum());
    }

    Set(const Set& source){
        this->salt = source.salt;
        this->pepper = source.pepper;
        this->serialNumber = source.serialNumber;
        cout << "Copy Constructor called" << endl;
    }

    void print(){
        cout << "We have " << salt->model << " " << salt->type << " capacity: " << salt->capacity << " gr. with serial number " << salt->serialNumber << endl;
        cout << "We have " << pepper->model << " " << pepper->type << " with serial number " << pepper->serialNumber << endl;
        cout << "Set serial number: " << serialNumber << endl;
    }

};



int Model::serialNumber = 1000;

Set* operator+(const Container& first, const Container& second){
        return new Set(&first, &second);    

}

int main(){

    Model model("Cali", 65);
    Container* c1 = Model::produce(model, "salt");
    Container* c2 = Model::produce(model, "pepper");

    Set *set = *c1 + *c2;
    set->print();
    Set new_set = *set;
    new_set.print();


}