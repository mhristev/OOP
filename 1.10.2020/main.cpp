#include <iostream>
#include <cstring>
using namespace std;


class Student{
	char* name;
	int age;
	
	public:
	
	char* getName(){
		return name;
	}
	
	Student(string name, int age){
		strcpy(this->name,name);
		this->age = age;
	}
	
	int getAge(){
		return age;
	}
	
	void setName(char* name){
		strcpy(this->name, name);
	
	}
	
	void setAge(int age){
		this->age = age;		
	}
};


int main(){
	Student s1 = Student("Ivan", 17);

}
