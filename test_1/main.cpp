#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Visitor{
    string name;
    int age;

    public:
        Visitor();

        Visitor(string name, int age){
            this->name = name;
            this->age = age;
        }

        string getName(){ return this->name;}
        int getAge(){ return this->age;}

        void setName(string name){ this->name = name;}
        void setAge(int age){ this->age = age;}
};


class Group{
    vector <Visitor> group_members;

    public:
        int youngestMemberAge(){
            int age = group_members[0].getAge();
            for(int i = 1; i < group_members.size(); i++){
                if(age > group_members[i].getAge()){
                    age = group_members[i].getAge();
                }

            }

            return age;
        }

        vector <Visitor> getMembers(){ return this->group_members;}

        void add_member(Visitor visitor){
            this->group_members.push_back(visitor);
        }

};

class Section{
    string name;
    list <Group> waiting_groups;

    public:
        int queue(Group group){
            if(group.getMembers().size() < 2){
                throw("The group is too small! You should add more members!");
            }
		    if(group.youngestMemberAge() < 6){
                waiting_groups.push_front(group);
                return 0;
            }else{
                int count = 0;
                 
	            list <Group>::iterator it;
 
 	            for(it = waiting_groups.begin(); it != waiting_groups.end(); it++){
                    count += it->getMembers().size();
                }
                waiting_groups.push_back(group);
                return count;
            }
        }

        string getName(){return this->name;}
        void setName(string name){ this->name = name;}

        void printQueue(){
            list <Group>::iterator it;
            int p = 0;
 
 	            for(it = waiting_groups.begin(); it != waiting_groups.end(); it++){
                    cout << ++p << ". ";
                    for(int i = 0; i < it->getMembers().size(); i++){
                        cout << it->getMembers()[i].getName() << ", ";
                    }
                    cout << endl;
                }
                
        }
};


Group new_group_cin(){
     int num_members;
     Group new_group;
     string name;
     int age;


    while(!cin.eof() && cin.good()){ 
        cout << "How many members are in this group? ";
        cin >> num_members;
        if(num_members <= 1){
            throw("The group is too small!");
        }
        if(cin.eof() || !cin.good()) break;
        cin.ignore();
        for(int i = 1; i <= num_members; i++){

            cout << "what is the name of the " << i << " member? ";
            getline(cin, name);
            if(cin.eof() || !cin.good()) break;
            cout << "What is the age of the " << i << " member? ";
            cin >> age;
            if(cin.eof() || !cin.good()) break;
            cin.ignore();
            Visitor visitor(name, age);
            new_group.add_member(visitor);
        }
        break;
    }

    return new_group;
    
}


int main(){
try{
    Visitor v1("Ivan Petrov", 18);
    Visitor v2("Gergana Ivanova", 30);

    Visitor v3("Petar Petrov", 5);
    Visitor v4("Stoyana Ivanova", 30);

    Group gr1;
    gr1.add_member(v1);
    gr1.add_member(v2);

    //cout << "Youngest in gr1 " << gr1.youngestMemberAge() << endl;

    Group gr2;
    gr2.add_member(v3);
    gr2.add_member(v4);

    //cout << "Youngest in gr1 " << gr2.youngestMemberAge() << endl;


    Section my_section;
    my_section.queue(gr1);
    my_section.queue(gr2);
    my_section.queue(new_group_cin());
    my_section.printQueue();



}catch(const char* error){
    cout << error << endl;
}

    return 0;
}