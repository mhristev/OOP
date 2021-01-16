  
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main() {
    string name = "s.321";
    char * c = strdup(name.c_str());
    char* token;
    char *p;
    token = strtok(c, ".");
    int a = strtol(token, &p,10);
    cout << a << endl;
    token = strtok(NULL,".");
    token = strtok(NULL,".");
    if(token) {
        cout << token << endl;
    } else {
        cout << "Third dot not found!" << endl;
    }
}