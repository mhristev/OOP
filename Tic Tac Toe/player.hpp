#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

enum Sign
{
    O, X 
};

class Player{
    std::string name;
    Sign symbol;
public:
    Player(Sign sign, std::string name);

    std::string getsymbol();

    std::string getName();

    virtual int make_turn() = 0;

};

#endif