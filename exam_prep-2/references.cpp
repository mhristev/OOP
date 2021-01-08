#include <iostream>
#include <vector>

using namespace std;

class Student {
    short age;
    string name;
    string team;

    Student* partner;

    void setPartner(Student& teammate) {
        this->partner = &teammate;
    }
public:
    Student(string name, short age) {
        this->name = name;
        this->age = age;
    }

    void setFavouriteTeam(string team) {
        this->team = team;
    }

    void reportPartner() {
        cout << partner->name << ", " << partner->age << ", fan of " << partner->team << endl;
    }

    static void pair(Student &a, Student &b) {
        a.setPartner(b);
        b.setPartner(a);
    }
};