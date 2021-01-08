#include "game.hpp"



using namespace std;


int main(){

    Human p1 = Human(X, "space");
    Human p2 = Human(O, "stinky");
    Game new_game(p1, p2);
    new_game.start_game();

}