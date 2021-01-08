#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Book{
	public:
		string name;
		int pages;
		float rating;
	public:
		Book(string name, int pages, float rating){
			this->name = name;
			this->pages = pages;
			this->rating = rating;
		}
};

class BookShelf{
		public:
		vector <Book> vbooks;
	public:
		void Push_el(Book b){
			this->vbooks.push_back(b);
		}
		
		void print(){
			vector <Book>::iterator b;
		
		 	for(b = vbooks.begin(); b !=  vbooks.end(); b++){
				cout << (*b).name << " ";
				cout << (*b).pages << " ";
				cout << (*b).rating << endl;
			
			}
		}
		
		void write_in_csv(){
			vector <Book>::iterator b;
			ofstream my_file;
			my_file.open("test.csv");
			my_file << "#Col 1" << "," << "#Col 2" << "," << "#Col 3" << "\n";  
		 	for(b = vbooks.begin(); b !=  vbooks.end(); b++){
				my_file << (*b).name << ", ";
				my_file << (*b).pages << ", ";
				my_file << (*b).rating << endl;
				
			
			}
			
			my_file.close();
		
		}
};




int main(){
	BookShelf my_bookshelf;
	Book b("az", 10, 4.1);
	Book b2("az2", 11, 5.1);
	Book b3("az3", 12, 0.1);
	my_bookshelf.Push_el(b);
	my_bookshelf.Push_el(b2);
	my_bookshelf.Push_el(b3);
	my_bookshelf.print();
	my_bookshelf.write_in_csv();
	
	
	
	

}





