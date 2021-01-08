#include <iostream>
#include <vector>

using namespace std;




class Router{
public:
    string IP;
    vector <Router*> routers;

public:
    Router(string name): IP(name) {}

    string getIP(){
        return IP;
    }

    void add_router(Router& router){
        routers.push_back(&router);
        routers[routers.size()-1]->routers.push_back(this);

    }

};



int main(){
    Router router1 = Router("1.0.0.0");
    Router router2 = Router("2.0.0.0");
    Router router3 = Router("3.0.0.0");

    router1.add_router(router2);
    router2.add_router(router3);

    cout << router2.routers[0]->IP << endl;
    cout << router2.routers[1]->IP << endl;
    cout << router3.routers[0]->IP << endl;




}