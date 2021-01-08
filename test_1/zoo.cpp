#include <iostream>
#include <vector>

using namespace std;

class Animal{
    int id;
    string name;
    int age;
    double monthlyExpenses;
    string type;

    public:
        Animal(int id, string name, int age, double monthlyExpenses, string type){
            this->id = id;
            this->name = name;
            this->age = age;
            this->monthlyExpenses = monthlyExpenses;
            this->type = type;
        }

        int getID(){
            return this->id;
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        double getExpenses(){
            return this->monthlyExpenses;
        }
        string getType(){return this->type;}

};

class Cage{
    int id;
    vector <Animal> animals_in_cage;
    int capacity;
    string type_in_cage;

    public:
        Cage(int id, int capacity, string type){
            this->id = id;
            this->capacity = capacity;
            this->type_in_cage = type;
        }

        int getID() {return this->id;}
        int getCapacity() { return this->capacity;}
        string getType_in_cage() {return this->type_in_cage;}

        void setID(int id) {this->id = id;}
        void getCapacity(int capacity) {this->capacity = capacity;}
        void getType_in_cage(string type) {this->type_in_cage = type;}

        void addAnimal(Animal animal){
            if(animals_in_cage.capacity() == capacity){
                throw("The cage is full");
                return;
            }
            if(type_in_cage != animal.getType()){
                throw("This type of animal is not for this cage!");
            }else{
                animals_in_cage.push_back(animal);
            }
        }

        double getMonthlyTotal(){
            cout << "There are " << animals_in_cage.capacity() << " " << type_in_cage << " here!" << endl;
            double total = 0;

            for(int i = 0; i < animals_in_cage.capacity(); i++){
                total += animals_in_cage[i].getExpenses();
            }

            return total;

        }
        int getRemainCapacity(){
            return (capacity-animals_in_cage.capacity());
        }

};

int main(){
    try{
        Animal ani1(1, "Petar", 3, 10.50, "los");
        Animal ani2(2, "Ivan", 3, 10.50, "los");
        Animal ani3(3, "dragan", 3, 10.50, "los");
        Animal ani4(4, "Ivan", 3, 10.50, "penguin");

        Cage cage1(1, 2, "los");
        cage1.addAnimal(ani1);
        cout << "Remain capacity: " << cage1.getRemainCapacity() << endl;
        cage1.addAnimal(ani2);
        cout << "Remain capacity: " << cage1.getRemainCapacity() << endl;
        cout << cage1.getMonthlyTotal() << endl;
    }catch(const char* error){
        cout << error << endl;
    }
}