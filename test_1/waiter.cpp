#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MenuItem{
    int type; // 0 for drink 1 for dish
    string name;
    float price;

    public:
        MenuItem(int type, string name, double price){
            this->type = type;
            this->name = name;
            this->price = price;
        }

        int getType(){
            return this->type;
        }

        string getName(){
            return this->name;
        }
};

class TableOrder{ // 1 table = 1 order
    public:
    list <MenuItem> order;

    public:
        TableOrder(){
            //cout << "bread" << endl;
        }
    
    void add_item(MenuItem &new_order){
        if(new_order.getType() == 0){
            //cout << new_order.getName() << endl;
            this->order.push_front(new_order);
            //cout << "check3" << endl;
        }else
            this->order.push_back(new_order);
        
    }

    list <MenuItem> getOrders(){
        return this->order;
    }    
};



class Waiter{
    public:
    string name;
    vector <TableOrder> table_orders;

    public:
        Waiter(string name){
            this->name = name;
        }

        vector<TableOrder> getTable(){
            return this->table_orders;
        }

        string getName(){
            return this->name;
        }
    
};

void order(Waiter waiter, int table){
        int type;
        string name;
        float price;
        float check = 0;
        TableOrder orders;

    while(!cin.eof() && cin.good()){ 
        cout << "0 for drink, 1 for food: ";
        cin >> type;
        if(cin.eof() || !cin.good()) break;
        cin.ignore();
        cout << "What's the name?: ";
        getline(cin, name);
        if(cin.eof() || !cin.good()) break;
        cout << "What's the price?: ";
        cin >> price;
        if(cin.eof() || !cin.good()) break;
        check += price;
        MenuItem item(type, name, price);
        orders.add_item(item);
    }
    waiter.table_orders.push_back(orders); 
    cout << endl <<"Your waiter name is " << waiter.getName() << " and your order is:" << endl;
    
    list <MenuItem>::iterator it;
 
    for(it = orders.order.begin(); it != orders.order.end(); ++it){

        cout << it->getName() << "(" << it->getType() << ")" << endl;
    }
    cout << "Total price is: " << check << endl;
}




int main(){
    Waiter waiter("petar");
    order(waiter, 0);
   
    
    //MenuItem item(1, "pepsi", 2.50);
    //TableOrder table;
    //table.add_item(item);
    //waiter.table_orders.push_back(table);
    //waiter.table_orders[0].order.push_front(item);
    //print_table(waiter, 0);

return 0;
}