#include <iostream>

using namespace std;

class Weapon {
public:
    int* uses;
    static int instances;

    Weapon(string type){
        if(type == "rev"){
            //cout << "we are in the rev" << endl;
            this->uses = new int[1];
            uses[0] = 12;
        }

        if(type == "double barrel"){
            //cout << "We are here in the double barrel" << endl;
            this->uses = new int[2];
            uses[0] = 12;
            uses[1] = 12;
        }

        instances++;
    }


    ~Weapon(){
        cout << "Before Destructor" << endl;
        if(sizeof(uses) == 4){
            cout << this->uses[0] << endl;
        }else{
            cout << this->uses[0] << endl;
            cout << this->uses[1] << endl;
        }
        delete [] this->uses;
        
        instances--;
    }

};

int Weapon::instances = 0;

int main(){
    Weapon w1("rev");
    Weapon w2("double barrel");

    //cout << w1.uses[0] << endl;w


}
