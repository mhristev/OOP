  
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;


int main() {
    string name = "12.adsd.12";
    char * c = strdup(name.c_str());
    char* token;
    char *p;
    token = strtok(c, ".");
     
while(token) {
    for (int i = 0; i < sizeof(token); i++) {
        cout << token[i] << endl;
        if (isdigit(token[i])) {
            cout << "yes" << endl;
        } else {
            cout << "no " << endl;
        }
    }

    token = strtok(NULL,".");

}
    
    if(token) {
        cout << token << endl;
    } else {
        cout << "Third dot not found!" << endl;
    }
}