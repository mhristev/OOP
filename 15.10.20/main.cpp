#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class Card{
	public:
	int num;
	string suit;
	
	Card(int num1, string suit1){
		this->num = num1;
		this->suit = suit1;
	}
};



int main(){
	stack <Card> cards;
	cards.push({2, "Spades"});
	cards.push({2, "Clubs"});
	cards.push({2, "Hearts"});
	cards.push({2, "Diamonds"});
	cards.push({2, "Diamondsss"});
	
	
	list <Card> player;
	//cout<<cards.size()<<endl;
	int p = cards.size();
	for(int i = 0; i < p; i++){
		player.push_back(cards.top());				
		cards.pop();
	}	
	
	
	list <Card>::iterator it;
 
 	for(it = player.begin(); it !=  player.end(); it++){
		cout<<(*it).num<<" ";
		cout<< (*it).suit <<endl;
	
	}
	
	
	
	
	return 0;
}



