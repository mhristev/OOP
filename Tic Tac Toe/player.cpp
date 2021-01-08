#include "player.hpp"


Player::Player(Sign sign, std::string name){
    this->symbol = sign;
    this->name = name;
}

std::string Player::getsymbol(){
    if(symbol == 0)
        return "O";
    else
        return "X";        
}

std::string Player::getName(){
    return name;
}
