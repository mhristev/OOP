#include <iostream>


using namespace std;

class Set;

class Container{
    string model_name;
    string type; //salt or pepper
    int size; // = model size
    string id;
public:
    Container(string model_name, string type, int size, string id){
        this->model_name = model_name;
        this->type = type;
        this->size = size;
        this->id = id;
    }

    friend Set;

    friend Set* operator+(const Container& second);

    void operator++(int num){
        this->size += 1;
    }

    void operator+(int num){
        this->size += num;
    }

    friend ostream& operator<<(ostream& out, const Container& cont);

};

class Set{
    const Container* salt;
    const Container* pepper;
    string serialNumber;
public:
    Set(const Container* salt, const Container* pepper){
        this->salt = salt;
        this->pepper = pepper;
        this->serialNumber = (salt->id + ":" + pepper->id);
    }

    void print()const{
        cout << "We have " << salt->model_name << " " << salt->type << " capacity: " << salt->size << " gr. with serial number " << salt->id << endl;
        cout << "We have " << pepper->model_name << " " << pepper->type << " capacity: " << pepper->size << " with serial number " << pepper->id << endl;
        cout << "Set serial number: " << serialNumber << endl;
    }

};




class Model{
    string name;
    int size;
    static int id;
public:
    Model(string name, int size): name(name), size(size){}

    static Container* produce(Model& model, string type){
        return new Container(model.name, type, model.size, to_string(model.id++));
    }

};


int Model:: id = 2121;

Set* operator+(const Container& first, const Container& second){
        return new Set(&first, &second);
}

ostream& operator<<(ostream& out, const Container& cont) {
    out << "Container type: " << cont.type << endl;
    out << "Model name: " << cont.model_name << endl;
    out << "ID: " << cont.id << endl;
    out << "SIZE: " << cont.size << endl;
    return out;
}

int main(){
    Model model("Cali", 65);
    Container* c1 = Model::produce(model, "salt");
    Container* c2 = Model::produce(model, "pepper");
    (*c2)+5;
    cout << *c2;
    Set* set = *c1 + *c2;
    set->print();

}