#include "human.hpp"




int Human::make_turn(){
    int place;
    std::cout << "Choose place to put '" << getsymbol() << "': " << std::endl;
    std::cin >> place;
    
    while(!std::cin)
    {
        std::cout << "Please type valid value" << std::endl;
        std::cin >> place;
    }

    return place;
}
