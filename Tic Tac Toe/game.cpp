#include "game.hpp"

Game::Game(Player& player){
    srand(time(NULL));
    int who_is_first = rand()%(2 - 1 + 1) + 1;
    if(who_is_first == 1)
    {
        player_1 = &player;
        if(player.getsymbol() == "O")
        {
            AI* computer = new AI(X, "COMPUTER");
            player_2 = computer;
        }
        else
        {
            AI* computer = new AI(O, "COMPUTER");
            player_2 = computer;
        }
        
    }
    else
    {
        player_2 = &player;
        if(player.getsymbol() == "O")
        {
            AI* computer = new AI(X, "COMPUTER");
            player_1 = computer;
        }
        else
        {
            AI* computer = new AI(O, "COMPUTER");
            player_1 = computer;
        }
    }
}

Game::Game(Player& player1, Player& player2){
    srand(time(NULL));
    int who_is_first = rand()%(2 - 1 + 1) + 1;
    if(who_is_first == 1){
        player_1 = &player1;
        player_2 = &player2;
    }else{
        player_1 = &player2;
        player_2 = &player1;
    }
}

void Game::init_field(){
    int count = 1;
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            std::string ch = std::to_string(count);
            field[i][k] = ch;
            count++;
        }
    }
}

void Game::print_field(){
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "| ";
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            std::cout << field[i][k] << " | ";
        }
        std::cout << std::endl;
        std::cout << "+---+---+---+" << std::endl;
        if(i != 2)
        {
            std::cout << "| ";
        }
    }
}

bool Game::check_winner(){
    for(int i = 0; i < 3; i++)
    {
        if(field[i][0] == field[i][1])
        {
            if(field[i][0] == field[i][2])
            {
                system("clear");
                if(field[i][0] == player_1->getsymbol())
                {
                    std::cout << "The winner is " << player_1->getName() << std::endl;
                }else
                {
                    std::cout << "The winner is " << player_2->getName() << std::endl;
                }
                return true;
            }
        }

        for(int k = 0; k < 3; k++)
        {
            if(field[i][k] == field[i+1][k])
            {
                if(field[i][k] == field[i+2][k])
                {
                    system("clear");
                    if(field[i][k] == player_1->getsymbol())
                    {
                        std::cout << "The winner is " << player_1->getName() << std::endl;
                    }else
                    {
                        std::cout << "The winner is " << player_2->getName() << std::endl;
                    }
                    return true;
                }
            }
        }
        
                if(field[0][0] == field[1][1]){
                    if(field[0][0] == field[2][2])
                    {
                        system("clear");
                        if(field[0][0] == player_1->getsymbol())
                        {
                            std::cout << "The winner is " << player_1->getName() << std::endl;
                        }else
                        {
                            std::cout << "The winner is " << player_2->getName() << std::endl;
                        }
                        return true;
                    }
                }

                if(field[0][2] == field[1][1])
                {
                    if(field[0][2] == field[2][0])
                    {
                        system("clear");
                        if(field[0][2] == player_1->getsymbol())
                        {
                            std::cout << "The winner is " << player_1->getName() << std::endl;
                        }else
                        {
                            std::cout << "The winner is " << player_2->getName() << std::endl;
                        }
                        return true;
                    }
                }
    }
        
    return false;
}


void Game::start_game()
{
    system("clear");
    std::cout << "Starting the game" << std::endl << std::endl;
    init_field();
    print_field();

    bool found = false;
    int place;


    while(1)
    {
        //----------------PLAYER 1----------------------------------------
        std::cout << "Player " << player_1->getName() << " is playing now!" << std::endl;
        while(found == false)
        {
            place = player_1->make_turn();

            for(int i = 0; i < 3; i++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(field[i][k] == std::to_string(place))
                    {
                        field[i][k] = player_1->getsymbol();
                        found = true;
                    }
                }
            }
        }

        if(check_winner())
        {
            std::cout << "GAME OVER" << std::endl;
            print_field();
            return;
        }
        //----------------------------PLAYER 2----------------------------------------------
        found = false;
        system("clear");
        print_field();

        std::cout << "Player " << player_2->getName() << " is playing now!" << std::endl;

        while(found == false){
            place = player_2->make_turn();

            for(int i = 0; i < 3; i++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(field[i][k] == std::to_string(place))
                    {
                        field[i][k] = player_2->getsymbol();
                        found = true;
                    }
                }
            }
        }

        found = false;
        system("clear");
        print_field();

        if(check_winner())
        {
            std::cout << "GAME OVER" << std::endl;
            print_field();
            return;
        }


    }
}