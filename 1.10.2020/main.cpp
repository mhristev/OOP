#include <iostream>
#include <cstring>
using namespace std;


class Student{
	string name;
	int age;
	
	public:
	
	string getName(){
		return name;
	}
	
	Student(string name, int age){
		this->name = name;
		this->age = age;
	}
	
	int getAge(){
		return age;
	}
	
	void setName(string name){
		this->name = name;
	
	}
	
	void setAge(int age){
		this->age = age;		
	}
};


int main(){
	Student s1 = Student("Ivan", 17);

}
