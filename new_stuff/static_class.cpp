#include <iostream>
#include <vector>

using namespace std;

class Student {
   string name;
   static int position;
   static int state;
public:
    Student(string name){
        this->name = name;
        state++;
    }
    void reportPosition(){ 

        cout << position << "!" << endl;
        if(position >= 2)
            position = 1;
        else
            position++;
        
     }
    void reportState(){ 
        cout <<"I'm "<< this->name << " and there is " <<  this->state << " of us" << endl;
    }
};

int Student :: position = 1;
int Student :: state = 0;

int main() {
    Student s1 = Student("John");
    Student s2 = Student("George");
    Student s3 = Student("Bill");
    
    s1.reportPosition(); // 1!
    s2.reportPosition(); // 2!
    s3.reportPosition(); // 1!

    s3.reportState(); // I'm Bill and there is 3 of us
}