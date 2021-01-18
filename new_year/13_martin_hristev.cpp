#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Sport {

public:
    virtual void print() = 0;
};


class IndividualSport : public Sport {
    string name;
    string win_cond;
public:
    IndividualSport(string name, string wincond): name(name), win_cond(wincond) {}

    void print() {
        cout << "Individual Sport: " << name << ", winner determinated by: " << win_cond << endl;
    }

};

class TeamSport : public Sport {
    string name;
    int players;
public:
    TeamSport(string Sname, int num) : name(Sname), players(num) {}

    void print() {
        cout << "TeamSport: " << name << ", players: " << players << endl;
    }
};


class User {
    string username;
    string name;
    vector<Sport*> sports;
public:
    User(string username_): username(username_) {}

    User& setName(string real_name) {
        this->name = real_name;
        return *this;
    }

    string getName() {
        return name;
    }

    User& addSport(Sport& sport){
        sports.push_back(&sport);
        return *this;
    }

    vector <Sport*> getSports() {
        return sports;
    }

    string getUsername() {
        return username;
    }
    
    vector <IndividualSport*> indivSports() {
        vector <IndividualSport*> sports;
        for (auto t : sports) {
           IndividualSport *s = dynamic_cast<IndividualSport*>(t);
            if (s) {
                sports.push_back(s);
            }
        }
        if (sports.empty()) 
            cout << "we did not find individual sports!" << endl;
        return sports;
    }

};

class Server {
    vector<User*> users;

public:
    User& addUser(string username) {
        User *usr = new User(username);
        users.push_back(usr);
        return *usr;
    }

    void listUsersWithSports() {
        for (auto i : users) {
            cout << "User: " << i->getName() << ", username: " << i->getUsername() << endl;
            cout << "Practices: " << endl;
            for (auto t : i->getSports()) {
                t->print();
            }
        }
    }
    ~Server() {
        for (auto i : users) {
            delete i;
        }
    }


};



int main() {
    Server server;

    IndividualSport sport1("10-mile run", "time");
    IndividualSport sport2("Pool", "score");
    TeamSport sport3("Football", 5);

    User& user = server.addUser("zapbulon");

    user.setName("Lubo Varbanov")
        .addSport(sport1)
        .addSport(sport2)
        .addSport(sport3);

    server.listUsersWithSports();
    /*
        Горната линия да извежда в терминала следното:

        User Lubo Varbanov, username zapbulon
            Practices:
            Individual sport: 10-mile run, winner determined by time
            Individual sport: Pool, winner determined by score
            Team sport: Football, 5-a-side
    */

    return 0;
}