#include <iostream>
using namespace std;

class Vehicle {
public:
    enum TwoAxleDrives { FRONT, REAR, ALL, NONE };
    enum TwoAxleVehicles { BIKE, CAR, TRAILER };
private:
    TwoAxleVehicles type;
    TwoAxleDrives drive;

    float km;
public:
    int getKM(){
        return km;
    }

  static Vehicle* factory(TwoAxleVehicles type, TwoAxleDrives drive){
     Vehicle* new_vehicle = new Vehicle;
     new_vehicle->type = type;
     new_vehicle->drive = drive;

     return new_vehicle;
  }
  static Vehicle* factory(TwoAxleDrives drive){
      Vehicle* new_vehicle = new Vehicle;
      new_vehicle->drive = drive;
      new_vehicle->type = NONE;
  }

    void operator ()(int km){
        this->km = km;
    }

};

int main() {
    Vehicle* bike = Vehicle::factory(Vehicle::BIKE);
    Vehicle* bmw = Vehicle::factory(Vehicle::CAR, Vehicle::REAR);

    // let's drive it
    (*bmw)(100.8);

    cout << "BMW, " << bmw->getKM() << "km" << endl; // BMW, 100.8km

    delete bike, bmw;
}