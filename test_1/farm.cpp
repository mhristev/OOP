#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Niva{
    private:
    string type;
    int kolichestvo;
    int nujni_rabotnici;

    public:
    Niva(string type, int kolichestvo, int rabotnici){
        this->type = type;
        this->kolichestvo = kolichestvo;
        this->nujni_rabotnici = rabotnici;
    }

    string getType(){
        return this->type;
    }

    int getKolichestvo(){
        return this->kolichestvo;
    }

    int getRabotnici(){
        return this->nujni_rabotnici;
    }
};

class Ferma{
    public:
    list <Niva> nivi;
    int rabotnici;
    string name;


    void add_field(Niva niva){
        nivi.push_back(niva);
    }



    int get_production(string type){
        int production = 0;
        int nezaetost = this->rabotnici;
        cout << "svobodni rabotnici: " << nezaetost << endl;
        bool exist = false;
        if(nivi.size() == 0){
            throw("Nivite sa prazni");
        }
        list <Niva>::iterator it;
    
            for(it = nivi.begin(); it != nivi.end(); it++){
                if((*it).getType() == type){
                    if(nezaetost >= (*it).getRabotnici()){
                        production += (*it).getKolichestvo();
                        nezaetost -= (*it).getRabotnici();
                        exist = true;
                    }
                }
            }
            if(exist == false){
                throw("There is nothing like this in the farm");
            }
            cout << "svobodni rabotnici: " << nezaetost << endl;
            return production;
    }
};

void test(Ferma &farm){

        while(!cin.eof() && cin.good()){
            string type;
            int kolichestvo;
            int workers;
            cout << "Enter field type: ";
            getline(cin, type);
            if(cin.eof() || !cin.good()) return;


            cout << "Enter produced kolichestvo: ";
            cin >> kolichestvo;

            if(cin.eof() || !cin.good()) return;

            cout << "Enter needed workers: ";
            cin >> workers;
            if(cin.eof() || !cin.good()) return;
            cin.ignore();

            farm.add_field(Niva(type, kolichestvo, workers));   
     }



}





int main(){
    try{
        Niva niva1("tomato", 10, 10);
        Niva niva2("weat", 10, 10);
        Niva niva3("potato", 10, 10);
        Niva niva4("weat", 10, 10);

        Ferma farm;
        test(farm);
        farm.rabotnici = 15;
        farm.nivi.push_back(niva1);
        farm.nivi.push_back(niva2);
        farm.nivi.push_back(niva3);
        farm.nivi.push_back(niva4);

        cout << farm.get_production("weat") << endl;
        

        list <Niva>::iterator it;
 
 	    for(it = farm.nivi.begin(); it != farm.nivi.end(); it++){
		    cout << (*it).getType() << " - " << (*it).getKolichestvo() << " - " << (*it).getRabotnici() << endl;
        }




    }catch(char const* error){
        cout << error << endl;
    }
}