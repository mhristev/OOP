#include <iostream>
using namespace std;

class Vehicle {
public:
    enum Drive { FRONT, REAR, ALL, NONE };
    enum Type { BIKE, CAR, TRAILER, TRUCK };
private:
    class Tire {
    public:
        int wear;
        Tire() : wear(0) {}
    };

    Type type;
    Drive drive;

    float km;

    Tire* axles;
public:

    friend ostream& operator<< (ostream& out, const Vehicle& source);

    static Vehicle* factory(Type type, Drive drive){
     Vehicle* new_vehicle = new Vehicle;
     new_vehicle->type = type;
     new_vehicle->drive = drive;

     return new_vehicle;
  }

  void operator ()(int km){
        this->km = km;
        if(this->type == CAR){
            this->axles = new Tire[2];
            axles[0].wear += km;
            axles[1].wear += km*1.2;
        }else if(this->type == TRUCK){
            this->axles = new Tire[3];
            axles[0].wear = km;
            axles[1].wear = km;
            axles[2].wear = km;
        }

    }
};

ostream& operator << (ostream& out, const Vehicle& source){
    if(source.axles == sizeof(int) * 2){
        out << "Front: " << source.axles[0] << " Rear: " << source.axles[1];  
    }
}

int main() {
    Vehicle* bmw = Vehicle::factory(Vehicle::CAR, Vehicle::REAR);
    Vehicle* truck = Vehicle::factory(Vehicle::TRUCK);

    // let's drive them
    (*bmw)(120);
    (*truck)(120);

    cout << *bmw << endl; // front: 120; rear: 144;
    cout << *truck << endl; // front: 120; middle: 120; rear: 120;

    cout << "Truck middle axle tires wear: " << (*truck)[1].wear << "km" << endl; // Truck middle axle tires wear: 120km

    delete bmw;
}