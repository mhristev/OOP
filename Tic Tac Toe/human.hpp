#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"
#include "game.hpp"


class Human: public Player{

public:
    Human(Sign sym, std::string name): Player(sym, name){};

    virtual int make_turn();

};

#endif