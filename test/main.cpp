#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
// Бях си забравил зарядното и компютърът ми умря в средата на часа

class MenuItem{
    int type; 
    string name;
    double price;

    public:
        MenuItem(int my_type, string my_name, double my_price){
            if(my_type == 0 || my_type == 1){
                this->type = my_type;
                this->name = my_name;
                this->price = my_price;
            }else{
                throw "Invalid type!";
                exit(1);
            }
            
        }

        int getType(){
            return type;
        }
};


class TableOrder{
    
    list <MenuItem> items;

    public:
        TableOrder(){
            cout << "Bread" << endl;
        }
    
        void order(MenuItem my_item){
            if(my_item.getType() == 0){
                cout << "This is a drink!" << endl;
                items.push_front(my_item);
            }else{
                cout << "This is a dish!" << endl;
                items.push_back(my_item);
            }
        }



};

class Waiter{
    public:
        string name;
        vector <TableOrder> orders;

};


int main(){
    try{
        TableOrder order1;
        MenuItem item1 = MenuItem(0, "Cola", 1.20);
        order1.order(item1);

        Waiter w1;
        w1.name = "Name";
        //w1.orders.push_back(order1.items);

       /* vector <MenuItem> result;
        for (MenuItem c: order1.items) {
            w1.items.push_back(c);
        }

        for (int i = 0; i < result.size(); i++) {
		    cout << result[i].getType();
	    }

       // w1.orders = order1.getItems();

    */

    




    }catch(const char* error){
        cout << error << endl;
    }
    return 0;
}




