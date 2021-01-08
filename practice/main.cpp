#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

int main () {
    vector<int> v;

    cout << boolalpha << "Initial size of vector is " << v.size() << endl; // Vector information
    cout << "Initial capacity of vector is " << v.capacity() << endl;
    cout << "Is it empty - vector? " << v.empty() << endl << endl; 
         
         v.push_back(2);
    	 v.push_back(3);
    	 v.push_back(4);
    
    for (int i=0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
//-----------------------------------------------------------------------------------------------------------     
      stack<int> stak;
      cout << boolalpha << "Initial size of stack is " << stak.size() << endl; // Stack information
      cout << "Is it empty - stack? " << stak.empty() << endl << endl; 
         
         stak.push(2);
    	 stak.push(3);
    	 stak.push(4);
    	 
    	 
    for (int i=0; i < v.size(); i++) {
       	int x = stak.top();
       	cout << x << endl;
       	stak.pop();
    }
 //------------------------------------------------------------------------------------------------------------ 
  list <int> my_list;
  
   cout << "Initial size of list is " << my_list.size() << endl; // List information
   cout <<"Is it empty - list? "  << my_list.empty() << boolalpha << endl << endl;
    
   		 my_list.push_back(2);
    	 my_list.push_back(3);
    	 my_list.push_back(4);
    	 
  
  
	list <int>::iterator it;
 
 	for(it = my_list.begin(); it != my_list.end(); it++){
		cout<< *it <<endl;
	
	}
//----------------------------------------------------------------------------------------------------------------





  
}
