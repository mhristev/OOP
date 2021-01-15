  
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main() {
    string name = "12.32.1";
    char * c = strdup(name.c_str());
    char* token;
    token = strtok(c, ".");
    token = strtok(NULL,".");
    token = strtok(NULL,".");
    cout << token << endl;
}