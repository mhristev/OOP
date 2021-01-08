#include <iostream>


using namespace std;

class Set{
    Container c_salt;
    Container c_pepper;
    string serialnumber;


}

class Container{
    string model;
    string type;
    string id;

    public:
        Container(){}
        Container(string model, string type){
            this->model = model;
            this->type = type;
        }
        Container(string model, string type, string id){
            this->model = model;
            this->type = type;
            this->id = id;
        }

};

class Model{
    string name;
    float capacity;

    static int serialNumber;

    public:
        static Container* produce(Model& model, string type){
            new Container(model.name, model.capacity, type)
        } //static metods outside
};

