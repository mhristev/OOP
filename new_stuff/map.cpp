#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

class Foo {
public:
    int a;
    Foo() {}
    Foo(int b) : a(b % 3) {}
};

ostream& operator<<(ostream& out, const Foo& foo) {
    out << "Foo(" << foo.a << ")";

    return out;
}

// https://en.cppreference.com/w/cpp/container/map
// std::map is a sorted associative container that contains key-value pairs with unique keys

int main() {
    /*
    map<char, Foo> foo;

    foo['c'] = Foo(3);
    foo.insert({'a', Foo(2)});
    foo['b'] = Foo(7);

    for (auto element : foo) {
        cout << element.first << ": " << element.second << endl;
    }

    pair<int, char> p = {2, 'b'};
    cout << endl << p.first << ": " << p.second << endl;


    map<string, int> mymap;
    mymap["day"] = 12;
    mymap["month"] = 3;
    mymap["year"] = 1900;

    for(auto i : mymap){
        cout << i.first << " : " << i.second << endl;
    }
*/
    

    map<string,pair<int,int>> mymap;
    mymap["day"] = make_pair(13, 12);
    mymap["month"] = make_pair(15, 14);

     for(auto i : mymap){
        cout << i.first << " : " << i.second.first << " : " << i.second.second << endl;
    }



}