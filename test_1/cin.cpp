#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;


int main(){
    /*
    string name;
    getline(cin,name); 
    cin.ignore();
    cout << name << endl;
    */

   int num;
   string name;
   cout << "enter your favourite number: ";
   cin >> num; // slagame v num vuvedenata informacia, no v cin ostava '\n'
   cout << "enter your name:";
   cin.ignore(); // ignore-va edin character v tozi sluchai '\n'
   getline(cin, name); //kogato stigen do getline toi vijda che v cin ima neshto a imenno '\n' i go skip-va

   cout << "Your number: " << num << endl
   << "Your name: " << name << endl;
   
}