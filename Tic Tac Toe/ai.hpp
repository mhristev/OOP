#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"

class AI: public Player{

public:
    AI(Sign sym, std::string name): Player(sym, name){};
    virtual int make_turn();
};




#endif  