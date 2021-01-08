#include <iostream>
#include <map>

using namespace std;

enum ItemType { ROCK, STICK, AXE };

struct ItemProperties {
    string name;
    bool stackable;
    short stackSize;
    short uses;
};

class Item {
    ItemType type;
    short count;
    short durability;
public:
    const static map<ItemType, ItemProperties> types;

    short getCount(){
        return count;
    }

    Item(ItemType type) {
        this->type = type;
        this->count = 0;
        this->durability = this->types.at(type).uses;
    }

    
    Item& operator+=(int count){
        this->count += count;
        return *this;
    }

    Item& operator++(int){
        this->count = this->count + 1;
        return *this;
    }

    Item operator+(Item& add){
        this->count--;
        add.count--;
        
        Item new(AXE);
        new++;
        return new;
        
    }

    friend ostream& operator<<(ostream& out, const Item& item){
        out << 
    }
    
};

const map<ItemType, ItemProperties> Item::types = {
    { ROCK,  { "rock",  true,  10,  1 } },
    { STICK, { "stick", true,  20,  1 } },
    { AXE,   { "axe",   false,  1, 10 } },
};

/*  <--- operator overload definitions here --->  */

int main() {
    Item rock   = Item(ROCK);
    Item stick  = Item(STICK);

    rock += 5;
    cout << rock.getCount() << endl;
    /*
    stick++;асдсад

    cout << rock << endl    // Item: rock, count 5, uses 1/1
         << stick << endl;  // Item: stick, count 1, uses 1/1

    Item axe = rock + stick;

    cout << rock << endl    // Item: rock, count 4, uses 1/1
         << stick << endl   // Item: stick, count 0, uses 1/1
         << axe << endl;    // Item: axe, count 1, uses 10/10
*/
}