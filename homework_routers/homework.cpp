#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cstring>
#include <unistd.h>
#include <fstream>

using namespace std;


class Package{
    string content;
    int lenght;
    string IP_sender;
    string IP_receiver;
    static int instances;
    int package_number;

public:
    Package(string content, string IP_sender, string IP_receiver){
        
        if(content.length() == 2){
            throw("The package content is empty!");
        }
        if(IP_sender == "0.0.0.0" || IP_sender == "127.0.0.0" || IP_receiver == "0.0.0.0" || IP_receiver == "127.0.0.0"){
            throw("Check your IP adresses!");
        }else{
            this->content = content;
            this->lenght = sizeof(content);
            this->IP_sender = IP_sender;
            this->IP_receiver = IP_receiver;
            this->package_number = instances;
            instances++;
        }
    }
        int validate(){
            int content_lenght = sizeof(content)/sizeof(char);
            if(content_lenght == lenght)
                return 1;
            else
                return 0;
        }
        int getNumber()const{ return this->package_number;}

        string getIP_receiver()const{return this->IP_receiver;}


    
};

class Router{
    string name;
    string IP_adress;
    vector <Router*> connected_routers;
    list < map< string,pair<int, int>> > routing_table; // string - IP, (int  = index in vector, int = sent packets)
    const static int max_elements_in_route;
    const static int hops;
public:
        Router(string name, string IP_adress){
            this->name = name;
            this->IP_adress = IP_adress;
        }
        string getName(){
            return this->name;
        }
        string getIP_adress(){
            return this->IP_adress;
        }
        vector<Router*> getConnected_routers(){
            return this->connected_routers;
        }

        list <map< string,pair<int, int>>> getRouting_table(){
            return this->routing_table;
        }


        void add_router(Router& router){
            if(router.IP_adress == "0.0.0.0" || router.IP_adress == "127.0.0.0"){
                throw "Invalid router!";
            }
            connected_routers.push_back(&router);
            connected_routers[connected_routers.size()-1]->connected_routers.push_back(this);
        }

        int query_route(const string adress, const int hop_count){
            if(this->IP_adress == adress){
                cout << "found" << endl;
                return 1;
            }
            // check if the IP is in the list of known routes
            list<map<string, pair<int, int>>>:: iterator it;
            for(it = routing_table.begin(); it != routing_table.end(); it++){
                for(auto i : (*it)){
                    if(i.first == adress){
                        return 1;
                    }
                }
            }
            // Ask connected routers in the vector if they know this IP adress
            if(hop_count > 1){
                for(int i = 0; i < connected_routers.size(); i++){
                    if(connected_routers[i]->query_route(adress, (hop_count-1)) == 1){
                        map <string, pair<int, int>> mymap;
                        if(routing_table.size() != max_elements_in_route){
                            mymap[adress] = make_pair(i, 0);
                            routing_table.push_back(mymap);
                            cout << "added in the routing table" << endl;
                            return 1;
                        }else{
                            routing_table.pop_back();
                            cout << "The route was full" << endl;
                            mymap[adress] = make_pair(i, 0);
                            routing_table.push_back(mymap);
                            cout << "added in the routing table" << endl;
                            return 1;
                        }
                    }
                              
                }
            }
            return 0;
        }

        void send_package(const Package& package){
            cout << "Current IP " << IP_adress << endl;
            if(package.getIP_receiver() == IP_adress){
                cout << "The package is in the right place!" << endl;
                return;
            }
            int packets = 0;
            int num;
            cout << "Package number: " << package.getNumber()<< " destination IP: " <<package.getIP_receiver()<< endl;
            list<map<string, pair<int, int>>>:: iterator it;
                for(it = routing_table.begin(); it != routing_table.end(); ++it){
                  for(auto i : (*it)){
                    packets = packets + i.second.second;
                 }
                    if(packets % 10 == 0){
                            routing_table.sort();
                        }    
                }             
            for(it = routing_table.begin(); it != routing_table.end(); ++it){
                cout << "Looking for the ip in the list..." << endl;
                for(auto i : (*it)){
                    if(i.first == package.getIP_receiver()){
                        cout << "Router with the same IP found!" << endl;
                        int v_place = i.second.first; //proverka v lista dali imame tova ip i uvelichavame poluchenite paketi ot nego
                        int pak = i.second.second;
                        (*it)[package.getIP_receiver()] = make_pair(v_place, pak+1);
                        num = i.second.first;
                        cout << "Index in the vector found...Sending the package..." << endl;
                        cout << connected_routers[num]->IP_adress << endl;
                        cout << package.getIP_receiver() << endl;
                        connected_routers[num]->send_package(package); 
                        cout << "Package sent!" << endl;
                        return ;
                    }
                }
            }
            cout << "The IP is not in the list of routes" << endl;
            if((query_route(package.getIP_receiver(), hops)) == 1){
                cout << "We found route in the connected routers!" << endl;
                list<map<string, pair<int, int>>>:: iterator it;          
                for(it = routing_table.begin(); it != routing_table.end(); ++it){
                    for (auto i : (*it)){
                        if(i.first == package.getIP_receiver()){
                            cout << "Router with the same IP in the vectors!" << endl;
                            int v_place = i.second.first; //proverka v lista dali imame tova ip i uvelichavame poluchenite paketi ot nego
                            int pak = i.second.second;
                            (*it)[package.getIP_receiver()] = make_pair(v_place, pak+1);
                            num = i.second.first;
                            cout << "We found the router index in the vector, now sending the package..." << endl;
                            connected_routers[num]->send_package(package); //prashtame paketa na rutera
                            cout << "Package sent!" << endl;
                            return;
                        }
                    }   
                }
            }else{
                cout << "The route doesnt exist, the package is destroyed!" << endl;
                return;
            }
        }

    friend void print_routes(vector<Router*> &routers);
    friend void print_vector(vector <Router*> &routers);


};


void read_routers(string filename, vector<Router*> &routers){
    ifstream in = ifstream(filename);
    string name;
    string ip;
    string real_name;
    int i = 1;
    if(in.is_open()){
        while(in >> name){
            if(i == 1){
                real_name = name;
                i++;
            } else if(i == 2){
                ip = name;
                Router* r = new Router(real_name, ip);
                routers.push_back(r);
                i = 1;
            }
        }   



        in.close();
    }
    
    cout << "Succesfully read routers!" << endl;
}

void read_network(string filename, vector<Router*> &routers){
    ifstream in = ifstream(filename);
    string name;
    string router2;
    string router1;
    int i = 1;
    if(in.is_open()){
        while(in >> name){
            if(i == 1){
                router1 = name;
                i++;
            } else if(i == 2){
                router2 = name;
                for(int k = 0; i < routers.size(); k++){
                    if(routers[k]->getName() == router1){
                        for(int p = 0; p < routers.size(); p++){
                            if(routers[p]->getName() == router2){
                                routers[k]->add_router(*routers[p]);
                            }
                        }
                        break;
                    }
                }
                i = 1;
            }
        }   



        in.close();
    }
    

    cout << "--------------------------" << endl;
    cout << "Succesfully read networks!" << endl;
}


void read_packets(string filename, vector<Router*> &routers){
    ifstream in = ifstream(filename);
    string name;
    string source_IP;
    string target_IP;
    string content;
    int i = 1;
    while(in.is_open()){
            if(i == 1){
                if(in >> name){
                    source_IP = name;
                    i++;
                    continue;
                }else{
                    break;
                }
            }else if(i == 2){
                in.ignore();
                in >> name;
                target_IP = name;
                i++;
                continue;
            }else if(i == 3){
                in.ignore();
                getline(in, content);
                Package* pac = new Package(content, source_IP, target_IP);
                for(int k = 0; k < routers.size(); k++){
                    if(routers[k]->getIP_adress() == source_IP){
                        cout << "------------------------------------" << endl;
                        cout << "Sending package from " << source_IP << " to " << pac->getIP_receiver() << endl;
                        routers[k]->send_package(*pac);
                        break;
                    }
                }
                i = 1;
                continue;
            }else{
                break;
                in.close();
            }
    }
    cout << "--------------------------" << endl;
    cout << "Succesfully read packets!" << endl;
}

void print_routes(vector<Router*> &routers){
    cout << "--------------------------------" << endl;
    for(int k = 0; k < routers.size(); k++){
    cout << "++Router number " << k+1 << endl;
    list<map<string, pair<int, int>>>:: iterator it;
        for(it = routers[k]->routing_table.begin(); it != routers[k]->routing_table.end(); ++it){
            for (auto i : (*it)){
                cout << "Ip: " << i.first << ", went trough the vector with index: " << i.second.first << ", packages: " << i.second.second << endl;
            }

        }
    }
}

void print_vector(vector <Router*> &routers){
    cout << "---------------------------------------------" << endl;
    for(int i = 0; i < routers.size(); i++){
        cout << routers[i]->IP_adress << " connected with: " << endl;
        for(int k = 0; k < routers[i]->connected_routers.size(); k++){
            cout << routers[i]->connected_routers[k]->IP_adress << endl;
        }
    }
}

int Package::instances = 1;
const int Router::max_elements_in_route = 3;
const int Router::hops = 2; //хопс се наглася в зависимост, най-дългия connection който имаме
// ако имаме Р1 свързан с Р2
// и Р2 с Р3
// за да изпратим от Р1 към Р3 трябва да мине през Р2, което прави хоповете да са 3 за трите рутера
// ако подам хопс, например 50 получавам една безкрайна рекурсия и започва да се върти от Р1 до Р2 после пак Р1 и се ресетват хоповете
// не мисля, че без да подавам името на предишния рутер, от който идва пакета е възможно да се фиксне тази рекурсия или поне аз не се сещам
// затова хоповете трябва да са <= на макс connected routers

int main(){
    try{
        vector <Router*> routers;
        read_routers("routers2.txt", routers);
        read_network("network2.txt", routers);
        read_packets("packages2.txt", routers);

        print_routes(routers); //print current routes for every router
        //print_vector(routers); //print connections between routers

    }catch(const char* error){
        cout << error << endl;
    }
}